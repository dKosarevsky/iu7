#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>
int main (int argc, char **argv)
{
	int size, ind;
	int a[10];
	int i;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);//размер коменикатора количество соседий
	MPI_Comm_rank(MPI_COMM_WORLD, &ind);
 	
	printf("I'm %d of %d!!\n", ind, size);//я под номером, всего нас

	if( ind == 0 ){
	    int *b = (int*)  malloc( 10 * sizeof(int) * size );
	    int i;
	    for( i = 0; i<size*10; i++ )
		b[i] = i+1;
	    MPI_Scatter( b, 10, MPI_INT, a, 10, MPI_INT, 0, MPI_COMM_WORLD );

	    free( b );
	}
	else{
	    MPI_Scatter( NULL, 0, MPI_INT, a, 10, MPI_INT, 0, MPI_COMM_WORLD );
	}


	printf( "proc=%2d  a={ ", ind );
	for( i=0; i<10; i++ )
	    printf( "%4d", a[i] );
	printf( " }\n" );

	if( ind != 0 ){
	    MPI_Reduce( a, NULL, 10, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD );
	}
	else{
	    int b[10];
	    MPI_Reduce( a, b, 10, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD );

	    printf( "proc=%2d Reduce b={ ", ind );
	    for( i=0; i<10; i++ )
		printf( "%6d", b[i] );
	    printf( " }\n" );
	}


	MPI_Finalize();
	
	return 0;
}
