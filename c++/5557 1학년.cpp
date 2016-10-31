#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
typedef unsigned int ui;

int N, arr[110];
long long DP[110][10000];

long long f(int length, int sum) {
	if(sum<0 || sum>20) return 0;
	if(length == N) {
		if(sum == arr[N]) return 1;
		else return 0;
	}
	long long &ret = DP[length][sum];
	if(ret != -1) return ret;
	ret = f(length+1, sum+arr[length]) + f(length+1, sum-arr[length]);
	return ret;
}

int main() {

	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d", &arr[i]);
	}
	memset(DP, -1 ,sizeof(DP));
	printf("%lld\n", f(2,arr[1]));

	return 0;
}