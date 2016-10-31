#include <stdio.h>
#include <string.h>

int N,powArr[401],DT[100001];

int min(int a, int b) { return (a<b)?a:b;}

void init(int n) {
	for(int i=1; i<=N*2 || i<=400; i++) {
		powArr[i]=i*i;
	}
}

int f(int n, int x, int cost) {
	if(n==N) {
		if(DT[n] > cost)
			DT[n]=cost;
		return DT[n]; 
	}
	if(DT[n]!=0 && DT[n]<cost) return DT[n];
	int ret=0x7fffffff;
	for(int i=x; n+powArr[i]<=N; i++) {
		ret = min(ret, f(n+powArr[i], i, cost+1));
	}
	return DT[n]=ret;
}

void solve() {
	for(int w=1; w<=N; w++) {
		DT[w]=0x7fffffff;
		for(int i=1; powArr[i]<=N; i++) {
			if(w-powArr[i] < 0){

			} else {
				DT[w] = min(DT[w], DT[w-powArr[i]]+1);
			}
		}
	}
}

int main() {

	scanf("%d", &N);
	
	init();

	//DT[N]=0x7fffffff;
	//if(N==1) printf("%d", 1);
	//else printf("%d", f(0,1,0));

	solve();
	printf("%d", DT[N]);

	return 0;
}