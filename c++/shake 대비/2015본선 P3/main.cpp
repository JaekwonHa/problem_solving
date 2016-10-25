#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N,M;
int DP[1100][4];
int arr[1100];
bool chk[1100];

int f(int cnt, int n) {
	if(n>N || cnt>2) return 0;

	int& ret = DP[n][cnt];
	if(ret != -1) return ret;

	ret=f(0,n+1);
	if(chk[n+1] == false && cnt<2) {
		ret=max(ret, f(cnt+1,n+1)+arr[n]);
	}
	return ret;
}

int main() {
	int t;

	memset(DP,-1,sizeof(DP));
	memset(chk,false,sizeof(chk));

	cin>>N>>M;
	for(int i=1; i<=N; i++) cin>>arr[i];
	for(int i=0; i<M; i++) cin>>t, chk[t]=true;

	
	cout<<f(0,1)<<endl;

	return 0;
}