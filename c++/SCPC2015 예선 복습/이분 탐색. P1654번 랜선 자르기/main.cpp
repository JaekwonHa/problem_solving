#include <iostream>
#include <algorithm>
using namespace std;

int K,N;
long long lb,ub,arr[10000];

bool f(long long m) {
	long long sum=0;
	for(int i=0; i<K; i++) {
		sum += arr[i]/m;
	}
	return (sum>=N)?true:false;
}

int main() {

	scanf("%d %d", &K, &N);
	for(int i=0; i<K; i++) {
		scanf("%lld", &arr[i]);
		ub = max(ub,arr[i]);
	}
	long long m;
	while(lb<ub) {
		m = (lb+ub+1)/2;
		if(f(m)) lb=m;
		else ub=m-1;
	}
	printf("%lld\n", ub);

	return 0;
}