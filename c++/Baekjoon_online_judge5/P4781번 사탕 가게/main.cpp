#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N,M;
long long DP[11111];
int c[11111];
int p[11111];

// 전형적인 knapsack 문제 !!
// knapsack문제는 동전문제와 마찬가지로 이중for문으로 해결가능하다.
// 바깥쪽은 동전의 종류가 아니라 돈이 와야 한다.
// 또한 답을 출력할때는 0에서 M까지 중에서의 최대 가치를 출력 !!
// 하지만 소수점이 등장한다. 소수점에 100을 *할때는 반드시 +0.5 보정치를 더해줘야 한다. !!!
// 그리고 케이스가 여러개다 -> 매번 초기화를 해줘야 한다. !!!

int main() {

	while(1) {
		double tm;
		cin>>N>>tm;
		if(N==0 && tm==0.00) break;
		M = (int)(tm*100+0.5);
		for(int i=0; i<N; i++) {
			cin>>c[i]>>tm;
			p[i] = (int)(tm*100+0.5);
		}
		memset(DP,0,sizeof(DP));
		for(int i=1; i<=M; i++) {
			for(int j=0; j<N; j++) {
				if(i-p[j]>=0) {
					DP[i] = max(DP[i], DP[i-p[j]]+c[j]);
				}
			}
		}
		long long ans=0;
		for(int i=1; i<=M; i++)
			ans = max(ans, DP[i]);
		cout<<ans<<endl;
	}

	return 0;
}