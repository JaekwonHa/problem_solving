#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define INF 987654321

int N,M,K;
int DP[310][310];
int map[310][310];
vector<pair<int,int> > v[310];

int f(int num, int m) {
	if(m>M) return -INF;
	if(num>=N) return 0;

	int& ret = DP[num][m];
	if(ret!=-1) return ret;

	//ret = -INF;
	/*
	for(int i=0; i<v[num].size(); i++) {
		ret = max(ret, f(v[num][i].first, m+1)+v[num][i].second);
	}
	*/
	for(int i=num+1; i<=N; i++) {
		if(map[num][i]>0) {
			ret = max(ret, f(i, m+1)+map[num][i]);
		}
	}
	return ret;
}

int main() {

	scanf("%d %d %d", &N, &M, &K);
	int a,b,c;
	for(int i=0; i<K; i++) {
		scanf("%d %d %d", &a, &b, &c);
		//if(a>b) swap(a,b);
		//v[a].push_back(make_pair(b,c));
		map[a][b] = max(map[a][b],c);
	}

	memset(DP,-1,sizeof(DP));
	printf("%d\n", f(1,1));

	return 0;
}

