#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAXN 200

int N,M;
vector<int> v[MAXN+5];
int backMatch[MAXN+5];
bool visited[MAXN+5];

bool dfs(int now) {
	if(visited[now]) return false;
	visited[now] = true;
	for(int i=0; i<v[now].size(); i++) {
		int next = v[now][i];
		if(backMatch[next]==-1 || dfs(backMatch[next]) ) {
			backMatch[next]=now;
			return true;
		}
	}
	return false;
}

int BipartiteMatching() {
	memset(backMatch, -1, sizeof(backMatch));
	int matched=0;
	for(int i=1; i<=N; i++) {
		memset(visited,false,sizeof(visited));
		if(dfs(i)) matched++;
	}
	return matched;
}


int main() {

	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) {
		int n,a;
		scanf("%d", &n);
		for(int j=0; j<n; j++) {
			scanf("%d", &a);
			v[i].push_back(a);
		}
	}
	printf("%d\n", BipartiteMatching());


	return 0;
}

