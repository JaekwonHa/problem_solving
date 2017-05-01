#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

#define MAXN 100

bool a[MAXN][MAXN],isAP[MAXN];
int n,total,cnt,start, order[MAXN];

int dfs(int A, bool isRoot) {
	order[A]=++cnt;
	int ret = order[A];
	int child=0;
	for(int i=0; i<n; i++) {
		if(a[A][i]) {
			if(!order[i]) {
				child++;
				int low=dfs(i,false);
				if(!isRoot && low>=order[A] && !isAP[A]) {
					isAP[A]=true;
					total++;
				}
				ret = std::min(ret,low);
			} else {
				ret = std::min(ret, order[i]);
			}
		}
	}
	if(isRoot && child>=2) {
		total++;
		isAP[A]=true;
	}
	return ret;
}

int main() {

	int m,i,d;
	std::string str;

	while(1) {
		cin>>n;
		if(!n) break;
		
		std::fill(order,order+n,0);
		std::fill(isAP,isAP+n,false);
		for(int i=0; i<n; i++) std::fill(a[i],a[i]+n,false);

		cnt=0, start=-1, total=0;

		while(1) {
			cin>>m;
			if(m==0) break;
			--m;
			if(start==-1) start=m;
			cin.get();
			getline(cin,str);

			istringstream is(str);
			while(is>>d) a[m][d-1]=a[d-1][m]=true;
		}

		dfs(start,true);

		cout<<total<<endl;
	}


	return 0;
}