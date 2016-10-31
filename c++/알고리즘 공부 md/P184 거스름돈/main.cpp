#include <stdio.h>

int n,m,coin[10],ans=0x7fffffff;

void solve(int money, int cnt) {

	if(money>n || money>ans)
		return;
	else if(money==n) {
		if(cnt < ans )
			ans = cnt;
	}
	
	for(int i=m-1; i>=0; i--)
		solve(money + coin[i], cnt+1);
}

int main() {

	scanf("%d", &n);
	scanf("%d", &m);
	for(int i=0; i<m; i++)
		scanf("%d", &coin[i]);

	solve(0,0);

	printf("%d", ans);


	return 0;
}