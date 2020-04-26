#include <stdio.h>

int n,m;
int map[200][200];
int ans[200][200];

void f(int x, int y, int cost) {
	//if(ans[x][y] < cost) return;
	if(ans[x][y]==0 || (ans[x][y]!=0 && ans[x][y] < cost))
		ans[x][y] = cost;
	if(ans[x][y] != 0 && ans[x][y]>cost)
		return;
	if(x==n-1 && y==m-1) {
		ans[x][y]=cost;
		return;
	}
	if(x>=n || y>=m) {
		return;
	}
	f(x+1, y, cost+map[x][y]);
	f(x, y+1, cost+map[x][y]);
}


int main() {

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &map[i][j]);

	f(0,0,map[0][0]);

	printf("%d", ans[n-1][m-1]);

	return 0;
}