#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N,M,matrix[110][110];

void solve() {
	for(int k=1; k<=N; k++) {
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				if(i==j) continue;
				if(matrix[i][j]==0 && ((matrix[i][k]==1 && matrix[k][j]==1) || (matrix[j][k]==1 && matrix[k][i]==1))) {
					matrix[i][j]=1;
					matrix[j][i]=1;
				}
			}
		}
	}
}

int main() {
	memset(matrix,0,sizeof(matrix));
	cin>>N>>M;
	int t1,t2;
	for(int i=0; i<M; i++) {
		cin>>t1>>t2;
		matrix[t1][t2]=1;
		matrix[t2][t1]=1;
	}

	solve();
	int ans=0;
	for(int i=2; i<=N; i++) {
		if(matrix[1][i]==1) ans++;
	}
	cout<<ans<<endl;

	return 0;
}