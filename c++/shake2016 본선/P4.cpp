#include <stdio.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

struct Hole { int xs,ys,xf,yf;};
int N,K;
int ub=2000000, lb, m;
Hole arr[5010];
double map[5010][5010];
int chk[5010];

int xa,ya,xb,yb;

int f(int m) {
	memset(chk,-1,sizeof(chk));
	std::queue<pair<int,int> > Q;
	Q.push(make_pair(xa,ya));
	while(!Q.empty()) {
		pair<int,int> T = Q.front(); Q.pop();
		if(chk[T] > K+1) return 0;
		else if(T==N+1) return 1;
		for(int i=0; i<N+2; i++) {
			if(chk[i]==-1 && map[T][i] <= m) {
				chk[i]=chk[T]+1;
				Q.push(i);
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d %d %d %d %d", &xa, &ya, &xb, &yb, &N);
	for(int i=0; i<N; i++)
		scanf("%d %d %d %d", &arr[i].xs, &arr[i].ys, &arr[i].xf, &arr[i].yf);

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(i==j) continue;
			map[i][j] = abs(arr[i].xf-arr[j].xf) + abs(arr[i].yf-arr[j].yf);
		}
	}

	while(lb<ub) {
		memset(chk,0,sizeof(chk));
		m = (lb+ub-1)/2;
		if(f(m)) ub=m;
		else lb=m+1;
	}

	printf("%.f\n", ceil((double)ub/10));
	return 0;
}