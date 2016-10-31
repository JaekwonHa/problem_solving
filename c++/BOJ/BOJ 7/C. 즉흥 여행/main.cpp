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
using namespace std;

// 정답이 ll 이상일 경우 INF를 98765432100000 정도까지 크게 해야함
// 입력받는 값이 10^9 이고 답이 뭔가 그것들을 더하는 연산이라면 답은 ll 일수 있다
// priority_queue 는 기본적으로 내림차순 정렬이다. 오름차순으로 하고 싶다면 priority_queue<int, vector<int>, greater<int>>
// queue에서 pop하기 전에는 반드시 empty인 경우를 체크하고 예외처리 해줘라


#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
#define eps 1e-8

typedef long long ll;

int arr[101][101];
map<string, int> nameFrom;
map<int, string> nameTo;
int N, K;

int preSum[101];

tuple<double,string> DP[101][1001];

double ans;
string ansName;

const int A = 10000000;

void bfs() {
	queue<tuple<int, double, int>> q;
	q.push(mt(0, -1, 0));
	while (!q.empty()) {
		int cur;
		double point;
		int cnt;
		tie(cur, point, cnt) = q.front();
		q.pop();

		if (cnt >= K) {
			if (point > ans) {
				ans = point;
				for (auto a : nameFrom) {
					if (a.second == cur) {
						ansName = a.first;
					}
				}
			}
			continue;
		}

		if (ans > point) {
			continue;
		}

		double sum = 0;
		for (int i = 0; i < N; i++) {
			sum += arr[cur][i];
		}
		for (int i = 0; i < N; i++) {
			if (arr[cur][i]>0) {
				double temp = (double)point*(arr[cur][i] / sum);
				if (point == -1) temp = arr[cur][i] / sum;
				q.push(mt(i, temp, cnt + 1));
			}
		}
	}
}

tuple<double,string> dfs(int cur, int cnt) {

	double retDouble;
	string retStr;
	tie(retDouble, retStr) = DP[cur][cnt];
	if (!(retDouble-(-1) <= eps)) return DP[cur][cnt];

	if (cnt == 1) {
		int sum = preSum[cur];

		double ansTemp = -1;
		string ansStr = "";
		for (int i = 0; i < N; i++) {
			if ((double)arr[cur][i] / sum > ansTemp) {
				ansStr = nameTo[i];
				ansTemp = (double)arr[cur][i] / sum;
			}
		}
		DP[cur][cnt] = mt(ansTemp, ansStr);
		return DP[cur][cnt];
	}

	

	int sum = preSum[cur];

	if (sum <= 0) {
		return DP[cur][cnt];
	}
	
	for (int i = 0; i < N; i++) {
		if (arr[cur][i]>0) {
			double tempDouble;
			string tempStr;
			tie(tempDouble, tempStr) = dfs(i, cnt - 1);
			tempDouble = ((double)arr[cur][i] / sum)*tempDouble;
			if (retDouble == -1) {
				retDouble = tempDouble;
				retStr = tempStr;
			}
			else {
				if (retDouble < tempDouble) {
					retDouble = tempDouble;
					retStr = tempStr;
				}
			}
		}
	}
	DP[cur][cnt] = mt(retDouble, retStr);
	return DP[cur][cnt];
}

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		memset(arr, 0, sizeof(arr));
		nameFrom.clear();
		nameTo.clear();

		scanf("%d %d", &N, &K);


		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= K; j++) {
				DP[i][j] = mt(-1, "");
			}
		}

		string str;
		for (int i = 0; i < N; i++) {
			cin >> str;
			nameFrom[str] = i;
			nameTo[i] = str;
		}
		int a;
		for (int i = 0; i < N; i++) {
			int t = 0;
			for (int j = 0; j < N; j++) {
				scanf("%d", &a);
				arr[i][j] = a;
				t += a;
			}
			preSum[i] = t;
		}
		ans = -1;
		ansName = "";

		tie(ans, ansName) = dfs(0, K);

		cout << ansName << endl;
	}

	return 0;
}

