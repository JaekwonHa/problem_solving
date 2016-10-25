#include <stdio.h>

int main() {
	int A[2][2] = {4,7,3,5};
	int B[2][2] = {9, -2, 6, 8};
	int C[2][2] = {0,0,0,0};
	int D = 0;

	printf("A행렬 입력\n");
	printf("1,1의 값을 입력하시오.\n");
	scanf("%d", &A[0][0]);
	printf("1,2의 값을 입력하시오.\n");
	scanf("%d", &A[0][1]);
	printf("2,1의 값을 입력하시오.\n");
	scanf("%d", &A[1][0]);
	printf("2,2의 값을 입력하시오.\n");
	scanf("%d", &A[1][1]);

	printf("B행렬 입력\n");
	printf("1,1의 값을 입력하시오.\n");
	scanf("%d", &B[0][0]);
	printf("1,2의 값을 입력하시오.\n");
	scanf("%d", &B[0][1]);
	printf("2,1의 값을 입력하시오.\n");
	scanf("%d", &B[1][0]);
	printf("2,2의 값을 입력하시오.\n");
	scanf("%d", &B[1][1]);


	printf("A+B=\n");
	for(int x=0; x<2; x++) {
		for(int y=0; y<2; y++) {
			C[x][y]=A[x][y]+B[x][y];
			printf("%d ", C[x][y]);
		}
		printf(";\n");
	}

	printf("A-B=\n");
     for(int x=0; x<2; x++) {
		 for(int y=0; y<2; y++) {
			 C[x][y]=A[x][y]-B[x][y];
			 printf("%d ",C[x][y]);
		 }
		 printf(";\n");
	 }
	 
	 printf("2A=\n");
	for(int x=0; x<2; x++){
		for(int y=0; y<2; y++){
			C[x][y] = 2*A[x][y];
			printf("%d ",C[x][y]);
		}
		printf(";\n");
	}
	
	printf("A*B=\n");

	for(int x=0; x<2; x++) {
		for(int y=0; y<2; y++) {
			C[x][y]=A[x][0]*B[0][y] + A[x][1]*B[1][y];
			printf("%d ", C[x][y]);
		}
		printf(";\n");
	}


	printf( "행렬식D(A)=\n");
	D = A[0][0]*A[1][1] - A[0][1]*A[1][0];
     printf("%d\n ", D);	
	printf( "행렬식D(B)=\n");
	 D = B[0][0]*B[1][1] - B[0][1]*B[1][0];	
	 printf("%d ", D);
	 return 0;
}

