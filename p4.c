#include<stdio.h>
#include<mpi.h> 
#include<stdlib.h> 


int main () {
	int x[100]; 
	int y[100]; 

	int page_rank, comm_sz; 


	for (int i=0; i<100; i++) {
		x[i] = rand()%10; 
		y[i] = rand()%10; 

		printf ("%dth vector (x, y)=>(%d, %d)\n", i, x[i], y[i]); 
	}

	MPI_Init (NULL, NULL); 
	MPI_Comm_size (MPI_COMM_WORLD, &comm_sz); 
	MPI_Comm_rank (MPI_COMM_WORLD, &page_rank); 
	int subsize = 100/comm_sz;

	int *x_small = malloc(sizeof(int)*subsize);
	int *y_small = malloc(sizeof(int)*subsize);

	MPI_Scatter(x, subsize, MPI_INT, x_small, subsize, MPI_INT, 	
