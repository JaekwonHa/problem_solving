#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int DP[1000010][2];
int degree[1000010];
bool visited[1000010];
int N;
vector<int> v[1000010];

int main() {
	int a,b;
	scanf("%d", &N);
	for(int i=0; i<N-1; i++) {
		scanf("%d %d", &a, &b);
		a--, b--;
		v[a].push_back(b);
		v[b].push_back(a);
		degree[a]++, degree[b]++;
	}
	queue<int> q;
	for(int i=0; i<N; i++) DP[i][1]=1;
	int root=-1;
	for(int i=0; i<N; i++) {
		if(degree[i]==1) {
			q.push(i);
			root = i;
		}
	}
	while(!q.empty()) {
		int now = q.front(); q.pop();
		visited[now] = true;
		for(int i=0; i<v[now].size(); i++) {
			int next = v[now][i];
			if(visited[next]) continue;
			DP[next][0] += DP[now][1];
			DP[next][1] += min(DP[now][0], DP[now][1]);
			degree[next]--;
			if(degree[next]==1) {
				q.push(next);
				root = next;
			}
		}
	}
	printf("%d\n", min(DP[root][0], DP[root][1]));

	return 0;
}