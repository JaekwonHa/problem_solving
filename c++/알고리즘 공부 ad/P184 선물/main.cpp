#include <stdio.h>

int N,W[21],DT[21][101][101], DT2[2][101][101], mSum;
int ansA, ansB, ansC;

int max(int a, int b) {
	if(a>b) return a;
	return b;
}

void solve(int n) {
	DT[0][0][0]=1;
	int a,b,c;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=mSum; j++) {
			for(int k=0; k<=mSum; k++) {
				a = DT[i-1][j][k];
				b = ((mSum-j-k)>=j && j-W[i]>=0)? DT[i-1][j-W[i]][k]:0;
				c = (j>=k && k-W[i]>=0)? DT[i-1][j][k-W[i]]:0;
				DT[i][j][k] = a || b || c;
			}
		}
	}
	int d=0x7fffffff;
	a=0x7fffffff,b=0,c=0;
	for(int j=0; j<=mSum; j++) {
		for(int k=0; k<=mSum; k++) {
			if(DT[n][j][k] && (mSum-j-k)>=j && j>=k && (mSum-j-k)-k <= d && mSum-j-k < a) {
				d = (mSum-j-k)-k, a= (mSum-j-k), b=j,c=k;
			}
		}
	}
	ansA=a, ansB=b, ansC=c;
}

void solve2(int n) {
	DT2[0][0][0]=1;
	int a,b,c;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=mSum; j++) {
			for(int k=0; k<=mSum; k++) {
				a = DT2[i%2][j][k];
				b = ((mSum-j-k)>=j && j-W[i]>=0)? DT2[i%2][j-W[i]][k]:0;
				c = (j>=k && k-W[i]>=0)? DT2[i%2][j][k-W[i]]:0;
				DT2[i%2][j][k] = a || b || c;
			}
		}
	}
	int d=0x7fffffff;
	a=0x7fffffff,b=0,c=0;
	for(int j=0; j<=mSum; j++) {
		for(int k=0; k<=mSum; k++) {
			if(DT2[n%2][j][k] && (mSum-j-k)>=j && j>=k && (mSum-j-k)-k <= d && mSum-j-k < a) {
				d = (mSum-j-k)-k, a= (mSum-j-k), b=j,c=k;
			}
		}
	}
	ansA=a, ansB=b, ansC=c;
}

int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++)
		scanf("%d", &W[i]), mSum+=W[i];

	solve2(N);

	printf("%d %d %d", ansA, ansB, ansC);

	return 0;
}