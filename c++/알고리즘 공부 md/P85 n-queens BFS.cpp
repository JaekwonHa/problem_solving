#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[31][31];
int size[101];
int n, cnt;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int cmp(int a, int b) {
	return a>b;
}

bool safe(int a, int b) {
	return (a>=0 && a<n && b>=0 && b<n);
}

struct Point {
	int x;
	int y;
};

void bfs(int x, int y, int c) {
	queue<Point> Q;
	Point p;
	p.x = x, p.y = y;
	Q.push(p);
	map[x][y]=c;
	while(!Q.empty()) {
		Point current = Q.front();
		Q.pop();
		for(int i=0; i<4; i++) {
			if( safe(current.x+dx[i], current.y+dy[i]) &&  map[current.x+dx[i]][current.y+dy[i]]==1) {
				map[current.x+dx[i]][current.y+dy[i]]=c;
				Point next;
				next.x = current.x+dx[i], next.y = current.y+dy[i];
				Q.push(next);
			}
		}
		
	}
}

void solve() {
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(map[i][j]==1) {
				cnt++;
				bfs(i,j,cnt+1);
			}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(map[i][j])
				size[map[i][j]-2]++;
	sort(size, size+cnt, cmp);
}

int main() {
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>map[i][j];
	solve();
	cout<<cnt<<endl;
	for(int i=0; i<cnt; i++)
		cout<<size[i]<<endl;

	return 0;
}