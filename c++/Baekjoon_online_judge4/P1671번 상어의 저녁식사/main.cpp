#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAXN 1000

typedef struct shark {
	int weight;
	int speed;
	int wisdom;
	shark() {
		weight=speed=wisdom=0;
	}
}shark;

int N;
vector<shark> v;
int map[2*MAXN+5][2*MAXN+5];
bool visited[2*MAXN+5];

bool dfs(int now)  {
	if(now==2*N+1) return true;
	visited[now]=true;
	bool b = false;
	for(int i=1; i<=2*N+1; i++) {
		if(map[now][i]>0 && !visited[i]) {
			visited[i]=true;
			b = dfs(i);
			if(b) {
				map[now][i]--,map[i][now]++;
				break;
			}
		}
	}
	return b;
}

int BipartiteMatching() {
	int cnt=0;
	while(1) {
		memset(visited,false,sizeof(visited));
		if(dfs(0)) cnt++;
		else break;
	}
	return N-cnt;
}


int main() {
	scanf("%d", &N);
	shark s;
	v.push_back(s);
	for(int i=1; i<=N; i++) {
		map[0][i]=2;
		map[N+i][2*N+1]=1;
		scanf("%d %d %d", &s.weight, &s.speed, &s.wisdom);
		v.push_back(s);
	}
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(i==j) continue;
			if(i>j && v[i].weight==v[j].weight && v[i].speed == v[j].speed && v[i].wisdom==v[j].wisdom) continue;
			if(v[i].weight >= v[j].weight && v[i].speed >= v[j].speed && v[i].wisdom >= v[j].wisdom) {
				map[i][N+j]=1;
			}
		}
	}
	printf("%d\n", BipartiteMatching());


	return 0;
}