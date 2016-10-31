#include <stdio.h>
#include <string.h>

int N,map[100001][3],DT[2][3];

int max(int a, int b) { return (a>b)?a:b; }
int min(int a, int b) { return (a<b)?a:b; }

int f(int n, int k, int cost) {

	if(n==N) return DT[n][k]=max(DT[n][k],cost);

	int ret = DT[n][k];
	if(ret!=-1 && ret > cost ) return DT[n][k];
	ret = 0;
	if(k-1>=0) ret = max(ret, f(n+1, k-1, cost+map[n+1][k-1]));
	if(k+1<=2) ret = max(ret, f(n+1, k+1, cost+map[n+1][k+1]));
	ret = max(ret, f(n+1,k,cost+map[n+1][k]));

	return DT[n][k]=ret;
}

int f2(int n, int k, int cost) {
	if(n==N) return DT[n][k]=min(DT[n][k],cost);
	
	int ret = DT[n][k];
	if(ret!=-1 && ret < cost ) return DT[n][k];
	ret = 0x7fffffff;
	if(k-1>=0) ret = min(ret, f2(n+1, k-1, cost+map[n+1][k-1]));
	if(k+1<=2) ret = min(ret, f2(n+1, k+1, cost+map[n+1][k+1]));
	ret = min(ret, f2(n+1,k,cost+map[n+1][k+1]));

	return DT[n][k]=ret;
}

int f3() {

	DT[0][0]=map[1][0];
	DT[0][1]=map[1][1];
	DT[0][2]=map[1][2];
	for(int i=2; i<=N; i++) {
		for(int k=0; k<3; k++) {

			int ret = 0;
			if(k-1>=0) ret = max(ret, DT[0][k-1]+map[i][k]);
			if(k+1<=2) ret = max(ret, DT[0][k+1]+map[i][k]);
			ret = max(ret, DT[0][k]+map[i][k]);
			DT[1][k]=ret;
		}
		for(int k=0; k<3; k++) {
			DT[0][k]=DT[1][k];
		}
	}
	int ans = 0;
	for(int i=0; i<3; i++)
		ans = max(ans, DT[1][i]);
	return ans;
}

int f4() {

	DT[0][0]=map[1][0];
	DT[0][1]=map[1][1];
	DT[0][2]=map[1][2];
	for(int i=2; i<=N; i++) {
		for(int k=0; k<3; k++) {

			int ret = 0x7ffffff;
			if(k-1>=0) ret = min(ret, DT[0][k-1]+map[i][k]);
			if(k+1<=2) ret = min(ret, DT[0][k+1]+map[i][k]);
			ret = min(ret, DT[0][k]+map[i][k]);
			DT[1][k]=ret;
		}
		for(int k=0; k<3; k++) {
			DT[0][k]=DT[1][k];
		}
	}
	int ans = 0x7fffffff;
	for(int i=0; i<3; i++)
		ans = min(ans, DT[1][i]);
	return ans;
}

int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++)
		scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);

	memset(DT, -1, sizeof(DT));
	//int Max = f(0,1,0);
	int Max = 0;
	if(N==1) {
		Max = max(Max,map[1][0]);
		Max = max(Max,map[1][1]);
		Max = max(Max,map[1][2]);
	} else  {
		Max = f3();
	}

	memset(DT, -1, sizeof(DT));
	//DT[N][0] = 0x7fffffff;
	//DT[N][1] = 0x7fffffff;
	//DT[N][2] = 0x7fffffff;
	//int Min = f2(0,1,0);

	int Min = 10;
	if(N==1) {
		Min = min(Min,map[1][0]);
		Min = min(Min,map[1][1]);
		Min = min(Min,map[1][2]);
	} else  {
		Min = f4();
	}
	
	printf("%d %d", Max, Min);

	return 0;
}