#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){

	int dp[10201];
	

	int i,j;

	int max_price, items;
	while(cin>>max_price, items) {

		memset(dp, 0, 10201*sizeof(int));

		int max_price_plus = max_price;
		if(max_price_plus > 1800) max_price_plus+=200;

		int price[101], favour[101];

		for(i=1; i<=items; i++) cin>>price[i]>>favour[i];

		for(i=1; i<=items; i++) {
			for(j=max_price_plus; j>=price[i]; j--) {
				dp[j] = max(dp[j], dp[j-price[i]]+favour[i]);
			}
		}

		if(max_price >1800 && max_price <2001) {
			
		}

	}

	return 0;
}