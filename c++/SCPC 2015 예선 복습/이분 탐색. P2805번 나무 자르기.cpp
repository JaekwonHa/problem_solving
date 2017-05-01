#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int arr[1000010];
int lb,ub;

bool f(int m) {
	long long sum=0;
	for(int i=0; i<N; i++) {
		if(arr[i]>m) sum+= arr[i]-m;
	}
	return (sum>=M)?true:false; 
}

int main() {

	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
		ub=max(ub,arr[i]);
	}

	int m;
	while(lb<ub) {
		m = (lb+ub+1)/2;
		if(f(m)) lb=m;
		else ub=m-1;
	}
	printf("%d\n", ub);

	return 0;
}