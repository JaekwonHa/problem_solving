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

bool visit[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int M, N;
int cnt = 0;

int dfs(int x, int y, int dir) {
	cnt++;
	if (cnt == M*N) return 0;
	visit[x][y] = true;
	int nextX = x + dx[dir];
	int nextY = y + dy[dir];
	if (visit[nextX][nextY] == true || nextX >= M || nextX < 0 || nextY >= N || nextY < 0) {
		if (dir == 2) {
			dir = 0;
			return 1 + dfs(x + dx[dir], y + dy[dir], dir);
		}
		if (dir == 0) {
			dir = 3;
			return 1 + dfs(x + dx[dir], y + dy[dir], dir);
		}
		if (dir == 1) {
			dir = 2;
			return 1 + dfs(x + dx[dir], y + dy[dir], dir);
		}
		if (dir == 3) {
			dir = 1;
			return 1 + dfs(x + dx[dir], y + dy[dir], dir);
		}
	}
	return dfs(nextX, nextY, dir);
}

int main() {

	
	scanf("%d %d", &M, &N);
	printf("%d\n", dfs(0, 0, 2));

	return 0;
}