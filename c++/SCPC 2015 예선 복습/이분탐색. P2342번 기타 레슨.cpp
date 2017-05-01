#include <iostream>
#include <algorithm>
using namespace std;

int N,M,arr[100010];
int lb,ub;

bool f(int m) {
	int sum=0;
	int cnt=1;
	for(int i=0; i<N; i++) {
		if(sum+arr[i]<=m) sum+=arr[i];
		else sum=arr[i], cnt++;
	}
	if(cnt<=M) return true;
	return false;
}

int main() {

	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
		ub+=arr[i];
	}

	int m;
	while(lb<ub) {
		m = (lb+ub-1)/2;
		if(f(m)) ub=m;
		else lb=m+1;
	}
	printf("%d\n", ub);

	return 0;
}