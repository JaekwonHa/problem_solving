#include <stdio.h>
#include <algorithm>

int D,N,M;
int arr[50002];
int ub=1000000000, lb,L;

int max(int a, int b) { return a>b?a:b;}

bool f(int d) {
	int cu=arr[0],cnt=0;
	for(int i=1; i<N+2; i++) {
		if(arr[i]-cu < d) cnt++;
		else cu = arr[i];
	}
	return cnt<=M && cu==D;
}

int main() {
	scanf("%d %d %d", &D, &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);
	arr[N]=0, arr[N+1]=D;
	std::sort(arr, arr+N+2);

	int cnt=0;
	while(lb<ub) {
		L = (lb+ub+1)/2;
		if(f(L)) lb=L;
		else ub=L-1;
	}

	printf("%d", ub);

	return 0;
}