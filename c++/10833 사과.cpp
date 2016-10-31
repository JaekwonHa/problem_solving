#include <stdio.h>

int N,A[101],B[101];

int f(int n) {
	int sum=0;
	for(int i=0; i<n; i++) sum+=B[i]%A[i];
	return sum;
}

int main() {

	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d %d", &A[i], &B[i]);
	}
	printf("%d", f(N));

	return 0;
}