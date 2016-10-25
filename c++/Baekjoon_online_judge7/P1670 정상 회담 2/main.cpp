#include <iostream>
#include <string.h>
using namespace std;

#define p 987654321

int N;
long long DP[10100];

long long f(int n) {
	if(n<=2) return 1;

	long long& ret = DP[n];
	if(ret != -1) return ret;

	ret =0;
	for(int k=2; k<=n; k+=2) {
		ret += f(n-k)*f(k-2)%p;
	}
	ret = ret%p;
	return ret;
}

int main() {

	cin>>N;
	memset(DP,-1,sizeof(DP));

	cout<<f(N);

	return 0;
}