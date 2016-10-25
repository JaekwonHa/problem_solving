#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define RIGHT 0
#define LEFT 1
#define INF 987654321

int N,M;
int DP[1010][1010][2];
int D[1010],W[1010];

int getWaste(int left, int right, int start, int end) {
	//if(start==0 || start >N) return INF;
	//if(end==0 || end >N) return INF;

	int time=abs(D[start]-D[end]);
	int ret=0;
	for(int i=1; i<=left; i++) {
		ret += time*W[i];
	}
	for(int i=0; i<right; i++) {
		ret += time*W[N-i];
	}
	return ret;
}

int f(int left, int right, int side) {
	if(left<0 || right<0) return INF;

	int &ret = DP[left][right][side];
	if(ret != -1) return ret;
	
	ret=0;
	if(left+right==0) {
		return ret;
	} else {
		if(side==RIGHT) {
			ret = min(f(left-1,right,LEFT)+getWaste(left,right,N-right,left), f(left,right-1,RIGHT)+getWaste(left,right,N-right+1,N-right));
		} else {
			ret = min(f(left-1,right,LEFT)+getWaste(left,right,left+1,left), f(left,right-1,RIGHT)+getWaste(left,right,N-right+1,left+1));
		}
	}
	return ret;
}

int solve() {
	//return min(f(M-1,N-M,LEFT)+getWaste(M-1,N-M,M,M-1), f(M-1,N-M,RIGHT)+getWaste(M-1,N-M,M+1,M));
	return min(f(M-1,N-M,LEFT), f(M-1,N-M,RIGHT));
}

int main() {
	memset(DP,-1,sizeof(DP));

	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++)
		scanf("%d %d", &D[i], &W[i]);

	printf("%d\n",solve());

	return 0;
}