#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> Point;

char map[20][20];
int visit[20][20];
int chainX[20];
int chainY[20];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void clearPuyo() {
	
	for(int j=0; j<6; j++) {
		queue<char> q;
		for(int i=11; i>=0; i--) {
			if(visit[i][j]!=4) {
				q.push(map[i][j]);
			}
		}
		int cnt=11;
		for(int i=11; i>=0; i--) {
			if(q.empty()) {
				map[i][j]='.';
			} else {
				map[i][j]=q.front();
				q.pop();
			}
		}
	}
}

int bfs(int x, int y) {

	char type=map[x][y];

	queue<Point> q;
	Point p(x,y);
	q.push(p);
	
	int ret=1;
	visit[x][y]=1;
	chainX[0]=x,chainY[0]=y;
	while(!q.empty()) {
		Point cur=q.front();
		q.pop();
		int nextX,nextY;
		for(int i=0; i<4; i++) {
			nextX = cur.first+dx[i];
			nextY = cur.second+dy[i];

			if(map[nextX][nextY] != type || visit[nextX][nextY]>0) continue;
			if(nextX<0 || nextX>=12 || nextY<0 || nextY>=6) continue;

			visit[nextX][nextY]=1;
			chainX[ret]=nextX,chainY[ret]=nextY;
			ret++;
			
			Point t(nextX,nextY);
			q.push(t);
		}
	}
	return ret;
}

int solve() {
	int check,ret=0;
	for(int i=11; i>=0; i--) {
		for(int j=5; j>=0; j--) {
			if(map[i][j] != '.' && visit[i][j]==0) {
				check=bfs(i,j);
				if(check>=4) {
					ret++;
					for(int i=0; i<check; i++) {
						visit[chainX[i]][chainY[i]]=4;
					}
					//clearPuyo();
					//return ret;
				}
			}
		}
	}
	clearPuyo();
	return ret;
}

int main() {

	for(int i=0; i<12; i++)
		scanf("%s", &map[i]);

	int ans=0,check=1;
	while(1) {
		memset(visit,0,sizeof(visit));
		check=solve();
		if(check==0) break;
		//ans+=check;
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}