#include <iostream>
#include <string.h>

using namespace std;

int map[50][50];
int N,M,answer;

void DFS(int x, int y) {
	map[x][y]++;
	if( x>0 && map[x-1][y]==1)
		DFS(x-1,y);
	if( y>0 && map[x][y-1]==1)
		DFS(x,y-1);
	if( x<M-1 && map[x+1][y]==1)
		DFS(x+1,y);
	if( y<N-1 && map[x][y+1]==1)
		DFS(x,y+1);
}

int main() {

	int T,K,x,y,i,j;
	cin>>T;
	while(T--) {
		cin>>M>>N>>K;
		memset(map, 0, sizeof(map));
		answer=0;
		for(i=0; i<K; i++) {
			cin>>x>>y;
			map[x][y]=1;
		}
		for(i=0; i<M; i++) {
			for(j=0; j<N; j++) {
				if(map[i][j]==1) {
					answer++;
					DFS(i,j);
				}
			}
		}
		cout<<answer<<endl;
	}


}