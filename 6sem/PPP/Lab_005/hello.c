#include <stdio.h>

#ifdef _OPENMP 

#include <omp.h>

#endif

int main(){
    int size=1, rank=0;

#pragma omp parallel default(none) private(size,rank)
    {
	int i;

#ifdef _OPENMP 
	rank = omp_get_thread_num();
	size = omp_get_num_threads();
#endif
	printf(" I`am %d from %d!!\n", rank, size);

#pragma omp for
	for( i=0; i<100; i++ )
	    printf( "%4d", i );
	printf(" Rank is %d\n", rank);

    }
    return 0;
}
