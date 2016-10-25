#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define MAXN 800

int N,P;
int map[MAXN+5][MAXN+5];
bool visited[MAXN+5];

bool dfsFrom1(int now) {
	if(now==2) return true;
	visited[now]=true;
	bool b=false;
	for(int i=N; i>0; i--) {
		if(map[now][i]>0 && !visited[i]) {
			b = dfsFrom1(i);
			if(b) {
				map[now][i]--,map[i][now]++;
				break;
			}
		}
	}
	return b;
}

bool dfsFrom2(int now) {
	if(now==1) return true;
	visited[now]=true;
	bool b=false;
	for(int i=N; i>0; i--) {
		if(map[now][i]>0 && !visited[i]) {
			b = dfsFrom2(i);
			if(b) {
				map[now][i]--,map[i][now]++;
				break;
			}
		}
	}
	return b;
}

int MaxFlow() {
	int cnt=0;
	while(1) {
		memset(visited,false,sizeof(visited));
		if(dfsFrom1(1)) cnt++;
		else break;
		/*
		visited[1]=visited[2]=false;
		if(dfsFrom2(2)) cnt++;
		else break;
		*/
	}
	return cnt;
}

int main() {
	int a,b;
	scanf("%d %d", &N, &P);
	for(int i=0; i<P; i++) {
		scanf("%d %d", &a, &b);
		map[a][b]=1;
	}
	/*
	for(int i=3; i<=N; i++) {
		map[1][i]=1;
		map[i][2]=1;
	}
	*/
	printf("%d\n", MaxFlow());
	return 0;
}