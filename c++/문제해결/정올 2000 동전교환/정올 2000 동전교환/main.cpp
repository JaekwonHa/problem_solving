#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {

	int dp[64001];

	int i,j,w, items, money;
	int coin[10];

	while(cin>>items) {
		memset(dp,0,64001*sizeof(int));
		for(i=0; i<items; i++) cin>>coin[i];
		cin>>money;

		for(w=1; w<=money; w++) {
			dp[w]=99999;
			for(i=0; i<items; i++) {
				if(w-coin[i]>0 && dp[w-coin[i]]==99999) {
				
				} else if(w-coin[i]>=0) {
					dp[w] = min(dp[w], dp[w-coin[i]]+1);
				}
			}
		}
		if(dp[money]==99999) cout<<"impossible"<<endl;
		else cout<<dp[money]<<endl;
	}

	return 0;
}