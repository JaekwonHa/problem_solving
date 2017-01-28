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


#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int m[51][51];
int WB[8][8] = {
	{ 1,0,1,0,1,0,1,0 },
	{ 0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,0,1,0 },
	{ 0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,0,1,0 },
	{ 0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,0,1,0 },
	{ 0,1,0,1,0,1,0,1 }
};
int BW[8][8] = {
	{ 0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,0,1,0 },
	{ 0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,0,1,0 },
	{ 0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,0,1,0 },
	{ 0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,0,1,0 }
};
int M, N;

int function_WB(int x, int y) {
	if (x + 8 > M || y + 8 > N) return INF;

	int ret = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (m[x + i][y + j] != WB[i][j]) ret++;
		}
	}
	return ret;
}

int function_BW(int x, int y) {
	if (x + 8 > M || y + 8 > N) return INF;

	int ret = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (m[x + i][y + j] != BW[i][j]) ret++;
		}
	}
	return ret;
}

int main() {
	
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			char c;
			cin >> c;
			if (c == 'W') m[i][j] = 1;
			if (c == 'B') m[i][j] = 0;
		}
	}
	int ans = INF;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			ans = min(ans, function_WB(i, j));
			ans = min(ans, function_BW(i, j));
		}
	}

	printf("%d", ans);

	return 0;
}