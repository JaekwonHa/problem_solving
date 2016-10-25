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

map<int, int> m;
typedef struct Puzzle {
	int state;
	int xy;
	Puzzle(int x, int y) : state(x), xy(y) {}
};

int change(int state, int a, int b) {
	int c = (state / (int)pow(10.0, 8 - a)) % 10;
	int d = (state / (int)pow(10.0, 8 - b)) % 10;

	state -= d*pow(10.0, 8 - b);
	state += d*pow(10.0, 8 - a);

	return state;
}

int main() {

	int state = 0, t;
	int xy;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &t);
		state = state * 10 + t;
		if (t == 0) xy = i;
	}
	int answer = 123456780;
	int depth = -1;
	queue<Puzzle> q;
	q.push(Puzzle(state, xy));
	m[state]++;
	while (!q.empty()) {
		depth++;
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {

			Puzzle now = q.front();
			q.pop();

			if (now.state == answer) {
				printf("%d\n", depth);
				return 0;
			}

			if (now.xy / 3 != 2) {
				int b = now.xy + 3;
				int a = change(now.state, now.xy, b);
				if (m.count(a) == 0) q.push(Puzzle(a, b)), m[a]++;
			}

			if (now.xy % 3 != 2) {
				int b = now.xy + 1;
				int a = change(now.state, now.xy, b);
				if (m.count(a) == 0) q.push(Puzzle(a, b)), m[a]++;
			}

			if (now.xy % 3 != 0) {
				int b = now.xy - 1;
				int a = change(now.state, now.xy, b);
				if (m.count(a) == 0) q.push(Puzzle(a, b)), m[a]++;
			}

			if (now.xy / 3 != 0) {
				int b = now.xy - 3;
				int a = change(now.state, now.xy, b);
				if (m.count(a) == 0) q.push(Puzzle(a, b)), m[a]++;
			}
		}
	}
	printf("-1\n");

	return 0;
}