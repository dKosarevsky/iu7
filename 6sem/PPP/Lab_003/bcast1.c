#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>


#define SIZE 1024


int main(int argc, char ** argv){

	int myrank, nprocs, len;
	char name[MPI_MAX_PROCESSOR_NAME];
	int *buf, *a,*b;
	MPI_Status st;

	a = (int*) malloc( sizeof(int) * 1024 );

	buf = (int*) malloc( sizeof(int)*(SIZE*1024 + 100) );
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Get_processor_name( name, &len );

	buf = (int*) malloc( sizeof(int)*(nprocs*1024) );

	printf("Hello from processor %s[%d] %d of %d  \n", name, len, myrank, nprocs);

	if ( myrank ==  0  ){

	    int i, cl;
	    for( i=0; i<1024*nprocs; i++ )
		    buf[i] = i+10;

	    for( i= 1; i<nprocs; i++ )
		      MPI_Send( buf, 1024, MPI_INT, i, 
				10, MPI_COMM_WORLD );
		

	    b = buf;
	}
	else {
	    int* buf = (int*) malloc( sizeof(int)*(SIZE*1024 + 100) );
	    int i;

	    b = NULL;

	    MPI_Recv( buf, 1024, MPI_INT, 0,
		      10, MPI_COMM_WORLD, &st );

	    printf( "myrank = %2d    ", myrank );
	    for( i=0; i<10; i++ )
		printf( "%5d", buf[i] );
	    printf( "\n" );

	    free( buf );
	}

	MPI_Bcast( buf, 1024, MPI_INT, 0, MPI_COMM_WORLD );
	if( myrank != 0 ){
	    int i;
	    printf( "myrank = %2d    ", myrank );

	    for( i=0; i<10; i++ )
		printf( "%5d", buf[i] );
	    printf( "\n" );

	}

	MPI_Scatter( b, 1024, MPI_INT, a, 1024, MPI_INT, 0, MPI_COMM_WORLD );
	{
	    int i;
	    printf( "myrank = %2d    ", myrank );

	    for( i=0; i<10; i++ )
		printf( "%5d", a[i] );
	    printf( "\n" );

	}
	MPI_Finalize();
	return 0;
}

