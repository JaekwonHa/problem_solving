#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAXN 2000

int N,M;
vector<int> v[MAXN+5];
int backMatch[MAXN+5];
bool visited[MAXN+5];

bool dfs(int now) {
	if(visited[now]) return false;
	visited[now]=true;
	for(int i=0; i<v[now].size(); i++) {
		int next = v[now][i];
		if(backMatch[next]==-1 || dfs(backMatch[next])) {
			backMatch[next]=now;
			return true;
		}
	}
	return false;
}

int BipartiteMatching() {
	int ans=0;
	memset(backMatch,-1,sizeof(backMatch));
	for(int i=1; i<=N; i++) {
		memset(visited,false,sizeof(visited));
		if(dfs(i))  ans++;
	}
	return ans;
}

int main() {

	scanf("%d %d", &N, &M);
	int n,a;
	for(int i=1; i<=N; i++) {
		scanf("%d", &n);
		for(int j=0; j<n; j++) {
			scanf("%d", &a);
			v[i].push_back(a);
		}
	}

	printf("%d", BipartiteMatching());
	return 0;
}