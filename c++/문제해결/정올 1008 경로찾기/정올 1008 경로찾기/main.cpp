#include <iostream>
#include <string.h>

using namespace std;

struct Step {
	int x;
	int y;
	int t;
	int v;
};

Step BFS[10010];
int matrix[110][110];
int BFS_matrix[110][110];
int checked[110][110];
int Gox[4] = {0, 0, 1, -1};
int Goy[4] = {1, -1, 0, 0};

int main() {

	int i,j,n,t,count;
	Step st, end;
	memset(matrix, 0, 110*110*sizeof(int));
	memset(checked, -1, 110*110*sizeof(int));
	memset(BFS_matrix, -1, 110*110*sizeof(int));

	cin>>n>>t;

	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			cin>>matrix[i][j];
			if(matrix[i][j]==-1) st.x=i, st.y=j, st.t=0, st.v=0;
			else if (matrix[i][j]==-2) end.x=i, end.y=j, end.t=0, end.v=0;
		}
	}

	BFS[0]=end;
	i=0, count=0;
	while(true) {
		if(count<i) break;
		for(j=0; j<4; j++) {
			if(BFS[i].x+Gox[j] <1 || BFS[i].x+Gox[j] >n) continue;
			if(BFS[i].y+Goy[j] <1 || BFS[i].y+Goy[j] >n) continue;
			if(matrix[BFS[i].x+Gox[j]][BFS[i].y+Goy[j]]==0) continue;
			if(BFS_matrix[BFS[i].x+Gox[j]][BFS[i].y+Goy[j]] != -1) continue;

			count++;
			BFS[count].x=BFS[i].x+Gox[j];
			BFS[count].y=BFS[i].y+Goy[j];
			BFS[count].t=BFS[i].t+1;
			BFS_matrix[BFS[count].x][BFS[count].y] = BFS[count].t;
		}
		i++;
	}
	BFS[0]=st;
	i=0, count=0;
	while(true) {
		if(count<i) break;
		for(j=0; j<4; j++) {
			if(BFS[i].x+Gox[j] <1 || BFS[i].x+Gox[j] >n) continue;
			if(BFS[i].y+Goy[j] <1 || BFS[i].y+Goy[j] >n) continue;
			if(matrix[BFS[i].x+Gox[j]][BFS[i].y+Goy[j]]==0) continue;

			if(BFS[i].t+BFS_matrix[BFS[i].x+Gox[j]][BFS[i].y+Goy[j]] > t) continue;

			if(checked[BFS[i].x+Gox[j]][BFS[i].y+Goy[j]]==-1) checked[BFS[i].x+Gox[j]][BFS[i].y+Goy[j]] = BFS[i].v + matrix[BFS[i].x+Gox[j]][BFS[i].y+Goy[j]];
			else {
				( BFS[count].t ) / BFS[i].v
			}
			
			count++;
			BFS[count].x = BFS[i].x+Gox[j];
			BFS[count].y = BFS[i].y+Goy[j];
			BFS[count].t = BFS[i].t+1;
			BFS[count].v = checked[BFS[i].x+Gox[j]][BFS[i].y+Goy[j]];

		}
	}
	


	return 0;
}