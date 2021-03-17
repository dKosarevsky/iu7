#include <stdio.h>
#include <mpi.h>

int main(int argc, char ** argv)
{
	int myrank, nprocs, len;
	char name[MPI_MAX_PROCESSOR_NAME];


	MPI_Init(&argc, &argv);

	MPI_Comm_size( MPI_COMM_WORLD, &nprocs);
	MPI_Comm_rank( MPI_COMM_WORLD, &myrank);
	MPI_Get_processor_name( name, &len );

	printf("Hello from host %s[%d] %d of %d\n", name, len, myrank, nprocs);

	MPI_Finalize();
	return 0;

}

