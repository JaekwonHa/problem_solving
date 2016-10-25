#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int> Stone;

int N;
int DP[2000][2000];

int f(int a, int b) {
	
	int c = N - a - b;
	if (a > 1000 || b > 1000 || c > 1000) return 0;
	if (a < 0 || b < 0 || c < 0) return 0;
	if (a == b && b == c) return 1;

	int &ret = DP[a][b];
	if (ret != -1) return ret;

	int ans,t1, t2;

	t1 = min(a, b) * 2;
	t2 = max(a, b) - min(a, b);
	if(a!=b && DP[t1][t2] == -1) {
		ret = f(t1, t2);
		if (ret == 1) return ret;
	}

	t1 = min(a, c) * 2;
	t2 = max(a, c) - min(a, c);
	if (a != c && DP[t1][b] == -1) {
		ret = f(t1, b);
		if (ret == 1) return ret;
	}
	

	t1 = min(b, c) * 2;
	t2 = max(b, c) - min(b, c);
	if (b != c && DP[a][t1] == -1) {
		ret = f(a, t1);
		if (ret == 1) return ret;
	}
	
	return 0;
}

int bfs(int A, int B) {
	queue<Stone> q;
	q.push(Stone(A,B));

	DP[A][B] = 0;
	while (!q.empty()) {
		Stone s = q.front();
		int a = get<0>(s);
		int b = get<1>(s);
		int c = N - a - b;
		q.pop();

		if (a > 1000 || b > 1000 || c > 1000) continue;
		if (a < 0 || b < 0 || c < 0) continue;
		if (a == b && b == c) return 1;
		DP[a][b] = 1;

		int ans, t1, t2;

		if (a < b) {
			t1 = a * 2;
			t2 = b - a;
			if (DP[t1][t2] == -1) {
				q.push(Stone(t1, t2));
			}
		}

		if (b < a) {
			t1 = a - b;
			t2 = b * 2;
			if (DP[t1][t2] == -1) {
				q.push(Stone(t1, t2));
			}
		}

		if (b < c) {
			t1 = b * 2;
			t2 = c - b;
			if (DP[a][t1] == -1) {
				q.push(Stone(a, t1));
			}
		}

		if (c < b) {
			t1 = b - c;
			t2 = c * 2;
			if (DP[a][t1] == -1) {
				q.push(Stone(a, t1));
			}
		}
		if (a < c) {
			t1 = a * 2;
			t2 = c - a;
			if (DP[t1][b] == -1) {
				q.push(Stone(t1, b));
			}
		}

		if (c < a) {
			t1 = a - c;
			t2 = c * 2;
			if (DP[t1][b] == -1) {
				q.push(Stone(t1, b));
			}
		}
	}
	return 0;
}

int main() {

	int A, B, C;
	cin >> A >> B >> C;
	N = A + B + C;

	memset(DP, -1, sizeof(DP));
	cout << bfs(A, B) << endl;

	return 0;
}