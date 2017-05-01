#include <stdio.h>

int B, n, money[21], check[21], ans;

void solve(int a, int cost) {
	if(cost>B || a==n)
		return;
	if(cost > ans)
		ans = cost;
	solve(a+1, cost);
	solve(a+1, cost+money[a]);
}

int main() {

	scanf("%d", &B);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &money[i]);

	solve(0,0);

	printf("%d", ans);

	return 0;

}