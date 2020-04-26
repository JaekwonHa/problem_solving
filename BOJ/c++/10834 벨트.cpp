#include <stdio.h>

int N,A[1001],B[1001],C[1001];
int ans1,ans2;

void solve(int n) {
	ans1=1, ans2=0;
	for(int i=0; i<n; i++) {
		if(A[i]==1) ans1*=B[i];
		else {
			ans1/=A[i];
			ans1*=B[i];
		}
		if(C[i]==1) ans2=!ans2;
	}
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d %d %d", &A[i], &B[i], &C[i]);

	solve(N);

	printf("%d %d", ans2, ans1);
	return 0;
}