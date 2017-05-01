#include <stdio.h>
#include <string.h>

int T,N,arr[1001],DT[1001][1001],sum[1001];
int min(int a, int b) {return (a<b)?a:b;}

int f(int a, int b) {
	if(a==b) return arr[a];
	if(a>b) return 0;

	int ret=DT[a][b];
	if(ret==-1) {
		ret = sum[b]-sum[a-1];
		ret = ret - min(f(a+1,b),f(a,b-1));
		DT[a][b]=ret;
	}
	return DT[a][b];
}

int main() {

	scanf("%d", &T);
	while(T--) {
		memset(DT,-1,sizeof(DT));
		scanf("%d", &N);
		for(int i=1; i<=N; i++)
			scanf("%d", &arr[i]), sum[i]=sum[i-1]+arr[i];

		printf("%d\n", f(1,N));
	}


	return 0;
}