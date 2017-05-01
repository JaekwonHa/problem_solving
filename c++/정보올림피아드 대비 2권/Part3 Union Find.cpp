#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int un[100];
int n;

/*
6 4
3 2
1 3
5 4
3 5
*/

int union_find(int x) {
	vector<int> q;

	//집합 번호와 같은 원소가 아닌 동안 최종 집합을 찾아간다.
	while(un[x] != x) {
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

	int m,i,a,b,p,q,uc;
	bool prn[100];
	cin>>n>>m;
	// 처음에는 집합개수가 원소의 개수와 같다.
	uc=n;
	// 제일 처음에는 각자의 원소를 하나씩 갖는 집합으로 구성한다.
	for(i=1; i<=n; i++) un[i]=i;

	while(m--) {
		cin>>a>>b;
		p = union_find(a);
		q = union_find(b);
		if(p != q) {
			if(p<q) un[q]=p;
			else un[p]=q;
			uc--;
		}
	}
	cout<<uc<<endl;

	return 0;
}