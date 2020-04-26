#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N,coin[300010],DP[300010];

int f(int n) {

	int i,sum=4;
	coin[0]=0,coin[1]=1,coin[2]=4;
	for(i=3; sum<=n; i++) {
		sum = sum + (coin[i-1]-coin[i-2]+i);
		coin[i]=sum;
	}
	i--;
	DP[0]=0;
	for(int w=1; w<=n; w++) {
		DP[w]=987654321;
		for(int j=1; j<=i; j++) {
			if(w-coin[j]<0) {

			} else {
				DP[w] = min(DP[w],DP[w-coin[j]]+1);
			}
		}
	}
	return DP[n];
}

int main() {

	scanf("%d", &N);

	printf("%d\n", f(N));

	return 0;
}