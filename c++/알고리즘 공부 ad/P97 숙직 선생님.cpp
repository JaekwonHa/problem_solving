#include <stdio.h>

int a,b,ans=0x7fffffff;
int step[3], DT[1000];

void f(int x, int cost) {
	if(x>b || cost > ans) return;
	
	if(x==b) {
		if(cost < ans)
			ans = cost;
		return;
	}
	if(DT[x+step[2]]==0 || DT[x+step[2]] > cost+1) {
		DT[x+step[2]] = cost+1;
		f(x+step[2], cost+1);
	}
	if(DT[x+step[1]]==0 || DT[x+step[1]] > cost+1) {
		DT[x+step[1]] = cost+1;
		f(x+step[1], cost+1);
	}
	if(DT[x+step[0]]==0 || DT[x+step[2]] > cost+1) {
		DT[x+step[0]] = cost+1;
		f(x+step[0], cost+1);
	}
}

int main() {

	scanf("%d %d", &a, &b);
	for(int i=0; i<3; i++)
		scanf("%d", &step[i]);

	f(a,0);

	if(ans>0)
		printf("%d", ans);
	else
		printf("%d", -1);

	return 0;
}