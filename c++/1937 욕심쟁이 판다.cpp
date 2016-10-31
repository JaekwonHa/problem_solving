#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 510

int N,K,map[MAXN][MAXN],DP[MAXN][MAXN];
int dx[4]={0,1,-1,0}, dy[4]={1,0,0,-1};

bool safe(int x, int y) {
	return 0<=x && x<N && 0<=y && y<N;
}

int f(int x, int y) {

	if(DP[x][y]==0) {
		DP[x][y]=1;
		int nextX,nextY;
		for(int i=0; i<4; i++) {
			nextX = x+dx[i], nextY = y+dy[i];
			if(safe(nextX, nextY) && map[x][y]<map[nextX][nextY]) {
				DP[x][y] = max(DP[x][y],f(nextX, nextY)+1);
			}
		}
	}
	return DP[x][y];
}

int main() {

	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			K = max(K,f(i,j));
		}
	}
	printf("%d", K);

	return 0;
}