#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10


int main( int argc, char **argv ){
	int size, ind;

	MPI_Init( &argc, &argv );
	MPI_Comm_size( MPI_COMM_WORLD, &size );
	MPI_Comm_rank( MPI_COMM_WORLD, &ind );
	printf( "I am %d of %d!!\n", ind, size );

	if( ind % 2 == 1 ){
	    int *a, *b,i,r;
	    MPI_Status st1;
	    double t1,t2;

	    a = (int*) malloc( N*sizeof(int) );
	    b = (int*) malloc( N*sizeof(int) );

	    for( i=0; i<N; i++)
		a[i] = i*10+10;

	    t1 = MPI_Wtime();
	    for( i=0; i<100; i++){
		MPI_Send( a, N, MPI_INT, 
			  ind-1, 100, MPI_COMM_WORLD );
		MPI_Recv( b, N, MPI_INT, 
			  ind-1, 101, MPI_COMM_WORLD, &st1 );
	    }
	    t2 = MPI_Wtime();
	    printf( "Time[%d]=%lf sek\n", ind, t2-t1 );
	    printf( "Bandwidth[%d] = %lf MByte/sek \n",
			ind,
			N*100*sizeof(int)*2/(t2-t1)/(1024*1024) ); 
	    r = 0;
	    for( i=0; i<N; i++)
		if( a[i] != b[i] ){
		    r++;
		    printf( "%d != %d  [%d]\n", a[i], b[i], ind );
		}
	    printf( "Worker %d, error=%d!!\n", ind, r );
	} 
	else 
	if( ind+1 < size ){

	    int *c,i;
	    MPI_Status st1;

	    c = (int*) malloc( N*sizeof(int) );

	    for( i=0; i<100; i++){
		MPI_Recv( c, N, MPI_INT, 
			  ind+1, 100, MPI_COMM_WORLD, &st1 );
		MPI_Send( c, N, MPI_INT, 
			  ind+1, 101, MPI_COMM_WORLD );
	    }

	} else
  	    printf( "Withioght opponent %d \n", ind );


	MPI_Finalize();

	return 0;
}


