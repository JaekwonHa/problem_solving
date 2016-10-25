#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 110

int N,S,M,P[MAXN],DP[MAXN][1010];

// x번째노래부터 초기볼륨 s로 끝까지 갔을때 가능한 최대 볼륨
// 이런문제는 상태트리 그려보고 DFS로 끝까지 간뒤 돌아오면서 메모제이션 하는 형태로
// 같은 길로 탐색하지 않도록 하는 방법으로 풀면 된다.

int f(int x, int s) {
	if(x>N) return s;
	int ret = DP[x][s];
	if(ret==-2) {
		DP[x][s]=-1;
		if(s+P[x]<=M) DP[x][s]=max(DP[x][s],f(x+1,s+P[x]));
		if(s-P[x]>=0) DP[x][s]=max(DP[x][s],f(x+1,s-P[x]));
		ret = DP[x][s];
	}
	return ret;
}


int main() {
	scanf("%d %d %d", &N, &S, &M);
	for(int i=1; i<=N; i++) scanf("%d", &P[i]);
	
	for(int i=0; i<=N; i++) fill(DP[i],DP[i]+M+1,-2);
	printf("%d\n", f(1,S));

	return 0;
}