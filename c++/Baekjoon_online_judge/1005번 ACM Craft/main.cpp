#include <iostream>
#include <string.h>
#include <map>
#include <algorithm>

using namespace std;


#define MAXN 1001

int T,N,K,w[MAXN],W,X,Y,b[MAXN],sum[MAXN],ans;
bool e[MAXN][MAXN];

void TS() {
	int i,j,k=N;
	while(k--) {
		for(i=1; i<=N; i++) if(b[i]==0) break;
		b[i]--;
		// 그냥 짓는게 좋은지 sum[i] 거쳐서 짓는게 좋은지 검사
		sum[i]=max(w[i],sum[i]);
		ans = max(ans,sum[i]);

		for(j=1; j<=N; j++) {
			if(e[i][j]) {
				// i건물을 지음으로써 가능한 모든 건물들을 갱신해준다.
				b[j]--;
				// 이전에 구해진 시간합 sum[j]와 이전 작업 최대시간 sum[i]+ 현재 작업시간 w[j] 중 더 긴 시간을 저장한다.
				sum[j] = max(sum[j],sum[i]+w[j]);
			}
		}
	}
}

int main() {

	cin>>T;
	while(T--) {
		memset(e, 0, sizeof(e));
		memset(b, 0 ,sizeof(b));
		ans=0;
		cin>>N>>K;
		for(int i=1; i<=N; i++)
			cin>>w[i], sum[i]=0;
		for(int i=0; i<K; i++) {
			cin>>X>>Y;
			e[X][Y]=true;
			b[Y]++;
		}

		TS();
		
		int des;
		cin>>des;
		cout<<sum[des]<<endl;
	}

	return 0;
}
/*

#ifdef floyd

int node[1001][1001];
int D[1001];
int T,N,K,X,Y,W;
int answer=0;

int main () {

	bool start[1001];

	cin>>T;

	while(T--) {
		memset(node, 0, sizeof(node));
		memset(D, 0, sizeof(D));
		memset(start, 0, sizeof(start));
		answer=0;
		for(int i=0; i<1001; i++) {
			for(int j=0; j<1001; j++) {
				node[i][j]=999999;
			}
		}

		cin>>N>>K;
		for(int i=1; i<=N; i++) {
			cin>>D[i];
		}
		for(int i=1; i<=K; i++) {
			cin>>X>>Y;
			node[X][Y] = D[Y];
			start[Y] = 1;
		}
		cin>>W;

		for(int i = 1; i <= N; i++)
		 {
		  for(int j = 1; j <= N; j++)
		  {
			   for(int k = 1; k <= N; k++)
			   {
					node[i][j] = min(node[i][j], node[i][k] +  node[k][j]);
			   }
		   }
		 }

		for(int i=1; i<=N; i++) {
			answer = max(answer, node[W][i]);
		}

		cout<<answer<<endl;
	}
}

#endif

#ifdef dfs

int node[1001][1001];
int D[1001];
int T,N,K,X,Y,W;
int answer=0;

void DFS(int start, int weight) {

	if(start==W) {
		answer = max(answer, weight);
		return;
	}
	for(int i=1; i<=N; i++) {
		if(node[start][i]>0) {
			DFS(i, weight+D[i]);
		}
	}
}

int main() {

	bool start[1001];

	cin>>T;

	while(T--) {
		memset(node, 0, sizeof(node));
		memset(D, 0, sizeof(D));
		memset(start, 0, sizeof(start));
		answer=0;

		cin>>N>>K;
		for(int i=1; i<=N; i++) {
			cin>>D[i];
		}
		for(int i=1; i<=K; i++) {
			cin>>X>>Y;
			node[X][Y] = D[Y];
			start[Y] = 1;
		}
		cin>>W;

		for(int i=1; i<=N; i++) {
			if(start[i]==0) {
				DFS(i,D[i]);
			}
		}
		cout<<answer<<endl;
	}
}

#endif

*/