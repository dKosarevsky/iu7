#include <mpi.h>
#include <stdio.h>
int main (int argc, char **argv)
{
	int size, ind;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);//размер коменикатора количество соседий
	MPI_Comm_rank(MPI_COMM_WORLD, &ind);
 	
	printf("I'm %d of %d!!\n", ind, size);//я под номером, всего нас

	if( ind % 2 == 1 ){
	    int a[10][10];
	    int i, j;
	    MPI_Datatype col, col1;
	    int               block_size[2];
	    MPI_Datatype      block_type[2];
	    MPI_Aint          block_adr[2];

	    for( i=0; i<10; i++ )
		for( j=0; j<10; j++ )
		    a[i][j] = i*100+j+1;

	    for( i=0; i<10; i++ ){
		printf( "%02d: ", ind );
		for( j=0; j<10; j++ )
		    printf( "%4d ", a[i][j] );
		printf( "\n" );
	    }
	    MPI_Type_vector( 10, 1, 10, MPI_INT, &col );
	    block_size[0] = 1;
	    block_size[1] = 1;
	    block_type[1] = col;
	    block_type[0] = MPI_UB;
	    block_adr[1]  = 0;
	    block_adr[0]  = sizeof(int);
	    MPI_Type_struct( 2, block_size, block_adr, block_type, &col1 );

	    MPI_Type_commit( &col1 );

	    MPI_Send( a, 10, col1, ind-1, 100, MPI_COMM_WORLD ); 

	    MPI_Type_free( &col1 );
	    MPI_Type_free( &col );
	    
	} else
	if( ind+1 == size ){
	    printf( "Proc %d withought job!!!\n", ind );
	}
	else{
	    int b[10][10];
	    int i, j;
	    MPI_Status s;
	    MPI_Recv( b, 10*10, MPI_INT, ind+1, 100, MPI_COMM_WORLD, &s );

	    printf( "Transpose a matrix in %d\n", ind );

	    for( i=0; i<10; i++ ){
		printf( "%02d: ", ind );
		for( j=0; j<10; j++ )
		    printf( "%4d ", b[i][j] );
		printf( "\n" );
	    }


	}

	MPI_Finalize();
	
	return 0;
}
