#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
int h,w;
int startX, startY, goalX, goalY;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct point {int x; int y; int c;};

bool safe(int a, int b) {
	return (a>=0 && a<h && b>=0 && b<w);
}

int bfs(int x, int y, int weight) {
	queue<point> Q;
	point p;
	p.x = x, p.y = y, p.c = 0;
	Q.push(p);
	while(!Q.empty()) {
		point curr = Q.front();
		Q.pop();
		for(int i=0; i<3; i++) {
			if(curr.x+dx[i] == goalX && curr.y+dy[i] == goalY) return curr.c+1;
			if(safe(curr.x+dx[i],curr.y+dy[i]) && weight < map[curr.x+dx[i]][curr.y+dy[i]] && map[curr.x+dx[i]][curr.y+dy[i]] != -1) {
				map[curr.x+dx[i]][curr.y+dy[i]] = curr.c+1;
				point next;
				next.x = curr.x+dx[i], next.y = curr.y+dy[i], next.c = curr.c+1;
				Q.push(next);
			}
		}
	}
	return -1;
}

int main() {
	char input;
	cin>>h>>w;
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++) {
			cin>>input;
			if(input=='#') map[i][j]=-1;
			else if(input=='.') map[i][j]=987654321;
			else if(input=='S')
				startX = i, startY = j, map[i][j]=-1;
			else if(input=='G')
				goalX = i, goalY = j, map[i][j]=-1;
		}
	cout<<bfs(startX, startY, 0)<<endl;

	return 0;
}