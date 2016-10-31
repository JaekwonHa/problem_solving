#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int DP[1000010][2];
bool visited[1000010];
int N;
vector<int> v[1000010];

void f(int now) {
	DP[now][0]=0, DP[now][1]=1;

	visited[now]=true;
	for(int i=0; i<v[now].size(); i++) {
		int next = v[now][i];
		if(visited[next]==true) continue;
		f(next);
		DP[now][0] += DP[next][1];
		DP[now][1] += min(DP[next][0], DP[next][1]);
	}
}

int main() {
	int a,b;
	scanf("%d", &N);
	for(int i=0; i<N-1; i++) {
		scanf("%d %d", &a, &b);
		a--, b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	f(0);
	printf("%d\n", min(DP[0][0], DP[0][1]));

	return 0;
}