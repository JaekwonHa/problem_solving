#include <stdio.h>
#include <vector>

int n,w,wx[1002],wy[1002],ans=0x7fffffff;
std::vector<int> ans_list;
std::vector<int> dfs_list;

int car1X, car1Y, car2X, car2Y;

int abs(int x) {
	if(x<0) return -x;
	return x;
}

void solve(int num, int cost) {
	if(num == n) {
		ans = 2*cost;
		return;
	}
	int dis1 = abs(wx[num] - car1X) + abs(wy[num] - car1Y);
	int dis2 = abs(wx[num] - car2X) + abs(wy[num] - car2Y);
	if( dis1 < dis2 ) {
		car1X = wx[num], car1Y = wy[num];
		solve(num+1, cost+dis1);
	} else {
		car2X = wx[num], car2Y = wy[num];
		solve(num+1, cost+dis2);
	}
}


int dis(int a, int b) {
	return abs(wx[a]-wx[b]) + abs(wy[a]-wy[b]);
}

void f(int car1, int car2, int cost) {

	if(cost > ans) {
		return;
	}
	
	if(car1 >= w+1 || car2 >= w+1) {
		if(cost <= ans) {
			ans_list.resize(dfs_list.size());
			std::copy(dfs_list.begin(), dfs_list.end(), ans_list.begin());
			ans = cost;
		}
		return;
	}
	int next = ((car1 > car2) ? car1:car2)+1;
	dfs_list.push_back(1);
	f(next, car2, cost + dis(car1,next));
	dfs_list.pop_back();
	dfs_list.push_back(2);
	f(car1, next, cost + dis(car2,next));
	dfs_list.pop_back();
}

int main() {

	scanf("%d", &n);
	scanf("%d", &w);

	wx[0] = 1, wy[0] = 1;
	wx[1] = n, wy[1] = n;
	car1X = 1, car1Y = 1, car2X = n, car2Y = n;
	for(int i=2; i<w+2; i++)
		scanf("%d %d", &wx[i], &wy[i]);
	

	solve(0, 0);
	f(0,1,0);

	printf("%d\n", ans);

	for(int i=0; i<ans_list.size(); i++) {
		printf("%d\n", ans_list[i]);
	}

	return 0;
}