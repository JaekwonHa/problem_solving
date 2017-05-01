#include <iostream>
#include <algorithm>
using namespace std;

int arr[200010],N,C;
int lb,ub;

bool f(int m) {
	int cnt=1;
	int prev=arr[0];
	for(int i=1; i<N; i++) {
		if(arr[i]-prev >= m) {
			prev=arr[i];
			cnt++;
		}
	}
	if(cnt>=C) return true;
	return false;
}

int main() {

	scanf("%d %d", &N, &C);
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
		ub=max(ub,arr[i]);
	}
	sort(arr,arr+N);
	int m;
	while(lb<ub) {
		m=(lb+ub+1)/2;
		if(f(m)) lb=m;
		else ub=m-1;
	}

	printf("%d\n", ub);


	return 0;
}