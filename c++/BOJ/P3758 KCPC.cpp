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
#include <set>
#include <deque>
#include <functional>
#include <sstream>
using namespace std;

// 정답이 ll 이상일 경우 INF를 98765432100000 정도까지 크게 해야함
// 입력받는 값이 10^9 이고 답이 뭔가 그것들을 더하는 연산이라면 답은 ll 일수 있다
// priority_queue 는 기본적으로 내림차순 정렬이다. 오름차순으로 하고 싶다면 priority_queue<int, vector<int>, greater<int>>
// queue에서 pop하기 전에는 반드시 empty인 경우를 체크하고 예외처리 해줘라


#define INF 9876543210
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int score[101][101];
struct Team {
	int total, cnt, time, idx;
	Team() {}
	Team(int a, int b, int c, int d) : total(a), cnt(b), time(c), idx(d) {}
};

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {

		int n, k, t, m, i, j, s;
		scanf("%d %d %d %d", &n, &k, &t, &m);
		memset(score, 0, sizeof(score));
		
		vector<Team> team(n + 1, Team(0, 0, 0, 0));
		for (int ii = 1; ii <= n; ii++) {
			team[ii].idx = ii;
		}

		for (int ii = 0; ii < m; ii++) {
			scanf("%d %d %d", &i, &j, &s);
			team[i].cnt++;
			team[i].time = ii;
			score[i][j] = max(score[i][j], s);
		}
		for (int ii = 1; ii <= n; ii++) {
			int sum = 0;
			for (int jj = 1; jj <= k; jj++) {
				sum += score[ii][jj];
			}
			team[ii].total = sum;
		}
		sort(team.begin(), team.end(), [](Team A, Team B) {
			if (A.total == B.total) {
				if (A.cnt == B.cnt) {
					return A.time < B.time;
				}
				return A.cnt < B.cnt;
			}
			return A.total > B.total;
		});
		int ans = 0;
		for (int ii = 1; ii <= n; ii++) {
			if (team[ii].idx == t) {
				ans = ii;
				break;
			}
		}
		printf("%d\n", ans+1);
	}

	return 0;
}