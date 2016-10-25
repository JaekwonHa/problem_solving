#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define INF 987654321

int N,arr[1000];
int DP[1000][1000];

pair<int,int> getMaxMin(int left, int right) {
	pair<int,int> p;
	p.first = INF;
	for(int i=left; i<=right; i++) {
		p.first = min(p.first, arr[i]);
		p.second = max(p.second, arr[i]);
	}
	return p;
}

int f(int left, int right) {
	if(left==right) return 0;

	int& ret = DP[left][right];
	if(ret!=-1) return ret;

	pair<int,int> p = getMaxMin(left, right);
	int sum = p.second - p.first;
	for(int k=left; k<right; k++) {
		sum = max(sum, f(left,k) + f(k+1,right));
	}
	return sum;
}

int main() {

	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);

	memset(DP,-1,sizeof(DP));

	printf("%d\n", f(0,N-1));

	return 0;
}