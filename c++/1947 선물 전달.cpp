#include <iostream>
#include <algorithm>
using namespace std;
#define p 1000000000

int N;
long long arr[1000010];

void solve() {
	arr[1]=0;
	arr[2]=1;
	for(int i=3; i<=N; i++) {
		arr[i] = (arr[i-1]+arr[i-2])*(i-1)%p;
	}
}

int main() {

	scanf("%d", &N);

	solve();

	printf("%lld\n", arr[N]);

	return 0;
}