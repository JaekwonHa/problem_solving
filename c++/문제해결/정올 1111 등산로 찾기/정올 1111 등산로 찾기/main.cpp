#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

struct person {
	int x;
	int y;
	int w;
};

int mount[101][101];
int checked[101][101];
int n,x,y;
int move[4][4] = {{-1,0},{1,0},{0,-1},{0,1}};
person BFS[10000];


int main() {
	memset(mount,0,sizeof(mount));
	memset(matrix,0,sizeof(matrix));
	memset(checked,0,sizeof(checked));

	person st;
	st.w=0;
	int i,j,w;
	cin>>n>>st.x>>st.y;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			cin>>mount[i][j];

	BFS[0]=st;



	return 0;
}