#include <stdio.h>
#include <math.h>
#include <string.h>
#include <queue>

struct Point { int x,y;};
int N,K;
int ub=15000, lb, m;
Point arr[1010];
double map[1010][1010];
int chk[1010];

int abs(int a) { return (a<0)?-a:a;}
double distance(Point i, Point j) {
	return sqrt((double)(i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y));
}

int f(int m) {
	memset(chk,-1,sizeof(chk));
	std::queue<int> Q;
	Q.push(0), chk[0]=0;
	while(!Q.empty()) {
		int T = Q.front(); Q.pop();
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
	scanf("%d %d", &N, &K);
	for(int i=1; i<N+1; i++)
		scanf("%d %d", &arr[i].x, &arr[i].y);
	arr[0].x=0, arr[0].y=0;
	arr[N+1].x=10000, arr[N+1].y=10000;

	for(int i=0; i<N+2; i++) {
		for(int j=0; j<N+2; j++) {
			if(i==j) continue;
			map[i][j] = distance(arr[i], arr[j]);
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