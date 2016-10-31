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


#define INF 9876543210
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int DP[10001];
int coin[101];
int cnt[101];
int N, K;

int main() {

	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d%d", &coin[i], &cnt[i]);
	}

	DP[0] = 1;
	
	for (int i = 0; i < K; i++) {
		for (int j = N; j >= 0; j--) {
			for (int k = 1; k <= cnt[i]; k++) {
				if (coin[i] * k > N) break;
				if (j - coin[i] * k < 0) continue;
				DP[j] += DP[j - coin[i] * k];
			}
		}
	}

	printf("%d\n", DP[N]);
	

	return 0;
}