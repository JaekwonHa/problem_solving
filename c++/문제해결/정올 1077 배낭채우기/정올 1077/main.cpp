#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	
	int dp[10001];

	int max_weight, items, i, j;

	while(cin>>items>>max_weight) {
		
		memset(dp,0,10001*sizeof(int));

		int weight[1001], price[1001];
		for(i=1; i<=items; i++) cin>>weight[i]>>price[i];
		/*
		for(i=1; i<=items; i++)
			for(j=max_weight; j>=weight[i]; j--)
				dp[j] = max(dp[j], dp[j-weight[i]]+price[i]);
				*/
		for(i=1; i<=max_weight; i++) {
			dp[i] = dp[i-1];
			for(j=items; j>=1; j--) {
				if(i-weight[j] >= 0) dp[i] = max(dp[i], dp[i-weight[j]]+price[j]);
			}
		}
		/*
		int result=0;
		for(i=0; i<=max_weight; i++) result=max(result, dp[i]);
		*/
		cout<<dp[max_weight]<<endl;
	}

	return 0;
}