#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int N, pos_x[100010], pos_y[100010];
long long DP[100010][5];

long long getCost(int x1, int y1, int x2, int y2) {
	//if(x1<0 || y1>100000 || x2<0 || y2>100000) return INF;
	return abs(x1-x2) + abs(y1-y2);
}

void solve() {
	DP[1][0] = getCost(pos_x[0], pos_y[0], pos_x[1], pos_y[1]);
	DP[1][1] = getCost(pos_x[0], pos_y[0], pos_x[1]-1, pos_y[1]);
	DP[1][2] = getCost(pos_x[0], pos_y[0], pos_x[1]+1, pos_y[1]);
	DP[1][3] = getCost(pos_x[0], pos_y[0], pos_x[1], pos_y[1]-1);
	DP[1][4] = getCost(pos_x[0], pos_y[0], pos_x[1], pos_y[1]+1);

	for(int i=2; i<=N; i++) {
		long long cost;

		cost = DP[i-1][0]+getCost(pos_x[i-1], pos_y[i-1], pos_x[i], pos_y[i]);
		cost = min(cost, DP[i-1][1]+getCost(pos_x[i-1]-1, pos_y[i-1], pos_x[i], pos_y[i]));
		cost = min(cost, DP[i-1][2]+getCost(pos_x[i-1]+1, pos_y[i-1], pos_x[i], pos_y[i]));
		cost = min(cost, DP[i-1][3]+getCost(pos_x[i-1], pos_y[i-1]-1, pos_x[i], pos_y[i]));
		cost = min(cost, DP[i-1][4]+getCost(pos_x[i-1], pos_y[i-1]+1, pos_x[i], pos_y[i]));
		DP[i][0] = cost;

		cost = DP[i-1][0]+getCost(pos_x[i-1], pos_y[i-1], pos_x[i]-1, pos_y[i]);
		cost = min(cost, DP[i-1][1]+getCost(pos_x[i-1]-1, pos_y[i-1], pos_x[i]-1, pos_y[i]));
		cost = min(cost, DP[i-1][2]+getCost(pos_x[i-1]+1, pos_y[i-1], pos_x[i]-1, pos_y[i]));
		cost = min(cost, DP[i-1][3]+getCost(pos_x[i-1], pos_y[i-1]-1, pos_x[i]-1, pos_y[i]));
		cost = min(cost, DP[i-1][4]+getCost(pos_x[i-1], pos_y[i-1]+1, pos_x[i]-1, pos_y[i]));
		DP[i][1] = cost;
		
		cost = DP[i-1][0]+getCost(pos_x[i-1], pos_y[i-1], pos_x[i]+1, pos_y[i]);
		cost = min(cost, DP[i-1][1]+getCost(pos_x[i-1]-1, pos_y[i-1], pos_x[i]+1, pos_y[i]));
		cost = min(cost, DP[i-1][2]+getCost(pos_x[i-1]+1, pos_y[i-1], pos_x[i]+1, pos_y[i]));
		cost = min(cost, DP[i-1][3]+getCost(pos_x[i-1], pos_y[i-1]-1, pos_x[i]+1, pos_y[i]));
		cost = min(cost, DP[i-1][4]+getCost(pos_x[i-1], pos_y[i-1]+1, pos_x[i]+1, pos_y[i]));
		DP[i][2] = cost;

		cost = DP[i-1][0]+getCost(pos_x[i-1], pos_y[i-1], pos_x[i], pos_y[i]-1);
		cost = min(cost, DP[i-1][1]+getCost(pos_x[i-1]-1, pos_y[i-1], pos_x[i], pos_y[i]-1));
		cost = min(cost, DP[i-1][2]+getCost(pos_x[i-1]+1, pos_y[i-1], pos_x[i], pos_y[i]-1));
		cost = min(cost, DP[i-1][3]+getCost(pos_x[i-1], pos_y[i-1]-1, pos_x[i], pos_y[i]-1));
		cost = min(cost, DP[i-1][4]+getCost(pos_x[i-1], pos_y[i-1]+1, pos_x[i], pos_y[i]-1));
		DP[i][3] = cost;

		cost = DP[i-1][0]+getCost(pos_x[i-1], pos_y[i-1], pos_x[i], pos_y[i]+1);
		cost = min(cost, DP[i-1][1]+getCost(pos_x[i-1]-1, pos_y[i-1], pos_x[i], pos_y[i]+1));
		cost = min(cost, DP[i-1][2]+getCost(pos_x[i-1]+1, pos_y[i-1], pos_x[i], pos_y[i]+1));
		cost = min(cost, DP[i-1][3]+getCost(pos_x[i-1], pos_y[i-1]-1, pos_x[i], pos_y[i]+1));
		cost = min(cost, DP[i-1][4]+getCost(pos_x[i-1], pos_y[i-1]+1, pos_x[i], pos_y[i]+1));
		DP[i][4] = cost;
	}

}

int main() {

	scanf("%d", &N);
	for(int i=0; i<=N; i++) scanf("%d %d", &pos_x[i], &pos_y[i]);

	solve();
	
	long long ans=DP[N][0];
	ans = min(ans,DP[N][1]);
	ans = min(ans,DP[N][2]);
	ans = min(ans,DP[N][3]);
	ans = min(ans,DP[N][4]);
	printf("%lld\n", ans);

	return 0;
}