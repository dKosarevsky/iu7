#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000000


int main( int argc, char **argv ){
	int size, ind;

	MPI_Init( &argc, &argv );
	MPI_Comm_size( MPI_COMM_WORLD, &size );
	MPI_Comm_rank( MPI_COMM_WORLD, &ind );
	printf( "I am %d of %d!!\n", ind, size );


	int nb_left, nb_right;
	int *a, *b,i,r;
	MPI_Status st1;
	MPI_Request rq1;
	double t1,t2;

	nb_left = (ind)? (ind - 1) : (size-1);
	nb_right = (ind<size-1)? (ind + 1 ) : ( 0 );   

	a = (int*) malloc( N*sizeof(int) );
	b = (int*) malloc( N*sizeof(int) );
	for( i=0; i<N; i++)
	    a[i] = i*10+10;

	t1 = MPI_Wtime();

	MPI_Irecv( b, N, MPI_INT, 
			nb_left, 100, MPI_COMM_WORLD, &rq1 );


	MPI_Ssend( a, N, MPI_INT, 
			nb_right, 100, MPI_COMM_WORLD );
	
	MPI_Wait( &rq1, &st1 );

	t2 = MPI_Wtime();
	printf( "Time[%d]=%lf sek\n", ind, t2-t1 );
	printf( "Bandwidth[%d] = %lf MByte/sek \n",
			ind,
			N*sizeof(int)/(t2-t1)/(1024*1024) ); 
	r = 0;
	for( i=0; i<N; i++)
	   if( a[i] != b[i] ){
		    r++;
		    printf( "%d != %d  [%d]\n", a[i], b[i], ind );
	   }
	printf( "Worker %d, error=%d!!\n", ind, r );
	 

	MPI_Finalize();

	return 0;
}


