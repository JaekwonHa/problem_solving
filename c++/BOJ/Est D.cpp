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
typedef long long ll;

int solution(int X, int Y) {
	// write your code in C++11 (g++ 4.8.2)

	int level = max(abs(X), abs(Y));

	int ans = (4 + (level - 1) * 4)*(level - 1);

	int baseX = 0, baseY = 0;

	if (X != -1 * level && Y == level) {
		baseX = -1 * level + 1;
		baseY = level;
	}
	else if (X == level) {
		ans += level * 2;
		baseX = level;
		baseY = level - 1;
	}
	else if (Y == -1 * level) {
		ans += level * 4;
		baseX = level - 1;
		baseY = -1 * level;
	}
	else {
		ans += level * 6;
		baseX = -1 * level;
		baseY = -1 * level + 1;
	}
	ans += abs(baseX - X) + abs(baseY - Y);

	return ans+1;
}


int main() {

	freopen("input.txt", "r", stdin);

	int x, y;
	scanf("%d %d", &x, &y);

	printf("%d", solution(x, y));

	return 0;
}