#include <stdio.h>
#include <math.h>

int n,k,ans=0x7fffffff;
int x[1002], y[1002];
int visited[10];

int max(int a, int b) {
	if(a>b) return a;
	return b;
}
int min(int a, int b) {
	if(a<b) return a;
	return b;
}

double dis(int pos1, int pos2) {
	return (double)pow(x[pos1]-x[pos2],(double)2) + (double)pow(y[pos1]-y[pos2],(double)2);
}

int fuel(int a) {
	if(a%10==0) return a/10;
	return (a/10 + 1);
}

void solve(int pos, int charge, int cost) {
	visited[pos]=1;
	int temp = dis(pos, 1);
	if(temp >= ans || charge>k+1)
		return;

	if(pos==1) {
		if(cost < ans) {
			ans = cost;
		}
		return;
	}
	
	for(int i=1; i<n+2; i++) {
		if(!visited[i] && pos!=i && (x[pos] <= x[i] || y[pos] <= y[i])) {
			solve(i, charge+1, max(cost, dis(pos, i)));
			visited[i]=0;
		}
	}
}

void solve2(int pos, int charge, int cost) {

	if(cost >= ans)
		return;

	if(charge==k) {
		cost = max(cost, dis(pos,1));
		ans = min(cost, ans);
		return;
	}

	if(pos==1) {
		ans = min(cost, ans);
		visited[1]=0;
		return;
	}

	for(int i=1; i<n+2; i++) {
		if(visited[i]==0 && pos != i) {
			visited[i]=1;
			solve2(i, charge+1, max(cost, dis(pos,i)));
			visited[i]=0;
		}
	}
}

int main() {

	scanf("%d %d", &n, &k);
	for(int i=2; i<n+2; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	x[0]=0, y[0]=0, x[1]=10000, y[1]=10000;
	solve2(0, 0, 0);

	//printf("%d", fuel(ans));
	printf("%.f\n", ceil(sqrt((double)ans)/10));

	return 0;
}