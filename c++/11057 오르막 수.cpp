#include <stdio.h>
#define p 10007

int N, DT[1001][10];

int f(int n) {
	for(int i=0; i<10; i++)
		DT[1][i]=1;
	for(int i=2; i<=n; i++) {
		for(int j=0; j<10; j++) {
			for(int k=0; k<=j; k++) {
				DT[i][j] = (DT[i][j]+DT[i-1][k])%p;
			}
		}
	}
	int sum=0;
	for(int i=0; i<10; i++)
		sum = (sum+DT[n][i])%p;
	return sum;
}

int main() {

	scanf("%d", &N);

	printf("%d", f(N));	

	return 0;
}