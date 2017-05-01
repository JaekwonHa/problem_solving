#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 30001

int T,N,M,un[MAXN],uc[MAXN],a,b;

int union_find(int x) {
	vector<int> q;
	while(x != un[x]) {
		if(un[x] != un[un[x]]) q.push_back(x);
		x = un[x];
	}
	while(!q.empty()) {
		un[q.back()] = x;
		q.pop_back();
	}
	return x;
}

int main() {
	cin>>T;
	while(T--) {
		cin>>N>>M;
		for(int i=1; i<=N; i++) un[i]=i, uc[i]=1;
		for(int i=0; i<M; i++) {
			cin>>a>>b;
			int p,q;
			p = union_find(a);
			q = union_find(b);
			if(p != q) {
				if(p < q) un[p]=q,uc[q]+=uc[p];
				else un[q]=p,uc[p]+=uc[q];
			}
		}
		int ans=0;
		for(int i=1; i<=N; i++)
			ans = max(ans,uc[i]);

		cout<<ans<<endl;
	}
	return 0;
}

/*
2
3 2
1 2
2 3
10 12
1 2
3 1
3 4
5 4
3 5
4 6
5 2
2 1
7 10
1 2
9 10
8 9
*/