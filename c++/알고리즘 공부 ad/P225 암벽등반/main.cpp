#include <stdio.h>
#include <string.h>

int N,map[501][501],chk[501][501];
int ub,lb,H;

int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

int abs(int a) { return (a<0)?-a:a;}
int max(int a, int b) { return a>b?a:b;}

bool can(int x, int y) {
	return x>=0 && x<N && y>=0 && y<N;
}

int dfs(int x, int y, int h) {
	int cnt=1;
	chk[x][y]=1;
	for(int k=0; k<4; k++) {
		if(can(x+dx[k],y+dy[k]) && !chk[x+dx[k]][y+dy[k]] && abs(map[x+dx[k]][y+dy[k]] - map[x][y]) <= h) {
			cnt += dfs(x+dx[k],y+dy[k],h);
		}
	}
	return cnt;
}

bool f(int h) {
	int mcnt=0,cnt=0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(!chk[i][j]) {
				cnt=dfs(i,j,h);
				mcnt=max(mcnt,cnt);
			}
		}
	}
	return mcnt>=(int)(N*N*0.75);
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++) {
			scanf("%d", &map[i][j]);
			ub=max(ub,map[i][j]);
		}

	while(lb<ub) {
		memset(chk,0,sizeof(chk));
		H = (lb+ub-1)/2;
		if(f(H)) ub=H;
		else lb=H+1;
	}

	printf("%d", ub);

	return 0;
}