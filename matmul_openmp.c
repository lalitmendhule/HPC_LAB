
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void matmul(int N , double *A,double *B,double *C){
	for(int i = 0; i<N ;i++){
		for(int j= 0 ;j<N;j++){
			double sum=0;
			for(int K=0;K<N;K++)
				sum += A[i*N+K] * B[K*N+j];
			C[i*N+j] = sum;
		}
	}
}

int main(int argc , char **argv){
	if(argc < 2){
		printf("Usage : %s matrix_size\n", argv[0]);
		return 1;
	}
	int N = atoi(argv[1]);
	double *A = malloc(N*N*sizeof(double));
	double *B = malloc(N*N*sizeof(double));
	double *C = malloc(N*N*sizeof(double));

	for(int i=0;i<N*N;i++){
		A[i]=1.0;
		B[i]=2.0;
	}
	double start = omp_get_wtime();
	matmul(N,A,B,C);
	double end = omp_get_wtime();
	printf("OpenMp Matmul elapsed time: %f seconds\n",end-start);
	free(A);
	free(B);
	free(C);
	return 0;
}

