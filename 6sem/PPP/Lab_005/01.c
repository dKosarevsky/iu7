#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <mpi.h>

#define N 1000000


int main( int argc, char** argv){

	int myrank, nprocs, len;
	char name[MPI_MAX_PROCESSOR_NAME];


	MPI_Init(&argc, &argv);

	MPI_Comm_size( MPI_COMM_WORLD, &nprocs);
	MPI_Comm_rank( MPI_COMM_WORLD, &myrank);
	MPI_Get_processor_name( name, &len );

	printf("Hello from host %s[%d] %d of %d\n", name, len, myrank, nprocs);


	int *a = (int*) malloc( N*sizeof(int) );
	int i;
	double sum;
	double time;

	for( i=0; i<N; i++ )
		a[i] = rand() %1001;


	sum = 0;

	time = omp_get_wtime();
	for( i=0; i<N; i++ )
		sum += a[i];

	time = omp_get_wtime()-time;

	printf( "sum=%12.2lf\n", sum );
	printf( "time=%14.10lf\n", time );


	sum = 0;

	time = omp_get_wtime();
#pragma omp parallel default(none) private(i) shared(a,sum) num_threads(4)
	{

	double sum_loc = 0;	
#pragma omp for 
	for( i=0; i<N; i++ )
		sum_loc += a[i];


	printf( "thread=%i   sum=%12.2lf\n", omp_get_thread_num(), sum_loc );

#pragma omp atomic
	sum += sum_loc;

	}
	time = omp_get_wtime()-time;

	printf( "sum=%12.2lf\n", sum );
	printf( "time=%14.10lf\n", time );



	sum = 0;

	time = omp_get_wtime();
	time = omp_get_wtime();
#pragma omp parallel default(none) private(i) shared(a) num_threads(4) reduction(+:sum)
	{

#pragma omp for 
	for( i=0; i<N; i++ )
		sum += a[i];


	printf( "thread=%i   sum=%12.2lf\n", omp_get_thread_num(), sum );

	}
	time = omp_get_wtime()-time;

	printf( "sum=%12.2lf\n", sum );
	printf( "time=%14.10lf\n", time );

	MPI_Finalize();

	return 0;
}


