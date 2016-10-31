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

string ans;
int visit[10000],A,B;

typedef struct Point {
	int x;
	long long dir;
	Point() {}
	Point(int x, long long dir) : x(x), dir(dir) {}
};

Point bfs(int a) {
	queue<Point> q;
	q.push(Point(a, 0));
	visit[a] = 1;
	while (!q.empty()) {
		Point now = q.front();
		q.pop();
		int t, a;
		a = now.x;

		if (a == B) return now;

		t = (a * 2) % 10000;
		if (visit[t] == 0) {
			visit[t] = 1;
			q.push(Point(t, now.dir * 10 + 1));
		}

		if (a == 0) t = 9999;
		else t = a - 1;
		if (visit[t] == 0) {
			visit[t] = 1;
			q.push(Point(t, now.dir * 10 + 2));
		}



		t = a % 1000 * 10 + a / 1000;
		if (visit[t] == 0) {
			visit[t] = 1;
			q.push(Point(t, now.dir * 10 + 3));
		}

		t = a / 10 + (a % 10) * 1000;
		if (visit[t] == 0) {
			visit[t] = 1;
			q.push(Point(t, now.dir * 10 + 4));
		}
	}
}

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		cin >> A >> B;
		ans.clear();
		memset(visit, 0, sizeof(visit));

		long long dir = bfs(A).dir;

		string ans;
		while (dir) {
			int t = dir % 10;
			dir /= 10;
			switch (t) {
			case 1:
				ans.push_back('D');
				break;
			case 2:
				ans.push_back('S');
				break;
			case 3:
				ans.push_back('L');
				break;
			case 4:
				ans.push_back('R');
				break;
			}
		}
		reverse(ans.begin(), ans.end());

		cout << ans << endl;
	}

	return 0;
}