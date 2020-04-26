#include <iostream>
#include <string.h>

using namespace std;

int N;
char map[16][16];
bool check[16];
int result;

void DFS(int x, int weight, int answer) {
	check[x]=1;
	for(int i=1; i<N; i++) {
		if(check[i]==0 && map[x][i]-'0'>=weight) {
			DFS(i,(map[x][i]-'0'),answer+1);
			check[i]=0;
		}
	}
	if(answer > result) result = answer;
}

int main() {

	cin>>N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin>>map[i][j];
	int answer=1;
	memset(check, 0, sizeof(check));
	check[0]=1;

	DFS(0,0,1);

	cout<<result<<endl;

	return 0;
}