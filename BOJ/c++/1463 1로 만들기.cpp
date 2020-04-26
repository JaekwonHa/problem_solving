#include <stdio.h>
#include <string.h>


int N;
int DT[1000000];

int min(int a, int b) {
	if(a<b) return a;
	return b;}

void solve(int n, int cost) {
	if(n<1) return;
	DT[n] = min(DT[n], cost);
	
	if(n%3==0) {
		if(DT[n/3] > cost+1) {
			solve(n/3, cost+1);
		}
	}
	if(n%2==0) {
		if(DT[n/2] > cost+1) {
			solve(n/2, cost+1);
		}
	}
	if(DT[n-1] > cost+1) {
		solve(n-1, cost+1);
	}
}

int main() {

	scanf("%d", &N);
	for(int i=0; i<=N; i++) DT[i]=0x7ffffff;

	solve(N, 0);


	printf("%d", DT[1]);

	return 0;
}