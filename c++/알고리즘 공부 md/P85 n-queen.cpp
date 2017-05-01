#include <iostream>
#include <string.h>

using namespace std;

int map[3][20];
int N;
int answer;

void solve(int r) {
	if(r>N) {
		answer++;
		return;
	}
	for(int c=1; c<=N; c++) {
		if(!map[0][c] && !map[1][r+c] && !map[2][N+(r-c)+1]) {	
			map[0][c]=map[1][r+c]=map[2][N+(r-c)+1]=1;
			solve(r+1);
			map[0][c]=map[1][r+c]=map[2][N+(r-c)+1]=0;
		}
	}
}

int main() {
	//while(1) {
		//memset(map, 0, sizeof(map));
		//answer=0;
	cin>>N;
	solve(1);
	cout<<answer<<endl;
	//}
	return 0;
}