#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;



int main() {

	int N;
	queue<int> q;

	scanf("%d", &N);

	for(int i=1; i<=N; i++)
		q.push(i);

	while(!q.empty()) {
		printf("%d ", q.front());
		q.pop();
		if(!q.empty()) {
			int temp = q.front();
			q.push(temp);
			q.pop();
		}
	}


	return 0;
}