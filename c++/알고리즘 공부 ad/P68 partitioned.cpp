#include <stdio.h>

int a[30], cnt;

int min(int a, int b) {
	return a>b ? b:a;
}
void solve(int n, int k) {
	if(n==0) {
		for(int i=0; i<cnt; i++)
			printf("%d ", a[i]);
		puts("");
		return;
	}
	for(int i=min(n,k); i>=1; i--) {
		a[cnt++]=i;
		solve(n-i,i);
		cnt--;
	}
}


int main() {

	int n;
	scanf("%d", &n);

	solve(n,n);

	return 0;
}