#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define INF 9999999

int N,E,t1,t2,map[810][810];
int ans;

int f(int x, int y) {
	int value[1001];
	int f[1001];
	int index[1001]; // 경로 저장

	memset(index,0,sizeof(index));
	for(int i=1; i<=N; i++) {
		value[i]=INF;
		f[i]=0;
	}
	value[x]=0;
	for(int i=1; i<=N; i++) {
		int min=INF, p;
		for(int j=1; j<=N; j++) {
			if(f[j]==0 && value[j]<min) {
				p=j;
				min=value[j];
			}
		}
		f[p]=1;
		for(int j=1; j<=N; j++) {
			if(value[p]+map[p][j] < value[j]) {
				value[j] = value[p]+map[p][j];
				index[j]=p;
			}
		}
	}
	return value[y];
}

int main() {

	int a,b,c;
	scanf("%d %d", &N, &E);
	for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				map[i][j]=INF;

	for(int i=0; i<E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a][b]=c;
		map[b][a]=c;
	}
	scanf("%d %d", &t1, &t2);
	/*
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			for(int k=1; k<=N; k++) {
				if(map[i][j] > map[i][k]+map[k][j]) {
					map[i][j]=map[i][k]+map[k][j];
				}
			}
		}
	}
	*/

	//ans = min(map[1][t1]+map[t1][t2]+map[t2][N], map[1][t2]+map[t2][t1]+map[t1][N]);
	ans = min(f(1,t1)+f(t1,t2)+f(t2,N), f(1,t2)+f(t2,t1)+f(t1,N));
	if(ans==3*INF) printf("-1\n");
	else printf("%d\n", ans);

	return 0;
}