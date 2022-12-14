#include<stdio.h>
#include<string.h>
#include<mpi.h>

const int MSG_SIZE = 100;

int main () {
	char op_msg[MSG_SIZE];
	char in_msg[MSG_SIZE];

	int comm_sz;
	int page_rank;
	MPI_Status stat; 

	MPI_Init (NULL, NULL); 
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &page_rank); 

	for (int i=0; i<comm_sz; i++) {
		if (i != page_rank) {
			MPI_Recv(&in_msg, MSG_SIZE, MPI_CHAR, i, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
			printf ("Recieving the follwoing message from %d of %d: %s \n", page_rank, comm_sz, in_msg);
			
		} else {
		sprintf(op_msg, "Message sent from %d of %d.... \n", page_rank, comm_sz); 
		MPI_Send(&op_msg, strlen(op_msg), MPI_CHAR, i, i, MPI_COMM_WORLD); 
		
		}
	}
	MPI_Finalize (); 
	return 0; 
}

