#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN 100010

int V,E,A,B,order[MAXN],counter;
std::vector<int> graph[MAXN];
std::vector<std::pair<int,int> > edge;

int dfs(int A, int parent) {

	order[A]=++counter;
	int ret = order[A];
	for(int i=0; i<graph[A].size(); i++) {
		int next = graph[A][i];
		if(next==parent) continue;
		if(!order[next]) {
			int low = dfs(next,A);
			if(low>order[A])
				edge.push_back(std::make_pair(std::min(A,next),std::max(A,next)));
			ret = std::min(ret, low);
		} else {
			ret = std::min(ret,order[next]);
		}
	}
	return ret;
}

int main() {

	scanf("%d %d", &V, &E);
	int a,b;
	for(int i=0; i<E; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1,0);

	std::sort(edge.begin(),edge.end());
	printf("%d\n", edge.size());
	for(int i=0; i<edge.size(); i++)
		printf("%d %d\n",edge[i].first,edge[i].second);


	return 0;
}