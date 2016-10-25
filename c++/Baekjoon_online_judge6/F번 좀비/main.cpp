#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

int N,M,K,S;
int p,q;
int k[100010];
vector<int> v[100010];
int ans=INF;

struct Point {
	int v;
	int cost;
};

int main() {

	scanf("%d %d %d %d", &N, &M, &K, &S);
	scanf("%d %d", &p, &q);

	int a,b;
	for(int i=0; i<K; i++) {
		scanf("%d", &a);
		k[a]=2;
	}
	for(int i=0; i<M; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1; i<=N; i++) {
		if(k[i]!=2) continue;
		for(int j=0; j<v[i].size(); j++) {
			k[v[i][j]]=1;
		}
	}

	queue<Point> que;
	Point point;
	point.v=1;
	point.cost=0;
	que.push(point);
	while(!que.empty()) {
		point = que.front();
		que.pop();
		if(point.v==N) {
			ans = min(ans,point.cost);
			continue;
		} else {
			for(int i=0; i<v[point.v].size(); i++) {
				if(k[v[point.v][i]]==2) continue;
				Point temp;
				temp.v = v[point.v][i];
				int cost;
				if(k[v[point.v][i]]==1) cost=p;
				else cost = q;
				temp.cost = point.cost + cost;
				que.push(temp);
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}