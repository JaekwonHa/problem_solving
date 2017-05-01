#include <stdio.h>

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}, h,w,S[110][110], res;

bool safe(int a, int b) {
	return (0<=a && a<h && 0<=b && b<w);
}

bool done(void) {
	int cnt=0;
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++) {
			if(S[i][j]==-1 || S[i][j]>2) S[i][j]=0;
			else if(S[i][j]==2 || S[i][j]==1)
				S[i][j]=1, cnt++;
		}
	return cnt==0;
}
int solve(int a, int b) {
	S[a][b]=-1;
	for(int i=0; i<4; i++) {
		if(S[a+dx[i]][b+dy[i]]==0)
			solve(a+dx[i], b+dy[i]);
		else if(S[a+dx[i]][b+dy[i]]>0)
			S[a+dx[i]][b+dy[i]]++;
	}
}

int main() {
	scanf("%d, %d", &h, &w);
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
			scanf("%d", &S[i][j]);
	for(res=0; !done(); res++)
		solve(0,0);
	printf("%d", res);
	return 0;
}