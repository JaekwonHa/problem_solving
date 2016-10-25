#include <stdio.h>

int N;
int A[100010],B[100010],ans;

int max(int a, int b) { return (a>b)?a:b;}

long long f(int n) {
	if(n==1) return B[n]=A[n];

	if(B[n]==0) {
		long long a,b;
		a = A[n];
		b = f(n-1)+A[n];
		B[n]=max(a,b);
	}
	return B[n];
}

int main() {

	/*
	int temp;
	scanf("%d", &N);
	scanf("%d", &a[0]);
	b[0]=a[0];
	for(int i=1; i<N; i++) {
		scanf("%d", &temp);
		if(temp*a[i-1] > 0) {
			a[i-1] += temp;
			b[i-1] += temp;
			i--,N--;
		} else {
			a[i]=temp;
			b[i]=a[i]+b[i-1];
		}
	}
	int ans = b[0];
	for(int i=1; i<N; i++) {
		for(int j=i; j<N; j++) {
			ans = max(ans, b[j]-b[i-1]);
		}
	}
	*/

	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d", &A[i]);
	}

	ans = f(N);

	for(int i=1; i<=N; i++) {
		ans = max(ans,B[i]);
	}
	printf("%d", ans);

	return 0;
}