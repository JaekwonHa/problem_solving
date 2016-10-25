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

int N;
int know[3001][3001];
int know2[3001][3001];
int DP[3001][3001];

int f(int start, int end) {

	int &ret = DP[start][end];
	if (ret != -1) return ret;

	if (start == end) {
		//ret = know[start][end] - know[start][start-1] + unknow[]
	}

	return ret;
}

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a;
		while (1) {
			scanf("%d", &a);
			if (a == 0) break;
			DP[i + 1][a] = 1;
			DP[a][i + 1] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (DP[i][j] == 1 && i != j) {
				know[i][j] = know[i][j - 1] + 1;
			}
			else {
				know[i][j] = know[i][j - 1];
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			know2[i][j] = know2[i - 1][j] + know[i][j] - know[i][i - 1];
		}
	}

	memset(DP, -1, sizeof(DP));

	printf("%d", f(1, N));


	return 0;
}