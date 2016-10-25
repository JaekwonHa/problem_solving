#include <iostream>
#include <vector>
using namespace std;

#define MAXN 50001

int n,m,un[MAXN],uc;


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
	int p,q,a,b,T=1;
	while(1) {
		cin>>n>>m;
		if(n==0 && m==0) break;
		for(int i=1; i<=n; i++) un[i]=i;
		uc=n;
		for(int i=0; i<m; i++) {
			cin>>a>>b;
			p  = union_find(a);
			q  = union_find(b);
			if(p!=q) {
				uc--;
				if(p<q) un[q]=p;
				else un[p]=q;
			}
		}
		
		cout<<"Case "<<T++<<": "<<uc<<endl;
	}

	return 0;
}


/*
10 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
10 4
2 3
4 5
4 8
5 8
0 0
*/