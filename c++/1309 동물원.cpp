#include <iostream>
#include <algorithm>
using namespace std;
#define p 9901

int N,DP[100100][3];

int f(int n) {
	DP[0][0]=1;
	for(int i=1; i<=n; i++) {
		int no,left,right;
		no = DP[i-1][0];
		left = DP[i-1][1];
		right = DP[i-1][2];
		DP[i][0] = (no+left+right)%p;
		DP[i][1] = (no+right)%p;
		DP[i][2] = (no+left)%p;
	}
	return (DP[n][0]+DP[n][1]+DP[n][2])%p;
}

int main() {

	scanf("%d", &N);
	printf("%d", f(N));

	return 0;
}