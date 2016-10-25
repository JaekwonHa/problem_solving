#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define MAXN 1000

int N,M;
int map[2*MAXN+5][2*MAXN+5];
bool visited[2*MAXN+5];

bool dfs(int now) {
	if(now==N+M+1) return true;
	visited[now]=true;
	bool b = false;
	for(int i=1; i<=N+M+1; i++) {
		if(map[now][i]>0 && !visited[i]) {
			visited[i]=true;
			b = dfs(i);
			if(b) {
				map[now][i]--, map[i][now]++;
				break;
			}
		}
	}
	return b;
}

int BipartiteMatching() {
	int cnt=0;
	while(1) {
		memset(visited,false,sizeof(visited));
		if(dfs(0)) cnt++;
		else break;
	}
	return cnt;
}

int main() {
	scanf("%d %d", &N, &M);
	int n,a;
	for(int i=1; i<=N; i++) {
		scanf("%d", &n);
		map[0][i]=2;
		for(int j=0; j<n; j++) {
			scanf("%d", &a);
			map[i][N+a]=1;
		}
	}
	for(int i=1; i<=M; i++) {
		map[N+i][N+M+1]=1;
	}
	printf("%d\n", BipartiteMatching());
	return 0;
}