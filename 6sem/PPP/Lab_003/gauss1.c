#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

void printM( double **a, int n ){
        int i, j;
	
	for( i=0; i< n; i++ ){
	   for( j=0; j<=n; j++ )
	     printf( " %14.5lf", a[i][j] );
	   printf("\n");     
	}
	printf("\n");     
}

int rank, size;

void forwardSubstitution(double **a, int n) {
        int i, j, k, max;
        double t;
	double *pt;
	
	
        for (i = 0; i < n; i++) {
		
/*
                max = i;
		
                for (j = i + 1; j < n; j++)
                        if ( fabs(a[j][i]) > fabs(a[max][i]) )
                                max = j;
				
		pt = a[max];
		a[max] = a[i];
		a[i] = pt;	
*/	

		for( k = i+1; k<n ; k++ ){
		  t = a[k][i]/a[i][i];
		  for( j = i; j<=n; j++ )
		    a[k][j] -= a[i][j]*t; 
		}

        }
}

void reverseElimination(double **a, int n) {
        int i, j;
        for (i = n - 1; i >= 0; i--) {
                a[i][n] = a[i][n] / a[i][i];
                a[i][i] = 1.0;
                for (j = i - 1; j >= 0; j--) {

                        a[j][n] -= a[j][i] * a[i][n];
                        a[j][i] = 0;
                }
        }
}

void testM( double **a, double **b, int n ){
        int i, j,imax;
	double sum,deltamax;
        printf("\n");     

	imax = -1;
	deltamax = 0.0;
	for( i=0; i< n; i++ ){
	   sum = 0.0;
	   for( j=0; j<n; j++ )
	     sum += b[i][j]*a[j][n];
//	   printf( "%5d %14f=%14f [%14f]\n", i, b[i][n], sum, b[i][n]-sum  );
//	   printf( "%14.10f %14.10f \n", fabs( b[i][n]-sum ), fabs( deltamax )  );
	   if( fabs( deltamax ) < fabs( b[i][n]-sum )   ){
	      printf( "%5d %14.10f=%14.10f [%14f.10]\n", i, b[i][n], sum, b[i][n]-sum  );
	      deltamax = b[i][n]-sum;
	   }
	}
	
}	

void gauss(double **a, int n) {

        forwardSubstitution(a,n);
	printM( a, n );
        reverseElimination(a,n);
}

int main(int argc, char *argv[]) {
        int i, j, k;

	int n=9;
	double **a, **b;
	double time;

	if( argc>1 ){
	   sscanf( argv[1], "%d", &n );
	}


	 MPI_Init (&argc, &argv);      /* starts MPI */
	 MPI_Comm_rank (MPI_COMM_WORLD, &rank);        /* get current process id */
	 MPI_Comm_size (MPI_COMM_WORLD, &size);        /* get number of processes */
	 printf( "Gauss for system[%d]\n", n );

        if( !rank ){
 	    double **ra;
	  
	
	    a = (double**) malloc(n*sizeof(double*));
	    b = (double**) malloc(n*sizeof(double*));


	    for (i = 0; i < n; i++) {
		a[i] = (double*) malloc((n+1)*sizeof(double));
		b[i] = (double*) malloc((n+1)*sizeof(double));
                for (j = 0; j < n+1; j++){
        		a[i][j] = rand()%1000;
			b[i][j] = a[i][j];
	    } }
	    

	  printM( a, n );

 	  time = MPI_Wtime();
          gauss(a, n);
	  time = MPI_Wtime()-time;


           printf("Time[%d]: %lf\n", rank,time) ;
	   printM( a, n );
           testM( a, b, n );
	
	
	} else {
	    printf( "myrank = %d\n", rank );

	}
	
	
	MPI_Finalize();
        return 0;
}
