#include <stdio.h>

int n, map[128][128];

int ans[2];

void solve(int x, int y, int size) {

	if(size==1) {
		ans[map[x][y]]++;
		return;
	}

	int check=1,i,j;
	int color = map[x][y];
	for(i=x; i<x+size; i++) {
		for(j=y; j<y+size; j++) {
			if(color != map[i][j]) {
				check=0;
				break;
			}
		}
		if(j != y+size)
			break;
	}
	if(check) {
		ans[color]++;
		return;
	}
	solve(x,y,size/2);
	solve(x,y+size/2,size/2);
	solve(x+size/2,y,size/2);
	solve(x+size/2,y+size/2,size/2);
}


int main() {

	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &map[i][j]);

	solve(0,0,n);

	printf("%d\n%d", ans[0], ans[1]);

	return 0;
}