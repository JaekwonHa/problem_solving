#include <stdio.h>

int n, ans;

void solve() {
	int a,b,c;
	for(a=1; a<=n; a++)
		for(b=a; b<=n; b++) {
			c = n-a-b;
			if(b > c) break;
			if(a+b>c)
				ans++;
		}
}

int main() {
	
	scanf("%d", &n);

	solve();

	printf("%d", ans);

	return 0;
}