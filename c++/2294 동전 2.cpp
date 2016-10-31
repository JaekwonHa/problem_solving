#include <stdio.h>

int N,K,coin[110];
int DT[1000000];

int MIN(int a, int b) {return a>b ? b:a; };

int f(int n) {
	if(n<=0) return 0;

	int min=0x7fffffff;
	for(int i=0; i<N; i++) {
		if(coin[i]<=n) {
			min = MIN(min, f(n-coin[i]));
		}
	}
	return min+1;
}
int f2(int n) {
	if(n<=0) return 0;

	if(DT[n]==0) {
		int min=0x7fffffff;
		for(int i=0; i<N; i++) {
			if(coin[i]<=n) {
				min = MIN(min, f(n-coin[i]));
			}
		}
		DT[n] = min+1;
	}
	return DT[n];
}
int f3(int c) {
	if(c==K) return DT[c]=0;
	if(DT[c]==0) {
		DT[c]=987654321;
		for(int i=0; i<N; i++) {
			if(c+coin[i]<=K)
				DT[c]=MIN(DT[c], f(c+coin[i]+1));
		}
	}
	return DT[c];
}

void solve() {
	for(int i=0; i<N; i++) {
		DT[coin[i]]=1;
	}
	for(int i=coin[0]; i<=K; i++) {
		if(DT[i]==0) {
			DT[i]=987654321;
			for(int j=0; j<N; j++) {
				if(i-coin[j]>0) {
					DT[i] = MIN(DT[i], DT[i-coin[j]]+1);
				}
			}
		}
	}
}

void solve2() {
	int w,i;
	for(w=1; w<=K; w++) {
		DT[w]=99999;
		for(i=0; i<N; i++) {
			if(w-coin[i]>0 && DT[w-coin[i]]==99999) {
			
			} else if(w-coin[i]>=0) {
				DT[w] = MIN(DT[w], DT[w-coin[i]]+1);
			}
		}
	}
	if(DT[K]==99999) printf("-1");
	else printf("%d", DT[K]);
}

int main() {

	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%d", &coin[i]);

	solve2();

	//solve();
	
	//if(DT[K]==0) printf("-1");
	//else printf("%d", DT[K]);

	return 0;
}