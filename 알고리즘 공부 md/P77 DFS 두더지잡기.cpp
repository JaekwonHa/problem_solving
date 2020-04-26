#include <iostream>
#include <algorithm>

using namespace std;

int map[31][31];
int visited[31][31];
int n,cnt;
int size[101];

int cmp(int a, int b) {
	return a>b;
}

bool safe(int a, int b) {
	return (a>=0 && a<n && b>=0 && b<n);
}

void DFS(int x, int y, int c) {
	map[x][y]=c;
	if(safe(x-1, y) && map[x-1][y]==1)
		DFS(x-1,y,c);
	if(safe(x, y-1) && map[x][y-1]==1)
		DFS(x,y-1,c);
	if(safe(x+1, y) && map[x+1][y]==1)
		DFS(x+1,y,c);
	if(safe(x, y+1) && map[x][y+1]==1)
		DFS(x,y+1,c);
}
void solve() {
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(map[i][j]==1) {
				cnt++;
				DFS(i,j,cnt+1);
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