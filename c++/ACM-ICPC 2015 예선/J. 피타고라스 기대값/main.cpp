#include <stdio.h>
#include <string.h>

int T,n,m,S[1001],A[1001],a,b,p,q;
double W[1001];
double min(double a, double b) {return (a<b)?a:b;}
double max(double a, double b) {return (a>b)?a:b;}

int main() {
	scanf("%d", &T);
	while(T--) {
		memset(S, 0, sizeof(S));
		memset(A, 0, sizeof(A));
		scanf("%d %d", &n, &m);
		for(int i=1; i<=m; i++) {
			scanf("%d %d %d %d", &a, &b, &p, &q);
			S[a] +=p, A[a] +=q, S[b] +=q, A[b]+=p;
		}
		double Min=2e9,Max=0;
		for(int i=1; i<=n; i++) {
			if(S[i]==0 && A[i]==0) W[i]=0;
			else W[i]=((double)S[i]*S[i]/(S[i]*S[i]+A[i]*A[i]));
			Min = min(Min,W[i]*1000);
			Max = max(Max,W[i]*1000);
		}
		printf("%d\n%d\n", (int)(Max+1e-8), (int)(Min+1e-8));
	}


	return 0;
}