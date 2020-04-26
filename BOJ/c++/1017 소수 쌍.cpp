#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAXN 100

int N;
vector<int> v[MAXN+5];
int backMatch[MAXN+5];
bool visited[MAXN+5];
int prime_table[2010];
int arr[MAXN+5];
vector<int> ans;

void find_prime() {
	for(int i=2; i<2010; i++) {
		for(int j=i+i; j<2010; j+=i) {
			prime_table[j]=1;
		}
	}
}

bool dfs(int now) {
	if(visited[now]) return false;
	visited[now] = true;
	for(int i=1; i<N; i++) {
		if(visited[i]==true) continue;
		if(prime_table[arr[i]+arr[now]]==1) continue;
		if(backMatch[i]==-1 || dfs(backMatch[i])) {
			backMatch[i]=now;
			return true;
		}
	}
	return false;
}

void BipartiteMatching(int t) {
	memset(backMatch,-1,sizeof(backMatch));
	int matched=2;
	for(int i=1; i<N; i++) {
		memset(visited,false,sizeof(visited));
		visited[0]=visited[t]=true;
		if(dfs(i)) matched++;
	}
	if(matched==N) ans.push_back(arr[t]);
}

int main() {
	find_prime();
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}

	for(int i=1; i<N; i++) {
		if(prime_table[arr[0]+arr[i]]==1) continue;
		BipartiteMatching(i);
	}

	if(ans.size()==0) printf("-1");
	else {
		sort(ans.begin(), ans.end());
		for(int i=0; i<ans.size(); i++) {
			printf("%d ", ans[i]);
		}
	}
	

	return 0;
}