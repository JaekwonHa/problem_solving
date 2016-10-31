#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define p 1000000000

long long DP[110][10][1<<10];
int N;

int f(int length, int num, int status) {
	if(num<0 || num>9) return 0;
	if(length==N) {
		// 전체가 다 켜졌는지 확인 하는 법 !!
		if(status == (1<<10)-1) return 1;
		return 0;
	}
	long long& ret = DP[length][num][status];
	if(ret!=-1) return ret;
	ret = f(length+1, num-1, status | (1<<(num-1))) + f(length+1, num+1, status | 1<<(num+1));
	ret %= p;
	return ret;
}

int main() {
	
	scanf("%d", &N);

	long long ans=0;
	memset(DP,-1,sizeof(DP));
	for(int i=1; i<10; i++) {
		ans += f(1,i,(1<<i));
		ans %= p;
	}
	printf("%lld\n", ans);

	return 0;
}