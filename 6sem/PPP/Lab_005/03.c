#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#ifdef _OPENMP

#include <omp.h>

#endif

#include <mpi.h>

#define M 100000
#define N 2000

#ifdef _OPENMP

int compress_num_th( char *buf, int *iter, int n, int thread );

#endif

int multMatrVect( double *a, double *v, double *rez, int n );


int myrank, nprocs;

int main( int argc, char** argv){

	int len;
	char name[MPI_MAX_PROCESSOR_NAME];
	double *a, *v, *r;
	int i, n_mpi, n_my;
	double time, *a1, *v1, *r1;


	MPI_Init(&argc, &argv);

	MPI_Comm_size( MPI_COMM_WORLD, &nprocs);
	MPI_Comm_rank( MPI_COMM_WORLD, &myrank);
	MPI_Get_processor_name( name, &len );

	printf("Hello from host %s[%d] %d of %d\n", name, len, myrank, nprocs);

	n_mpi = N / nprocs;
	if( N % nprocs )
		n_mpi++;

	if( myrank == 0 ){
		double *base;
		MPI_Request *rq1 = (MPI_Request*) malloc( 2*(nprocs-1) * sizeof(MPI_Request) );
		MPI_Status *st = (MPI_Status*) malloc( 2*(nprocs-1) * sizeof(MPI_Status) );
		MPI_Request *rq = rq1;

		if( NULL == ( a = (double*) malloc( N*M*sizeof(double) )) ){
			printf( "Malloc A[%d] data\n", myrank );
			return 10;
		}
		v = (double*) malloc( M*sizeof(double) );
		r = (double*) malloc( N*sizeof(double) );

		printf( "Arr A[%d] data\n", myrank );
		fflush( stdout );

		for( i=0; i<N*M; i++ ){
			a[i] = rand() %1001 - 500;
			// a[i] = i / M +1; //rand() %1001 - 500;
			if( i % 1000 == 999 )
				printf( "*" );
		}
		printf( "\n" );

		printf( "Arr V[%d] data\n", myrank );
		fflush( stdout );

		for( i=0; i<M; i++ )
			v[i] = rand() %1001 - 500;
			// v[i] = i+1;//rand() %1001 - 500;
		
		n_my = N - n_mpi*(nprocs-1);

		printf( "\nA[  1]=[" );
		for( i=0; i<10; i++ )
			printf( "%14.5lf  ", a[i] );
		printf( "]\nA[500]=[" );
		for( i=0; i<10; i++ )
			printf( "%14.5lf  ", a[i+M*500] );
		printf( "]\nV[ * ]=[" );
		for( i=0; i<10; i++ )
			printf( "%14.5lf  ", v[i] );
		printf( "]\n******************\n" );


		printf( "Fill[%d] data n_mpi=%d  n_my=%d\n", myrank, n_mpi, n_my );
		fflush( stdout );

  		time = MPI_Wtime();
		MPI_Barrier( MPI_COMM_WORLD );

		base = a;
		for( i=1; i<nprocs; i++ ){
			MPI_Isend( base, M*n_mpi, MPI_DOUBLE,
					i, 10, MPI_COMM_WORLD, rq++ );
			base += M*n_mpi;
		}
		a1 = base;

	//	base = v;
		for( i=1; i<nprocs; i++ ){
			MPI_Isend( v, M, MPI_DOUBLE,
					i, 20, MPI_COMM_WORLD, rq++ );
		//	base += n_mpi;
		}
		v1 = v; //base;

		r1 = r + (nprocs-1)*n_mpi;

		printf( "Send[%d] data n_mpi=%d  n_my=%d\n", myrank, n_mpi, n_my );
		MPI_Waitall( 2*(nprocs-1), rq1, st );
		free(rq1);
		free(st);

	}
	else{
		n_my = n_mpi;
		MPI_Status st1,st2;
		a1 = (double*) malloc( M*n_mpi*sizeof(double) );
		v1 = (double*) malloc( M*sizeof(double) );

		printf( "Get[%d] data n_mpi=%d  n_my=%d\n", myrank, n_mpi, n_my );

		MPI_Barrier( MPI_COMM_WORLD );
		MPI_Recv( a1, M*n_mpi, MPI_DOUBLE,
			       0, 10, MPI_COMM_WORLD, &st1 );	
		MPI_Recv( v1, M, MPI_DOUBLE,
			       0, 20, MPI_COMM_WORLD, &st2 );	

		printf( "Got[%d] data n_mpi=%d  n_my=%d\n", myrank, n_mpi, n_my );

		r1 = (double*) malloc( n_mpi*sizeof(double) );

	}

	printf( "Mult [%d] start\n", myrank );
	fflush( stdout );

	multMatrVect( a1, v1, r1, n_my );

	printf( "Mult [%d] finish\n", myrank );
	fflush( stdout );

	if( myrank == 0 ){

		double *base;
		MPI_Request *rq1 = (MPI_Request*) malloc( (nprocs-1) * sizeof(MPI_Request) );
		MPI_Status *st = (MPI_Status*) malloc( (nprocs-1) * sizeof(MPI_Status) );
		MPI_Request *rq = rq1;

		base = r;
		for( i=1; i<nprocs; i++ ){
			MPI_Irecv( base, n_mpi, MPI_DOUBLE,
					i, 30, MPI_COMM_WORLD, rq++ );
			base += n_mpi;
		}

		if( base != r1 ){
			printf( " base=%16lx  <> r1=%16lx\n", (unsigned long int) base, (unsigned long int) r1 );
		}


		MPI_Waitall( (nprocs-1), rq1, st );
		free(rq1);
		free(st);

  		time = MPI_Wtime()-time;

	}
	else{
		MPI_Send( r1, n_mpi, MPI_DOUBLE, 0, 30, MPI_COMM_WORLD );

		free(r1);
		free(a1);
		free(v1);
	}
	MPI_Finalize();

	if( myrank == 0 ){
		r1 = (double*) malloc( N*sizeof(double) );
		int j;
		double tmp,time1;

		printf( "\nra=[" );
		for( i=0; i<10; i++ )
			printf( "%14.5lf  ", a[i] );
		printf( "]\nrv=[" );
		for( i=0; i<10; i++ )
			printf( "%14.5lf  ", v[i] );
		printf( "]\n" );

  		time1 = MPI_Wtime();
		int error = 0;
		for( i=0; i<N; i++ ){
			tmp = 0.0;

			for( j=0; j<M; j++ )
				tmp += a[i*M+j] * v[j];
			r1[i] = tmp;

			if( fabs( tmp-r[i] ) > 0.0 ){
				printf( " tmp=%14.5lf  <> r[%3d]=%14.5lf -- %14.5lf\n", tmp, i, r[i], fabs(tmp-r[i]) );
				error++;
			}	

		}
		printf( "ERROR = %d\n", error );
  		time1 = MPI_Wtime()-time1;

		free(a);
		free(v);
		free(r);
		free(r1);

		printf( "time Par = %18.14lf sek\n", time );
		printf( "time Seq = %18.14lf sek\n", time1 );
		printf( "Effectiv = %18.14lf \x0a\n", time1/time/nprocs*100 );

	}

	return 0;

}


