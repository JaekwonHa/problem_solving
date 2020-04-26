#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string.h>
using namespace std;

#define MAXN 101

int V,E,counter,order[MAXN];
vector<int> graph[MAXN];
vector<pair<int,int> > edge;

int dfs(int A, int parent) {
	order[A]=++counter;
	int ret = order[A];
	for(int i=0; i<graph[A].size(); i++) {
		int next = graph[A][i];
		if(next == parent) continue;
		if(!order[next]) { 
			int low = dfs(next,A);
			if(low > order[A])
				edge.push_back(make_pair(min(next,A),max(next,A)));
			ret = min(ret,low);
		} else {
			ret = min(ret, order[next]);
		}
	}
	return ret;
}

int main() {

	int i,j,a,b,cnt;
	string str;
	char tp;
	while(cin>>V) {
		memset(order, 0, sizeof(order));
		for(int i=0; i<MAXN; i++)
			graph[i].clear();
		edge.clear();
		for(i=0; i<V; i++) {
		
			cin>>a>>str;
			istringstream is(str);
			is>>tp>>cnt;
			for(j=0; j<cnt; j++) {
				cin>>b;
				graph[a].push_back(b);
			}
		}

		for(int i=0; i<V; i++) {
			if(!order[i]) dfs(i,-1);
		}
		


		sort(edge.begin(),edge.end());

		cout<<edge.size()<<" critical links"<<endl;
		for(int i=0; i<edge.size(); i++) {
			cout<<edge[i].first<<" - "<<edge[i].second<<endl;
		}
		cout<<endl;
	}
	return 0;
}