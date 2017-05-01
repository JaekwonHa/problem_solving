#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct vertex {
	int weight,idx;
};

int rn[100][100];
int maxFlow,n;
bool check[100];
vector<int> path;

int vertex_sort(const vertex& a, const vertex& b) {
	return a.weight>b.weight;
}

bool PFS(int x, int localFlow) {
	int i;
	vector<vertex> v;
	vertex vx;

	if(x==n-1) {
		// DFS로 끝에 도착하면 왔던 경로들에서 flow를 업데이트 해줘야 한다.
		// MaxFlow에 현재 경로의 최소 flow를 더해준다.
		maxFlow += localFlow;
		// RN을 갱신한다.
		for(i=0; i<path.size()-1; i++) {
			rn[path[i]][path[i+1]] -= localFlow;
			rn[path[i+1]][path[i]] += localFlow;
		}
		path.clear();
		path.push_back(0);
		return true;
	}
	// 현재 정점에서 갈수있는 다음 정점의 정보를 저장
	for(i=0; i<n; i++) {
		if(rn[x][i] > 0 && check[i]==false) {
			vx.idx = i;
			vx.weight = rn[x][i];
			v.push_back(vx);
		}
	}
	// priority를 위해 weight에 따라 정렬
	sort(v.begin(), v.end(), vertex_sort);

	for(i=0; i<v.size(); i++) {
		// 다음 정점으로 선택된 것은 방문하지 않도록 체크
		check[v[i].idx] = true;
		// 경로에 그 정점을 추가
		path.push_back(v[i].idx);
		// 용량이 큰 것부터 차례대로 방문된다.
		// 하나의 경로가 처리되면 다음은 방문하지 않고 true 리턴하며 종료
		// 이전까지의 간선 용량중 최소로 갱신해간다.
		if(PFS(v[i].idx, min(localFlow, v[i].weight)) == true)
			return true;
		   
		// 체크와 경로에 대해서 복원
		path.pop_back();
		check[v[i].idx] = false;
	}
	return false;
}

void MaxFlow() {
	path.push_back(0);
	while(PFS(0,987654321)) {
		// 하나의 경로가 처리되면 check를 모두 초기화하고 다시 탐색. 경로가 없을때까지 반복
		fill(check,check+n,false);
		check[0]=true;
	}
}

int main() {
	int m,a,b,c;
	cin>>n>>m;

	while(m--) {
		cin>>a>>b>>c;
		rn[a][b]=c;
	}
	MaxFlow();

	cout<<maxFlow<<endl;

	return 0;
}

/*
6 10
0 1 14
0 3 18
1 2 15
1 3 12
2 4 9
2 5 6
3 1 6
3 4 16
4 1 11
4 5 28
*/