int compress_num_th( char *buf, int *iter, int n, int thread ){
	int i=0;
	buf[0] = 0;
/*
	for( i=0; i<20; i++ )
		if(
	for( i=0; i<20; i++ ){
		char bufs[80];

		sprintf( bufs, "%d,", iter[i] );
		strcat( buf, bufs );

	}
*/

	for(;;){
		int it_beg,it_end;
		char bufs[80];

		for( ; i<n && iter[i]==-1; i++ );
		it_beg=i++;

		if( it_beg>=n )
			break;

        if( iter[i] == -1 ){
            it_end=it_beg;
        }
        else{
            if( iter[it_beg] != thread ){
                int it_error =iter[it_beg];
                for( ; i<n && iter[i]==it_error; i++ );

                continue;
            }
            for( ; i<n && iter[i]==thread; i++);
            it_end=i-1;
        }


		if( it_beg == it_end ){
			sprintf( bufs, "%d,", it_beg );
		}else
		if( it_beg == it_end-1 ){
			sprintf( bufs, "%d,%d,", it_beg, it_end );
		}else{
			sprintf( bufs, "%d-%d,", it_beg, it_end );
		}

		strcat( buf, bufs );

	}
	i = strlen(buf);
	if( i>0 )
		buf[i-1] = 0;

	return 0;
}


int multMatrVect( double *a, double *v, double *rez, int n ){
	int i,j;
	double tmp;

	printf( "Mult [%d] work\n", myrank );
	fflush( stdout );

/*	if( myrank==3 ){
		printf( "\na[%d]=[", myrank );
		for( i=0; i<10; i++ )
			printf( "%14.5lf  ", a[i] );
		printf( "]\nv[%d]=[", myrank );
		for( i=0; i<10; i++ )
			printf( "%14.5lf  ", v[i] );
		printf( "]\n" );
//	}  */

#pragma omp parallel default(none) private(i,j,tmp) shared(n,a,v,rez,myrank)
	{

#ifdef _OPENMP

		int num_th = omp_get_thread_num();
		int *it_num = (int*) malloc( n * sizeof(int) );
		char buf[120];
		for( i=0; i<n; i++ )
			it_num[i] = -1;
#endif


#pragma omp for 
		for( i=0; i<n; i++ ){
			tmp = 0.0;

			for( j=0; j<M; j++ )
				tmp += a[i*M+j] * v[j];

			rez[i] = tmp;

#ifdef _OPENMP
			it_num[i] = num_th;
#endif

		}

#ifdef _OPENMP
		compress_num_th( buf, it_num, n, num_th );
		printf( "[%2d]thread=%i   iter[%s]\n", myrank, omp_get_thread_num(), buf );
#endif
		
	}
/*
	for( i=0; i<3; i++ ){
		printf( "[%2d] r[%3d] = %14.5lf\n", myrank, i, rez[i] );
	}

	printf( "Mult [%d] done work\n", myrank );
	fflush( stdout );
*/

	return 0;
}


