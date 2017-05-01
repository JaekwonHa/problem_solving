#include <stdio.h>
#include <algorithm>

int n,w,wi[100],vi[100],dp[100001];

/* 이것은 물건의 개수가 무한할때 !!
void f() {
	for(int i=1; i<=w; i++) {
		dp[i] = dp[i-1];
		for(int j=n-1; j>=0; j--) {
			if(wi[j] <= i) {
				dp[i] = std::max(dp[i],dp[i-wi[j]]+vi[j]); 
			}
		}
	}
}
*/

int f(int i, int r) {
	if(i>n)
		return 0;
	if(wi[i] > r)
		return f(i+1, r);
	return std::max( f(i+1,r), f(i+1,r-wi[i])+vi[i]);
}


int main() {

	scanf("%d %d", &n, &w);
	for(int i=0; i<n; i++)
		scanf("%d %d", &wi[i], &vi[i]);

	//printf("%d", f(n-1, w);
	//f();

	//printf("%d", dp[w]);

	printf("%d", f(0,w));

	return 0;
}