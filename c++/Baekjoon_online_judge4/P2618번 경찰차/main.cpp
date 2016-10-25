#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int N,W,eventX[1010],eventY[1010],DP[1010][1010];
vector<int> dfs_list;
vector<int> ans_list;
int ans=0x7fffffff;

int f(int a, int b, int cost) {
	int t = max(a,b)+1;
	if(t>=W+2) {
		if(cost<ans) {
			ans=cost;
			ans_list.resize(dfs_list.size());
			copy(dfs_list.begin(), dfs_list.end(), ans_list.begin());
		}
		return 0;
	}

	int& ret = DP[a][b];
	if(ret!=-1) return ret;

	int dist1, dist2;
	dist1 = abs(eventX[a]-eventX[t])+abs(eventY[a]-eventY[t]);
	dfs_list.push_back(1);
	dist1 += f(t,b,cost+dist1);
	dfs_list.pop_back();

	dist2 = abs(eventX[b]-eventX[t])+abs(eventY[b]-eventY[t]);
	dfs_list.push_back(2);
	dist2 += f(a,t,cost+dist2);
	dfs_list.pop_back();

	ret = min(dist1, dist2);

	return ret;
}

int main() {
	memset(DP,-1,sizeof(DP));
	scanf("%d", &N);
	scanf("%d", &W);
	for(int i=2; i<W+2; i++)
		scanf("%d %d", &eventX[i], &eventY[i]);
	eventX[0]=1,eventY[0]=1;
	eventX[1]=N,eventY[1]=N;

	printf("%d\n", f(0,1,0));
	for(int i=0; i<ans_list.size(); i++)
		printf("%d\n", ans_list[i]);

	return 0;
}