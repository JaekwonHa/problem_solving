#include <stdio.h>

int n, ans;

void solve(int a) {

	if(a>n) {
		return;
	} else if(a==n) {
		ans++;
		return;
	}
	solve(a+1);
	solve(a+2);
}

int main() {

	scanf("%d", &n);

	solve(0);

	printf("%d", ans);

	return 0;

}