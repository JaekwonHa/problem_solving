#include <stdio.h>

int N,K,coin[101];
int re[10001], ca[10001];
int A[10001], B[10001];

//int table[10001][101];

void solve() {
	int i,j;
	re[0]=1;
	for(i=1; i<=N; i++) {
		for(j=1; j<=K; j++) {
			if(j<coin[i]) {
				re[j]=ca[j];
			} else {
				re[j]=ca[j]+re[j-coin[i]];
			}
		}
		for(j=0; j<=K; j++) {
			ca[j]=re[j];
		}
	}
}
/*
int count(int n, int k) {

	for(int i=1; i<=N; i++) {
		table[0][i]=1;
	}
	for(int i=1; i<=K; i++) {
		for(int j=1; j<=N; j++) {
			int x,y;

			x = (i-coin[j]>=0) ? table[i-coin[j]][j] : 0;
			y = table[i][j-1];
			table[i][j] = x+y;
		}
	}
	return table[k][n];
}
*/

int count2(int n, int k) {

	A[0]=1;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=K; j++) {
			if(j-coin[i]<0) {
				A[j]=B[j];
			} else {
				A[j]=A[j-coin[i]]+B[j];
			}
		}
		for(int j=0; j<=K; j++)
			B[j]=A[j];
	}
	return A[k];
}

int count3(int n, int k) {
	A[0]=1;
	for(int i=n; i>0; i--) {
		for(int j=coin[i]; j<=k; j++) {
			A[j] += A[j-coin[i]];
		}
	}

	return A[k];
}


int main() {

	scanf("%d %d", &N, &K);
	for(int i=1; i<=N; i++) {
		scanf("%d", &coin[i]);
	}

	printf("%d", count3(N,K));

	/*
	solve();

	printf("%d", re[K]);
	*/

	return 0;
}