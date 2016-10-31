#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

#define INF 987654321
#define MAXN 100010

int N,M,K;
vector<int> sellter;
vector<pair<int, int> > v[MAXN];
priority_queue<pair<int,int> > pq;

int sumDist[MAXN],sumIndex[MAXN];

void DST(int start) {
	int dis[MAXN];
	for(int i=0; i<MAXN; i++) dis[i]=INF;

	dis[start]=0;
	pq.push(make_pair(0,start));

	while(!pq.empty()) {
		pair<int,int> value = pq.top();
		pq.pop();

		int current = value.second;
		int cost = -value.first;

		//현재 정점까지의 거리가 더 짧은 경우 무시
		if(dis[current] < cost) continue;

		for(int i=0; i<v[current].size(); i++) {
			int next = v[current][i].second;
			int nextCost = v[current][i].first + dis[current];

			if(dis[next] > nextCost) {
				dis[next] = nextCost;
				pq.push(make_pair(-nextCost,next));
			}
		}
	}
	for(int i=1; i<=N; i++) {
		if(start==i) continue;
		if(sumDist[i]==0) {
			sumDist[i]=dis[i];
			sumIndex[i]=start;
		} else {
			if(sumDist[i] > dis[i]) {
				sumDist[i]=dis[i];
				sumIndex[i]=start;
			}
		}
	}
}

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	   C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	   따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
    
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for(test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        
		int src,dest,cost,i;
		scanf("%d %d %d", &N, &M, &K);

		memset(sumDist,0,sizeof(sumDist));
		memset(sumIndex,0,sizeof(sumIndex));
		sellter.clear();
		for(int i=1; i<=N; i++) v[i].clear();

		for(i=1; i<=M; i++) {
			scanf("%d %d %d", &src, &dest, &cost);
			v[src].push_back(make_pair(cost,dest));
			v[dest].push_back(make_pair(cost,src));
		}
		for(i=0; i<K; i++) {
			scanf("%d", &src);
			sellter.push_back(src);
		}
        
		for(i=0; i<sellter.size(); i++) {
			DST(sellter[i]);
		}
		for(i=0; i<sellter.size(); i++) {
			sumIndex[sellter[i]]=sellter[i];
			sumDist[sellter[i]]=0;
		}

		long long sum1=0,sum2=0;
		for(int i=1; i<=N; i++) sum1+=sumDist[i], sum2+=sumIndex[i];
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		printf("%lld\n%lld\n", sum1, sum2);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}