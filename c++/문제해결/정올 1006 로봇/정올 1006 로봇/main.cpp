#include <iostream>
#include <string.h>

using namespace std;

struct Robot {
	int x;
	int y;
	int d;
};

int checked[110][110][5];
int Gox[5] = {0, 0, 0, 1, -1};
int Goy[5] = {0, 1, -1, 0, 0};
int Turn[5] = {0, 3, 4, 1, 2};
Robot BFS[40010];

int main() {

	int M,N,i,j, k, block, count;
	Robot st, end;

	while(cin>>M>>N) {
		memset(checked, -1, 110*110*5*sizeof(int));
		for(i=1; i<=M; i++) {
			for(j=1; j<=N; j++) {
				cin>>block;
				if(block==1) checked[i][j][0]=-2;
			}
		}
		cin>>st.x>>st.y>>st.d;
		cin>>end.x>>end.y>>end.d;

		

		BFS[1]=st;
		i=1, count=1;
		checked[st.x][st.y][st.d] = 0;

		while(true) {
			if(count<i) break;
			
			for(j=1; j<=3; j++) {
				if(BFS[i].x+Gox[BFS[i].d]*j <1 || BFS[i].x+Gox[BFS[i].d]*j >M) break;
				if(BFS[i].y+Goy[BFS[i].d]*j <1 || BFS[i].y+Goy[BFS[i].d]*j >N) break;
				if(checked[BFS[i].x+Gox[BFS[i].d]*j][BFS[i].y+Goy[BFS[i].d]*j][0] == -2) break;
				if(checked[BFS[i].x+Gox[BFS[i].d]*j][BFS[i].y+Goy[BFS[i].d]*j][BFS[i].d] != -1) continue; 

				count++;
				BFS[count].x = BFS[i].x+Gox[BFS[i].d]*j;
				BFS[count].y = BFS[i].y+Goy[BFS[i].d]*j;
				BFS[count].d = BFS[i].d;
				checked[BFS[count].x][BFS[count].y][BFS[count].d] = checked[BFS[i].x][BFS[i].y][BFS[i].d] + 1;
			}
			if(BFS[i].d==1 || BFS[i].d==2) j=1;
			else j=3;
			for(k=0; k<2; k++) {
				if(checked[BFS[i].x][BFS[i].y][Turn[j]] != -1) {
					j++;
					continue;
				}
				count++;
				BFS[count].x = BFS[i].x;
				BFS[count].y = BFS[i].y;
				BFS[count].d = Turn[j];
				checked[BFS[count].x][BFS[count].y][BFS[count].d] = checked[BFS[i].x][BFS[i].y][BFS[i].d] + 1;
				j++;
				
			}
			i++;
		}
		cout<<checked[end.x][end.y][end.d]<<endl;
		return 0;
	}
	return 0;
}