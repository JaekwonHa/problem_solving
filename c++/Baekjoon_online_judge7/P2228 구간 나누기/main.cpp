#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

long long DP[110][110];
int N,M;
long long arr[110];

int main() {
	for(int i=1; i<=M; i++) {
		for(int j=0; j<=N; j++) {
			DP[i][j] = -987654321;
		}
	}


	cin>>N>>M;
	int in,sum=0;
	cin>>arr[1];
	//DP[1][0]=arr[0];
	for(int i=2; i<=N; i++) {
		cin>>arr[i];
		//DP[1][i] = max(DP[1][i-1]+arr[i], arr[i]);
	}
	/*
	for(int i=2; i<=M; i++) {
		DP[i][(i-1)*2-1]=DP[i-1][(i-1)*2-1];
		for(int j=(i-1)*2; j<N; j++) {
			DP[i][j] = max(DP[i][j-1]+arr[j], DP[i-1][j-2]+arr[j]);
		}
	}
	*/
	DP[1][1] = arr[1];
	for(int i=2; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			DP[j][i] = DP[j][i-1]+arr[i];
			for(int k=0; k<i-1; k++) {
				DP[j][i] = max(DP[j][i], DP[j-1][k]+arr[i]);
			}
		}
	}

	long long ans=-987654321;
	for(int i=1; i<=N; i++) ans=max(ans,DP[M][i]);
	cout<<ans;

	return 0;
}