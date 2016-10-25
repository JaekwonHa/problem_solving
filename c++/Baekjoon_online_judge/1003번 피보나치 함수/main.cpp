#include <iostream>

using namespace std;

int main() {

	int dp[41][2];
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;

	for(int i=2; i<=40; i++) {
		dp[i][0] = dp[i-1][0] + dp[i-2][0];
		dp[i][1] = dp[i-1][1] + dp[i-2][1];
	}

	int cnt=0,t;
	cin>>cnt;
	for(int i=0; i<cnt; i++) {
		cin>>t;
		cout<<dp[t][0]<<" "<<dp[t][1]<<endl;
	}

}