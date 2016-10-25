#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int map[110][110];

bool check[110][110];
int W,H;

bool dfs(int x, int y) {
	if(x<1 || x>W || y<1 || y>H) return true;
	if(check[x][y] == true || map[x][y]==1) return false;
	check[x][y]=true;
	bool is = false;
	if(y%2==1) {
		is = is | dfs(x, y-1);
		is = is | dfs(x+1, y-1);
		is = is | dfs(x-1, y);
		is = is | dfs(x+1, y);
		is = is | dfs(x, y+1);
		is = is | dfs(x+1, y+1);
	} else {
		is = is | dfs(x-1, y-1);
		is = is | dfs(x, y-1);
		is = is | dfs(x-1, y);
		is = is | dfs(x+1, y);
		is = is | dfs(x-1, y+1);
		is = is | dfs(x, y+1);
	}
	
	return is;
}

int main() {

	
	scanf("%d %d", &W, &H);

	for(int i=1; i<=H; i++) {
		for(int j=1; j<=W; j++) {
			scanf("%d", &map[j][i]);
		}
	}

	for(int i=1; i<=H; i++) {
		for(int j=1; j<=W; j++) {
			if(map[j][i]==0) {
				if(!dfs(j,i)) {
					map[j][i]=1;
				}
				memset(check,false, sizeof(check));
			}
		}
	}

	int ans=0;
	for(int i=1; i<=H; i++) {
		for(int j=1; j<=W; j++) {
			if(map[j][i]==1) {
				int count=6;
				if(i%2==1) {
					if(map[j][i-1]==1) count--;
					if(map[j+1][i-1]==1) count--;
					if(map[j-1][i]==1) count--;
					if(map[j+1][i]==1) count--;
					if(map[j][i+1]==1) count--;
					if(map[j+1][i+1]==1) count--;
				} else {
					if(map[j-1][i-1]==1) count--;
					if(map[j][i-1]==1) count--;
					if(map[j-1][i]==1) count--;
					if(map[j+1][i]==1) count--;
					if(map[j-1][i+1]==1) count--;
					if(map[j][i+1]==1) count--;
				}
				
				ans += count;
			}
		}
	}
	printf("%d\n", ans);


	return 0;
}