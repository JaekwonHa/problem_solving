#include <stdio.h>

int N, DT[501][501], D[501], S[501], A[501];

int f(int n) {
	DT[0][0]=1;
	for(int a=0; a<n; a++) {
		for(int b=0; b<n; b++) {
			if(a!=b || (a==n-1)&&(b==n-1)) {
				if(a>=b) {
					for(int k=0; k<a; k++) {
						if(D[a]-D[k]<=S[k]) DT[a][b] += DT[k][b];
					}
				} else if(A[b]) {
					for(int k=0; k<b; k++) {
						if(D[b]-D[k]<=S[b]) DT[a][b] += DT[a][k];
					}
				}
			}
			DT[a][b]%=1000;
		}
	}
	return DT[n-1][n-1];
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d %d", &D[i], &S[i], &A[i]);

	printf("%d", f(N));

	return 0;
}