#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;

int prime[10010];
int P[1500];
bool visit[10010];

int main() {

	int top = 0;
	prime[0] = 1;
	for (int i = 4; i < 10000; i += 2) prime[i] = 1;
	for (int i = 3; i < 10000; i += 2) {
		if (!prime[i]) {
			if(i>=1000) P[top++] = i;
			for (int j = i*i; j <= 10000; j += i) {
				prime[j] = 1;
			}
		}
	}
	int T, A, B;
	scanf("%d", &T);
	while (T--) {
		memset(visit, 0, sizeof(visit));
		scanf("%d %d", &A, &B);

		queue<int> q;
		q.push(A);
		int ans = -1, now;
		visit[A] = 1;
		while (!q.empty()) {
			int qSize = q.size();
			ans++;
			for (int i = 0; i < qSize; i++) {
				now = q.front();
				q.pop();

				if (now == B) break;

				int t = now;
				// 1ÀÇ ÀÚ¸®
				for (int i = 0; i < 10; i++) {
					t = (now / 10) * 10 + i;
					if (prime[t] == 0 && visit[t] == 0) {
						visit[t] = 1;
						q.push(t);
					}
				}

				for (int i = 0; i < 10; i++) {
					t = (now / 100) * 100 + now % 10 + 10 * i;
					if (prime[t] == 0 && visit[t] == 0) {
						visit[t] = 1;
						q.push(t);
					}
				}

				for (int i = 0; i < 10; i++) {
					t = (now / 1000) * 1000 + now % 100 + 100 * i;
					if (prime[t] == 0 && visit[t] == 0) {
						visit[t] = 1;
						q.push(t);
					}
				}

				for (int i = 1; i < 10; i++) {
					t = now%1000 + 1000 * i;
					if (prime[t] == 0 && visit[t] == 0) {
						visit[t] = 1;
						q.push(t);
					}
				}

			}
			if (now == B) break;
			
		}
		if (now != B && q.empty()) printf("impossible\n");
		else printf("%d\n", ans);
	}

	return 0;
}