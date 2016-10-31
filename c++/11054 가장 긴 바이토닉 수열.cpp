#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 1010

int N,A[MAXN],DP1[MAXN],DP2[MAXN],len1[MAXN],len2[MAXN];

int main() {

	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &A[i]);

	for(int i=0; i<N; i++) {
		len1[i]=1;
		for(int j=0; j<i; j++) {
			if(A[j]<A[i]) {
				len1[i]=max(len1[i],len1[j]+1);
			}
		}
	}

	for(int i=N-1; i>=0; i--) {
		len2[i]=1;
		for(int j=N-1; j>i; j--) {
			if(A[i]>A[j]) {
				len2[i]=max(len2[i],len2[j]+1);
			}
		}
	}
	int ans=0;
	for(int i=1; i<N; i++) {
		ans = max(ans,len1[i]+len2[i]-1);
	}
	printf("%d\n", ans);

	return 0;
}