#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define INF 987654321

int N,M,arr[1010];
int DP[1010][2][1010];

int f(int num, int type, int length) {
	if(length>M) return INF;
	if(num==N) return 0;

	int &ret=DP[num][type][length];
	if(ret!=-1) return ret;

	int a,b;
	a = f(num+1,0,length+arr[num+1]+1);
	b = f(num+1,1,arr[num+1]) + (M-length)*(M-length);
	ret = min(a,b);
	return ret;
}

int main() {

	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	memset(DP,-1,sizeof(DP));
	printf("%d\n", f(0,0,arr[0]));

	return 0;
}