#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int T,N,arr[100010];
bool visited[100010];
int ans[100010];
int cnt;

void dfs(int start, int now) {
	if(ans[now]==1) return;
	if(start==now) {
		for(int i=1; i<=N; i++) {
			if(ans[i]==2) continue;
			if(visited[i]) {
				ans[i]=2;
				cnt--;
			}
		}
		return;
	}
	if(visited[arr[now]]) {
		return;
	}
	visited[arr[now]]=true;
	dfs(start,arr[now]);
	visited[arr[now]]=false;
	return;
}

int dfs2(int start, int now) {
	if(start==now) return 2;
	if(visited[now]==true) return 0;
	if(ans[now]==1) return 1;
	visited[now]=true;
	ans[now] = dfs2(start,arr[now]);
	visited[now]=false;
	return ans[now];
}

int main() {

	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i=1; i<=N; i++) {
			scanf("%d", &arr[i]);
		}
		memset(ans,0,sizeof(ans));
		cnt=N;
		for(int i=1; i<=N; i++) {
			if(ans[i]==2) continue;
			memset(visited,false,sizeof(visited));
			visited[arr[i]]=true;
			dfs(i, arr[i]);
			//if(ans[i]!=2) ans[i]=1;
		}
		/*
		for(int i=1; i<=N; i++) {
			if(ans[i]==0) {
				ans[i] = dfs2(i, arr[i]);
			}
		}
		for(int i=1; i<=N; i++) {
			if(ans[i]==2) cnt--;
		}
		*/
		printf("%d\n", cnt);
	}

	return 0;
}