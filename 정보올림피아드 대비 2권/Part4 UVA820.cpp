#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string.h>
using namespace std;


#define MAXN 110


int n,s,t,rn[MAXN][MAXN],maxFlow;

/*
bool check[101];
vector<int> path;

struct vertex {
	int weight,idx;
};

int vertex_sort(const vertex& a, const vertex& b) {
	return a.weight>b.weight;
}

bool PFS(int x, int localFlow) {
	int i;
	vector<vertex> v;
	vertex vx;

	if(x==t) {
		maxFlow += localFlow;
		for(int i=0; i<path.size()-1; i++) {
			rn[path[i]][path[i+1]] -= localFlow;
			rn[path[i+1]][path[i]] += localFlow;
		}
		path.clear();
		path.push_back(s);
		return true;
	}
	for(i=1; i<=n; i++) {
		if(rn[x][i] >0 && check[i]==false) {
			vx.idx=i;
			vx.weight=rn[x][i];
			v.push_back(vx);
		}
	}
	sort(v.begin(), v.end(), vertex_sort);

	for(i=0; i<v.size(); i++) {
		check[v[i].idx]=true;
		path.push_back(v[i].idx);
		if(PFS(v[i].idx, min(localFlow, v[i].weight))==true)
			return true;
		check[v[i].idx]=false;
		path.pop_back();
	}
	return false;
}

void MaxFlow_DFS() {
	path.push_back(s);
	while(PFS(s,987654321)) {
		fill(check,check+n+1,false);
		check[s]=true;
	}
}
*/

int f[MAXN][MAXN],check[MAXN];

bool BFS() {
	int x,i,min_flow;
	deque<int> q;

	q.push_back(s);

	while(!q.empty() && check[t]==-1) {
		x = q.front();
		q.pop_front();

		for(i=1; i<=n; i++) {
			// 아직 방문하지 않은 정점이고 대역폭이 남아 있을때
			if(check[i]==-1 && f[x][i]-f[i][x] < rn[x][i]) {
				check[i]=x;
				q.push_back(i);
			}
		}
	}
	if(check[t]==-1) return false;

	min_flow = rn[check[t]][t] - (f[check[t]][t]-f[t][check[t]]);
	x = check[t];
	i = check[x];
	while(i>0) {
		min_flow=min(min_flow,rn[i][x]-(f[i][x]-f[x][i]));
		x = i;
		i = check[x];
	}

	// 경로를 돌며 최소 대역폭을 흐름량에 갱신해준다.
	x = t;
	i = check[x];
	while(i>0) {
		f[i][x]+=min_flow;
		x = i;
		i = check[x];
	}
	maxFlow+=min_flow;
	return true;
}

void MaxFlow_BFS() {
	do {
		fill(check,check+MAXN,-1);
		check[s]=-2;
	} while(BFS());
}

int main() {
	int a,b,c,d,caseCnt=1;
	while(cin>>n) {
		if(n==0) break;
		maxFlow=0;
		memset(rn,0,sizeof(rn));
		memset(f,0,sizeof(f));
		cin>>s>>t>>c;
		while(c--) {
			cin>>a>>b>>d;
			rn[a][b]+=d;
			rn[b][a]+=d;
		}
		//MaxFlow_DFS();
		MaxFlow_BFS();
		cout<<"Network "<<caseCnt++<<endl;
		cout<<"The bandwidth is "<<maxFlow<<"."<<endl<<endl;
	}
	return 0;
}

/*

4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
0

*/