#include <stdio.h>
#include <vector>

int n,m,coloring[200];
std::vector<int> map[200];

void solve(int node, int color) {
	coloring[node] = color;
	int can=1;
	for(int i=0; i<map[node].size(); i++)
		if( coloring[map[node][i]] == color ) can=0;
	if(!can) {
		coloring[node] = 0;
		return;
	}
	for(int i=0; i<map[node].size(); i++) {
		if(!coloring[map[node][i]]) {
			solve(map[node][i], 1);
			solve(map[node][i], 2);
		}
	}
}

int main() {

	int a,b;
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}

	solve(0, 1);
	//m_coloring(0);

	int ans=1;
	for(int i=0; i<n; i++)
		if(coloring[i]==0) ans=0;
	(ans==0) ? puts("IMPOSSIBLE") : printf("OK");

	return 0;
}