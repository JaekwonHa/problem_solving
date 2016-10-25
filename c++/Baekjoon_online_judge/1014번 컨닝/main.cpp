#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

int map[15][15];
int check[15][15],N,M;

int DFS(int x, int y, int answer) {
	int k=0,i,j;
	while(k<=N && check[x+k][y]==1) {
		check[x+k][y]=0;
		check[x+k-1][y-1]=0;
		check[x+k][y-1]=0;
		check[x+k-1][y+1]=0;
		check[x+k][y+1]=0;
		k++;
		answer++;
	}
	for(i=x; i<=N; i++) {
		(i==x) ? j=y : j=1;
		for(; j<=M; j++) {
			if(check[i][j]) {
				answer = DFS(i,j,answer);
			}
		}
	}
	return answer;
}

int main() {

	int C,i,j;
	char buffer;
	memset(map, 0, sizeof(map));
	memset(check, 0, sizeof(check));
	cin>>C;
	while(C--) {
		cin>>N>>M;
		for(i=1; i<=N; i++) {
			for(j=1; j<=M; j++) {
				cin>>buffer;
				(buffer=='.') ? map[i][j]=1 : map[i][j]=0;
			}
		}
		int answer=0;
		for(i=1; i<=N; i++) {
			for(j=1; j<=M; j++) {
				if(map[i][j]==1) {
					for(int k=0; k<=N+1; k++)
						for(int l=0; l<=M+1; l++)
							check[k][l]=map[k][l];
					answer = max(answer, DFS(i,j,0));
				}
			}
		}
		cout<<answer<<endl;
	}
}