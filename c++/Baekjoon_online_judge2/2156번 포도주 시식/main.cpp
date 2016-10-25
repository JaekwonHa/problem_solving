#include <stdio.h>

int N;
long long arr[10000],DT[100000];

int max(int a, int b) {
	if(a>b) return a;
	return b;
}

int max3(int a, int b, int c) {
	if(a>b && a>c) return a;
	if(b>a && b>c) return b;
	return c;
}

long long f(int n) {
	DT[0]=arr[0];
	DT[1]=arr[0]+arr[1];
	DT[2]=max(arr[0]+arr[1],arr[1]+arr[2]);
	DT[2]=max(DT[2],arr[0]+arr[2]);
	for(int i=3; i<n; i++) {
		DT[i] = max(DT[i-1],DT[i-2]+arr[i]);
		DT[i] = max(DT[i],DT[i-3]+arr[i-1]+arr[i]);
	}
	return DT[n-1];
}

int main() {

	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	printf("%lld", f(N));


	return 0;
}