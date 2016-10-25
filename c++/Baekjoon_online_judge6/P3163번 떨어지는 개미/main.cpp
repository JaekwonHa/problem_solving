#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> ant;
vector<ant> ants;
vector<ant> info;
int N,L,k;

int main() {

	int a,b,T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d", &N, &L, &k);
		ants.clear();
		info.clear();
		for(int i=0; i<N; i++) {
			scanf("%d %d", &a, &b);
			if(b<0) {
				ants.push_back(make_pair(a,b));
				info.push_back(make_pair(a,-1));
			} else {
				ants.push_back(make_pair(a,b));
				info.push_back(make_pair(L-a,1));
			}
		}
		sort(ants.begin(), ants.end());
		sort(info.begin(), info.end());

		int ret,time;
		a = 0, b = N-1;
		for(int i=0; i<k; i++) {
			if(info[i].second < 0) {
				ret = ants[a].second;
				time = info[i].first;
				a++;
			} else {
				ret = ants[b].second;
				time = info[i].first;
				b--;
			}
		}

		printf("%d %d\n", ret);
	}


	return 0;
}