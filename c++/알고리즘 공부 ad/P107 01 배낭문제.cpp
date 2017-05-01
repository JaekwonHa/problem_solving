#include <stdio.h>

int n,w,wi[100], vi[100];
int DT[101][10001];

int max(int a, int b) {
	if(a>b) return a;
	return b;
}

int f(int i, int r) {
	if(DT[i][r] != 0) return DT[i][r];
	if(i==n+1) return DT[i][r]=0;
	if(wi[i] > r) return DT[i][r]=f(i+1,r);
	else return DT[i][r] = max(f(i+1,r), f(i+1,r-wi[i])+vi[i]);
}

int main() {

	scanf("%d %d", &n, &w);
	for(int i=1; i<=n; i++)
		scanf("%d %d", &wi[i], &vi[i]);

	f(1,w);

	printf("%d", DT[1][w]);

	return 0;
}