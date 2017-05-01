#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
double K;
char map[500][500];
int block[500][500];
int ans=0;
int start=true;
bool index_check[10000];

int dx[4] = {-1,-1,1,1};
int dy[4] = {-1,1,1,-1};

void dfs_block_check(int x, int y, int index) {
	if(x<0 || y<0 || x>2*M || y>2*N) return;

	block[x][y]=index;

	if(x-1>=0 && block[x-1][y]==0) {
		block[x-1][y]=index;
		if(map[x-1][y]=='.' && x-2>=0) {
			dfs_block_check(x-2,y,index);
		}
	}
	if(block[x+1][y]==0) {
		block[x+1][y]=index;
		if(map[x+1][y]=='.') {
			dfs_block_check(x+2,y,index);
		}
	}
	if(y-1>=0 && block[x][y-1]==0) {
		block[x][y-1]=index;
		if(map[x][y-1]=='.' && y-2>=0) {
			dfs_block_check(x,y-2,index);
		}
	}
	if(block[x][y+1]==0) {
		block[x][y+1]=index;
		if(map[x][y+1]=='.') {
			dfs_block_check(x,y+2,index);
		}
	}
}

void dfs(int x, int y, int dir) {
	if(!start) {
		if(x>=2*M) return;
	} else {
		start = false;
	}
	
	int next_x = x+dx[dir];
	int next_y = y+dy[dir];
	if(next_x<0 || next_y<0 || next_x>2*M || next_y>2*N) {
		if(dir==0) {
			if(next_y<0) {
				dir=1;
			} else {
				dir=3;
			}
		}
		if(dir==1) {
			if(next_x<0) {
				dir=2;
			} else {
				dir=1;
			}
		}
		if(dir==2) {
			dir=3;
		}
		if(dir==3) {
			dir=2;
		}
		dfs(x, y, dir);
	} else {
		if(block[x][y]>0) {
			if(index_check[block[x][y]]==false) {
				index_check[block[x][y]]=true;
				ans++;
			}
		}
		dfs(next_x, next_y,dir);
	}
}

int main() {

	cin>>N>>M>>K;
	K = 2*K;
	for(int i=0; i<=2*M; i++)
		cin>>map[i];
	
	int index=1;
	for(int i=1; i<=2*M; i+=2) {
		for(int j=1; j<=2*N; j+=2) {
			if(block[i][j]>0) continue;
			if(map[i][j]=='B') {
				dfs_block_check(i,j,index);
				index++;
			}
		}
	}
	
	dfs(2*M,K,0);

	printf("%d\n", ans);

	return 0;
}