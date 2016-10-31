#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct Point {
	int x;
	int y;
	int cost;
};

int R,C,map[55][55],cost[55][55],visited[51][51];
queue<Point> q;
queue<Point> fire;
int dx,dy,ans;
int cx[4] = {1,0,-1,0};
int cy[4] = {0,1,0,-1};

bool isIn(int x, int y) {
	return x>=0 && x<R && y>=0 && y<C;
}

void solve() {
	// fire process
	while(!fire.empty()) {
		int current_x = fire.front().x;
		int current_y = fire.front().y;
		int current_c = fire.front().cost;
		fire.pop();
		for(int i=0; i<4; i++) {
			int next_x = current_x+cx[i];
			int next_y = current_y+cy[i];
			if(!isIn(next_x, next_y)) continue;
			if(map[next_x][next_y]==-1) continue;
			if(cost[next_x][next_y]!=0) continue;
			cost[next_x][next_y]=current_c+1;
			Point p = {next_x, next_y, current_c+1};
			fire.push(p);
		}
	}
	while(!q.empty()) {
		int current_x = q.front().x;
		int current_y = q.front().y;
		int current_c = q.front().cost;
		q.pop();
		for(int i=0; i<4; i++) {
			int next_x = current_x+cx[i];
			int next_y = current_y+cy[i];
			if(!isIn(next_x, next_y)) continue;
			if(next_x==dx && next_y==dy) {
				ans=current_c+1;
				return;
			}
			if(map[next_x][next_y]==-1) continue;
			if(cost[next_x][next_y]!=0 && cost[next_x][next_y]<=current_c+1) continue;
			if(visited[next_x][next_y]==1) continue;
			visited[next_x][next_y]=1;
			Point p = {next_x, next_y, current_c+1};
			q.push(p);
		}
	}
}

int main() {
	string str;
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++) {
		cin>>str;
		for(int j=0; j<C; j++) {
			Point p;
			switch(str[j]) {
			case 'D':
				map[i][j]=-1;
				dx=i, dy=j;
				break;
			case 'S':
				map[i][j]=-1;
				p.x=i, p.y=j, p.cost=0;
				q.push(p);
				break;
			case '*':
				map[i][j]=-1;
				p.x=i, p.y=j, p.cost=0;
				fire.push(p);
				break;
			case 'X':
				map[i][j]=-1;
				break;
			}
		}
	}

	solve();

	if(ans==0)
		printf("KAKTUS\n");
	else
		printf("%d\n", ans);

	return 0;
}