#include <stdio.h>
#include <string.h>

int T,K,arr[501],DT[501][501];
int min(int a, int b) {return (a<b)?a:b;}

int f(int a, int b) {
	if(a==b) return 0;
	if(DT[a][b]==-1) {
		int sum=0;
		for(int i=a; i<=b; i++) sum+=arr[i];
		int ans = 0x7fffffff;
		for(int k=a; k<b; k++) {
			ans = min(ans, f(a,k)+f(k+1,b));
		}
		DT[a][b]=ans+sum;
	}
	return DT[a][b];
}

int main() {

	scanf("%d", &T);
	while(T--) {
		memset(DT,-1,sizeof(DT));
		scanf("%d", &K);
		for(int i=0; i<K; i++)
			scanf("%d", &arr[i]), DT[i][i]=arr[i];

		int sum=0;
		for(int i=0; i<K; i++) sum+=arr[i];
		printf("%d\n", f(0,K-1));

	}

	return 0;
}