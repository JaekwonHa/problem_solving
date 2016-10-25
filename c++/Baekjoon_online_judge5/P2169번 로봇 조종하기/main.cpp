#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N,M;
int map[1100][1100];
int DP[1100][1100][3];
int DP2[1100][1100];

int f(int x, int y, int dir, int cost) {
	if(x<=0 || x>N || y<=0 || y>M) return -1000;
	if(x==N && y==M) {
		if(DP[x][y][dir]==-1) {
			DP[x][y][dir] = cost+map[x][y];
		} else {
			DP[x][y][dir] = max(DP[x][y][dir], cost+map[x][y]);
		}
		return DP[x][y][dir];
	}
	int &ret = DP[x][y][dir];
	if(ret != -1 ) return ret;
	
	if(dir==0) {
		ret = max(max(f(x+1,y,0,cost+map[x][y]), f(x,y+1,2,cost+map[x][y])), f(x,y-1,1,cost+map[x][y]));
	} else if(dir==1) {
		ret = max(f(x+1,y,0,cost+map[x][y]), f(x,y-1,1,cost+map[x][y]));
	} else if(dir==2) {
		ret = max(f(x,y+1,2,cost+map[x][y]), f(x+1,y,0,cost+map[x][y]));
	}
	return ret;
}

int f2() {
	
	DP2[1][1]=map[1][1];
	for(int col=2; col<=M; col++) {
		DP2[1][col] = DP2[1][col-1]+map[1][col];
	}
	int line[2][1010];
	for(int i=2; i<=N; i++) {
		for(int col=1; col<=M; col++) {
			//DP2[i][col] = DP2[i-1][col]+map[i][col];
			line[0][col] = line[1][col] = DP2[i-1][col] + map[i][col];
		}
		for(int col=2; col<=M; col++) {
			//line[0][col] = max(DP2[i-1][col], DP2[i][col-1]+map[i][col]);
			line[0][col] = max(line[0][col], line[0][col-1]+map[i][col]);
		}
		for(int col=M-1; col>0; col--) {
			//line[1][col] = max(DP2[i-1][col], DP2[i][col+1]+map[i][col]);
			line[1][col] = max(line[1][col], line[1][col+1]+map[i][col]);
		}
		for(int col=1; col<=M; col++) {
			DP2[i][col] = max(line[0][col], line[1][col]);
		}
	}
	return DP2[N][M];
}

int main() {

	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	memset(DP, -1, sizeof(DP));
	//printf("%d\n", f(1,1,0,0));
	printf("%d\n", f2());

	return 0;
}