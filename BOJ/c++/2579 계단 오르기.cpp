#include <stdio.h>
#include <string.h>

#define MAX 987654321

int N, floor[310];
long long DT[310], ans;

int max(int a, int b) {
	if(a>b) return a;
	return b;
}

int f(int n, int k) {
	if(n<0) return 0;

	if(k<2) {
		int score1, score2;
		score1 = f(n-1,k+1);
		score2 = f(n-2,1);
		return floor[n] + max(score1, score2);
	} else {
		int score2;
		score2 = f(n-2,1);
		return floor[n] + score2;
	}
}

void f2(int n, int k, int cost) {
	if(N<n) return;

	DT[n]=max(cost, DT[n]);
	if(k<2) {
		f2(n+1,k+1, cost+floor[n+1]);
		f2(n+2,1, cost+floor[n+2]);
	} else {
		f2(n+2,1, cost+floor[n+2]);
	}
}
int f3(int n, int k) {
	if(n<=0) return 0;

	int ret=DT[n];

	if(DT[n]!=-1) return DT[n];

	if(k==2) {
		ret = f3(n-2,1)+floor[n];
	} else {
		int a = f3(n-1,k+1)+floor[n];
		int b = f3(n-2,1)+floor[n];
		ret = max(a,b);
	}
	return DT[n]=ret;
}

long long f4(int n) {
	DT[1]=floor[1];
	DT[2]=floor[1]+floor[2];
	DT[3]=max(floor[1],floor[2])+floor[3];
	DT[4]=max(floor[1]+floor[2],floor[1]+floor[3])+floor[4];

	for(int i=5; i<=N; i++) {
		DT[i]=max(floor[i-1]+DT[i-3],DT[i-2])+floor[i];
	}
	return DT[n];
}

int main() {
	memset(DT,-1,sizeof(DT));

	scanf("%d", &N);
	for(int i=1; i<=N; i++)
		scanf("%d", &floor[i]);

	//ans = max(f(N-1,1), f(N-2,1));
	//f2(0,0,0);
	//ans = DT[N];

	printf("%lld", f4(N));


	return 0;
}