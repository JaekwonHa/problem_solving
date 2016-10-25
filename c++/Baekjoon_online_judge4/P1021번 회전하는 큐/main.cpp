#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

int N,M,ans;
deque<int> deq;
queue<int> q;

void solve(int m) {

}

int main() {
	int a;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		deq.push_back(i+1);
	for(int i=0; i<M; i++) {
		scanf("%d", &a);
		q.push(a);
	}

	while(M--) {
		solve(q.front());
		q.pop();
	}


	return 0;
}