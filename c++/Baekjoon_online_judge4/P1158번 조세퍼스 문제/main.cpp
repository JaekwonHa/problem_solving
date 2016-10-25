#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
int arr[5010];
queue<int> q;

int main() {
	scanf("%d %d", &N, &M);

	for(int i=1; i<=N; i++) q.push(i);

	bool first=true;
	while(!q.empty()) {
		for(int i=1; i<M; i++) {
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		if(first) printf("<"), first=false;
		else printf(", ");
		printf("%d", q.front());
		q.pop();
	}
	printf(">\n");


	return 0;
}