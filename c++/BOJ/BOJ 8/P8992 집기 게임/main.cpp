#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;


#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int ccw(int ax, int ay, int bx, int by, int cx, int cy)
{
	ll k = (ll)(bx - ax)*(cy - ay) - (ll)(cx - ax)*(by - ay);
	if (k > 0) return 1;
	if (!k) return 0;
	return -1;
}

int N, M;
int w[402][402];
int c[402][402];
int from[402];
int Isin[402];
int dist[402];
vector<int> edge[402];

void add_edge(int s, int e, int cst) {

	edge[s].push_back(e);
	edge[e].push_back(s);
	w[s][e]++;
	c[s][e] = cst;
	c[e][s] = -cst;
}

int spfa() {

	for (int i = 0; i <= N + M + 1; i++) dist[i] = -INF, from[i] = -1, Isin[i] = 0;
	dist[0] = 0; from[0] = 0; Isin[0] = 1;
	queue<int> myQ; myQ.push(0);

	while (!myQ.empty()) {
		int now = myQ.front(); myQ.pop();
		Isin[now] = 0;

		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i];
			if (!w[now][next]) continue;
			if (dist[next] < dist[now] + c[now][next]) {
				dist[next] = dist[now] + c[now][next];
				from[next] = now;
				if (!Isin[next]) myQ.push(next), Isin[next] = 1;
			}
		}
	}
	return dist[N + M + 1]>-INF;
}

struct Line {
	int x1, y1, x2, y2, w;
};

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {

		int n, m, x1, y1, x2, y2;
		scanf("%d %d", &N, &M);

		vector<Line> line1(N + 1);
		vector<Line> line2(M + 1);

		for (int i = 0; i <= N + M + 1; i++) edge[i].clear();
		for (int i = 0; i <= N + M + 1; i++) {
			for (int j = 0; j <= N + M + 1; j++) {
				w[i][j] = 0;
				c[i][j] = 0;
			}
		}

		for (int i = 1; i <= N; i++) {
			scanf("%d %d %d %d %d", &line1[i].x1, &line1[i].y1, &line1[i].x2, &line1[i].y2, &line1[i].w);
			if (line1[i].x1 > line1[i].x2)swap(line1[i].x1, line1[i].x2);
		}
		for (int i = 1; i <= M; i++) {
			scanf("%d %d %d %d %d", &line2[i].x1, &line2[i].y1, &line2[i].x2, &line2[i].y2, &line2[i].w);
			if (line2[i].y1 > line2[i].y2)swap(line2[i].y1, line2[i].y2);
		}


		for (int i = 1; i<=N; i++) {
			add_edge(0, i, 0);
		}
		for (int i = N + 1; i <= N + M; i++) {
			add_edge(i, N + M + 1, 0);
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (ccw(line1[i].x1, line1[i].y1, line1[i].x2, line1[i].y2, line2[j].x1, line2[j].y1) * ccw(line1[i].x1, line1[i].y1, line1[i].x2, line1[i].y2, line2[j].x2, line2[j].y2) <= 0 &&
					ccw(line2[j].x1, line2[j].y1, line2[j].x2, line2[j].y2, line1[i].x1, line1[i].y1) * ccw(line2[j].x1, line2[j].y1, line2[j].x2, line2[j].y2, line1[i].x2, line1[i].y2) <= 0) {
					add_edge(i, N + j, line1[i].w * line2[j].w);
				}
			}
		}
		int ans = 0, cnt = 0;

		while (spfa()) {
			cnt++;
			ans += dist[N + M + 1];
			for (int i = N + M + 1; i; i = from[i]) w[from[i]][i]--, w[i][from[i]]++;
		}
		printf("%d %d\n", cnt, ans);
	}

	return 0;
}