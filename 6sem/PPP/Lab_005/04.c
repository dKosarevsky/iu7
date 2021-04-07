#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#ifdef _OPENMP

#include <omp.h>

#endif

#define M 100000
#define N 2000

#ifdef _OPENMP

int compress_num_th( char *buf, int *iter, int n, int thread );

#endif

int main( int argc, char** argv){

	int len;
	char name[MPI_MAX_PROCESSOR_NAME];
	double *a, *v, *r;
	int i, n_mpi, n_my;
	double time, *a1, *v1, *r1;

	a = (double*) malloc( M*N*sizeof(double) );
	v = (double*) malloc( M*sizeof(double) );
	r = (double*) malloc( N*sizeof(double) );


	for( i=0; i<N*M; i++ ){
		a[i] = rand() %1001 - 500;
			// a[i] = i / M +1; //rand() %1001 - 500;
		if( i % 1000 == 999 )
			printf( "*" );
	}
	printf( "\n" );

	printf( "Arr V[%d] data\n", myrank );

	for( i=0; i<M; i++ )
		v[i] = rand() %1001 - 500;
			// v[i] = i+1;//rand() %1001 - 500;
		

  	time = MPI_Wtime();
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

