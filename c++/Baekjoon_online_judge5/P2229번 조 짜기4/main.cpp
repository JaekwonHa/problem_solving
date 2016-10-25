#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define INF 987654321

int N,arr[1010];
int DP[1010];

int main() {

	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &arr[i]);

	
	for(int i=2; i<=N; i++) {
		int mini=arr[i], maxi=arr[i];
		for(int j=i; j>0; j--) {
			mini = min(mini, arr[j]);
			maxi = max(maxi, arr[j]);
			DP[i] = max(DP[i], DP[j-1]+maxi-mini);
		}
	}

	printf("%d\n", DP[N]);

	return 0;
}