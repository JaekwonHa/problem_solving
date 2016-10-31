#include <stdio.h>

int map[20][20];
int ans;
int dx[4] = {-1, 0, 1, 1};
int dy[4] = {1, 1, 1, 0};

bool safe(int x, int y) {
	return ( x>=0 && x<19 && y>= 0 && y<19 );
}

int dfs(int x, int y, int color, int dir, int cnt) {
	if(safe(x+dx[dir], y+dy[dir]) && map[x+dx[dir]][y+dy[dir]] == color) {
		return dfs(x+dx[dir], y+dy[dir], color, dir, cnt+1);
	}
	if(cnt == 5) return 1;
	return 0;
}

int main() {
	for(int i=0; i<19; i++)
		for(int j=0; j<19; j++)
			scanf("%d", &map[i][j]);

	for(int i=0; i<19; i++)
		for(int j=0; j<19; j++) {
			for(int k=0; k<4; k++) {
				if(safe(i-dx[k], j-dy[k]) && map[i-dx[k]][j-dy[k]] == map[i][j])
					continue;
				if(map[i][j])
					if(dfs(i,j,map[i][j],k,1)) {
						printf("%d\n", map[i][j]);
						printf("%d %d\n", i+1,j+1);
						return 0;
					}
			}
		}
	printf("%d", 0);
	return 0;
}