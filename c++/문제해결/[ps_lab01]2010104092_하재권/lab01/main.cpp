#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

#define isOdd(x) x%2 != 0 ? (true) : (false)
#define M 100000000

int dp[M];

int recursive(int count, int number) {
	
	if(isOdd(number)) number = 3*number+1;
	else number /= 2;

	if(number < M && dp[number]) {
			return dp[number]+1;
		} else if(number < M){
			dp[number] = recursive(count, number);
			return dp[number]+1;
		} else {
			count = recursive(count, number);
			return count+1;
		}
}

int main() {

	memset(dp, 0, M*sizeof(int));

	dp[1]=1;

	int a,b,T,cnt=1;
	cin>>T;
	while(T--) {
		cin>>a>>b;
		int min_number = min(a,b);
		int max_number = max(a,b);
		int count=0;
		int max_count=0;
		for(int i=min_number; i<=max_number; i++) {
			if(dp[i]) count=dp[i];
			else count=recursive(0, i);

			max_count = max(max_count, count);
		}
		cout<<"Case#"<<cnt++<<endl;
		cout<<a<<" "<<b<<" "<< max_count<<endl;
	}
	
	return 0;
}	