#include <stdio.h>

int n, A[100];

int main() {

	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &A[i]);

	int thisSum=0, maxSum=0;
	for(int i=0; i<n; i++) {
		thisSum += A[i];
		if(thisSum > maxSum)
			maxSum = thisSum;
		if(thisSum < 0)
			thisSum=0;
	}

	printf("%d", maxSum);

	return 0;
}