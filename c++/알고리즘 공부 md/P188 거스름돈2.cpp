#include <stdio.h>

int n,m,coin[10],ans=0x7fffffff;

void solve(int money, int depth, int cnt) {

	if(money>n || depth==m)
		return;
	else if(money==n)
		if(cnt < ans) {
			ans=cnt;
			return;
		}
	for(int i=0; money+coin[depth]*i <= n; i++)
		solve(money+coin[depth]*i, depth+1, cnt+i);
}


int main() {

	scanf("%d", &n);
	scanf("%d", &m);
	for(int i=0; i<m; i++)
		scanf("%d", &coin[i]);

	solve(0,0,0);

	printf("%d", ans);


	return 0;
}