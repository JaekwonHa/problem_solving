#include <iostream>
#include <algorithm>
using namespace std;

int N,m,arr[50010],DP[3][50010];

// DP 레벨업하는법 !
// 보통 DP[i] 라고 하면 i부터의 최대값? 이런식으로 생각하는데 그러지말고
// DP[i]까지의 최적해.라고 생각하자
// 그럼 그 이후의 열차를 구할때 그 이전의 열차가 i까지의 최적해가 있기 때문에 가져다쓰면 된다.

void solve() {
	DP[0][0]=DP[1][0]=DP[2][0]=0;

	for(int i=0; i<3; i++) {
		for(int j=(i+1)*m-1; j<N; j++) {
			if(i==0) {
				DP[i][j]=max(DP[i][j-1],arr[j]-arr[j-m]);
			} else {
				DP[i][j]=max(DP[i][j-1], DP[i-1][j-m]+arr[j]-arr[j-m]);
			}
		}
	}
}

int main() {
	int a;
	scanf("%d", &N);
	scanf("%d", &arr[0]);
	for(int i=1; i<N; i++) {
		scanf("%d", &a);
		arr[i]=arr[i-1]+a;
	}
	scanf("%d", &m);

	solve();

	printf("%d\n", DP[2][N-1]);

	return 0;
}