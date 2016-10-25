#include <iostream>
#include <string.h>

using namespace std;

#define MAX 100
int map[MAX][MAX];
int ans[MAX][MAX];
int checked[MAX];
int N;

void DFS(int x) {
	checked[x]++;
	for(int i=0; i<N; i++) {
		if(map[x][i] && checked[i]!=2) {
			DFS(i);
		}
	}
}

int main() {

	memset(map,0,sizeof(map));
	memset(ans,0,sizeof(ans));
	memset(checked,0,sizeof(checked));
	
	cin>>N;
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin>>map[i][j];

	for(int i=0; i<N; i++) {
		DFS(i);
		
		for(int k=0; k<N; k++) {
			if(i==k) continue;
			if(checked[k]>0) {
				ans[i][k]=1;
			}
		}
		if(checked[i]==2) ans[i][i]=1;
		memset(checked,0,sizeof(checked));
	}
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(j!=0) cout<<" ";
			cout<<ans[i][j];
		}
		cout<<endl;
	}
}