#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,A[10],B[10];
int ans;
vector<int> list;
bool visited[10];

void solve(int n) {
	if(n==N) {
		int sum=0;
		for(int i=0; i<N-1; i++) {
			sum+= abs(list[i]-list[i+1]);
		}
		ans = max(ans,sum);
		return;
	}
	for(int i=0; i<N; i++) {
		if(visited[i]==true) continue;
		visited[i]=true;
		list.push_back(A[i]);
		solve(n+1);
		list.pop_back();
		visited[i]=false;
	}
	return;
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &A[i]);

	solve(0);

	printf("%d\n", ans);
	return 0;
}