#include <stdio.h>
#include <algorithm>
#include <string.h>

int N,M,map[1100][1100],DP[1100][1100];

int solve2(int x, int y) {
	if(map[x][y+1]==1)
		DP[x][y]=solve2(x,y+1);
	else DP[x][y]=1;
	return DP[x][y]+1;
}

void solve() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(DP[i][j]!=0) continue;
			if(map[i][j]==1) {
				j = j-1+solve2(i,j);
			}
		}
	}
}

int main() {
	char buffer[1000];
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) {
		scanf("%s", &buffer);
		for(int k=1; k<=strlen(buffer); k++) {
			map[i][k]=buffer[k-1]-'0';
		}
	}
	/*
	solve();
	int ans=0;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++) {
			if(map[i][j]==1) {
				int x=i,y=j;
				int len=DP[x][y], height=0;
				while(map[x][y]==1 && DP[x][y]>=height) {
					len = std::min(len,DP[x][y]);
					x++,height++;
				}
				ans = std::max(ans,std::min(len,height));
			}
		}
	*/
	int ans=0;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(map[i][j]==1) {
				int a,b,c,d;
				a = DP[i-1][j-1];
				b = DP[i-1][j];
				c = DP[i][j-1];
				d = std::min(a,b);
				d = std::min(d,c);
				DP[i][j]=d+1;
				ans = std::max(ans,DP[i][j]);
			}
		}
	}

	printf("%d\n", ans*ans);

	return 0;
}

/*
4 4
1111
1111
1111
1111

5 5
11000
11000
00111
00111
00111

6 6
111000
110000
100001
000111
000111
001111

8 6
111000
110000
101111
011111
111011
011111
000111
001111
011111

*/