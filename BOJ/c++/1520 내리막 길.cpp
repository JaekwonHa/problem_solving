#include <stdio.h>
#include <string.h>

int N,M, map[502][502], DT[502][502];
int Dx[4]={0,1,0,-1}, Dy[4]={1,0,-1,0};

void primise(int x, int y, int a, int b) {
	if(map[a][b] > map[x][y]) {
		DT[x][y]++;
	}
}
void solve() {
	DT[1][1]=1;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			for(int k=0; k<4; k++) {
				primise(i,j,i+Dx[k],j+Dy[k]);
			}
		}
	}
}
int f(int x, int y) {
	if(x<1 || y<1 || x>N || y>M) return 0;
	if(x==1 && y==1) return 1;

	int ret = DT[x][y];
	if(ret != -1) return ret;

	ret = 0;
	for(int k=0; k<4; k++) {
		if(map[x+Dx[k]][y+Dy[k]]!=-1) {
			if(map[x][y] < map[x+Dx[k]][y+Dy[k]]) {
				ret += f(x+Dx[k], y+Dy[k]);
			}
		}
	}
	return DT[x][y]=ret;
}

int main() {

	memset(DT, -1, sizeof(DT));
	memset(map, -1, sizeof(map));

	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%d", &map[i][j]);

	//solve();
	//printf("%d", DT[N][M]);
	
	
	printf("%d", f(N,M));

	return 0;
}