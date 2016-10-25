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

int K,N;
char arr[1100][1100];
char ans[1100];
int posMark;
char dest[1100];
char failAns[1100];

int process(int x, int dir) {
	if (dir == 2) {
		int name = x;
		for (int y = 0; y < K; y++) {
			if (arr[y][x] == '-') {
				x--;
			}
			else if (arr[y][x+1] == '-') {
				x++;
			}
		}
		if (dest[x] - 'A' != name) {
			return -1;
		}
		return 1;
	}


	int y = dir == 1 ? 0 : K - 1;

	while (y != posMark) {

		if (arr[y][x] == '-') {
			x--;
		}
		else if (arr[y][x+1] == '-') {
			x++;
		}

		y += dir;
	}

	return x;
}

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &K);
	scanf("%s", dest);

	for (int i = 0; i < K; i++) {
		scanf("%s", arr[i]+1);
		if (arr[i][1] == '?') {
			posMark = i;
		}
	}

	bool ok = true;
	for (char i = 'A'; i < 'A' + N; i++) {

		int pos1 = process(i - 'A', 1);

		int pos2 = 0;
		for (int j = 0; j < N; j++) {
			if (dest[j] == i) {
				pos2 = process(j, -1);
				break;
			}
		}
		
		// ? 사다리 채우기
		if (abs(pos1 - pos2) >= 2) {
			ok = false;
			break;
		}
		if (pos1 == pos2) {
			ans[pos1] = ans[pos1 + 1] = '*';
		}
		else if (pos1 < pos2) {
			ans[pos1] = '*';
			ans[pos2] = '-';
		}
		else {
			ans[pos1] = '-';
			ans[pos2] = '*';
		}
	}
	if (ok) {
		strcpy(arr[posMark]+1, ans+1);

		for (char i = 'A'; i < 'A' + N; i++) {
			if (process(i-'A', 2)==-1) {
				ok = false;
				break;
			}
		}
	}
	if (ok) {
		ans[N] = '\0';
		printf("%s\n", ans + 1);
	}
	else {
		for (int i = 0; i < N - 1; i++) {
			failAns[i] = 'x';
		}
		printf("%s\n", failAns);
	}
	

	return 0;
}