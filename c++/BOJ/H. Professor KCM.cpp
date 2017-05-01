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
int arr[1000001];

int cnt[1001];

ll GCD(ll a, ll b) {
	if (b == 0) return a;
	return GCD(b, a%b);
}

int PRIME[1001];

int main() {

	for (int i = 2; i <= 1000; i++) {
		if (PRIME[i] == 0) {
			for (int j = i+i; j <= 1000; j += i) {
				PRIME[j] = 1;
			}
		}
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		memset(cnt, 0, sizeof(cnt));

		for (int i = 0; i < N; i++) {
			int t = arr[i];
			for (int j = 2; j <= t; j++) {
				if (PRIME[j] == 1) continue;
				int c = 0;
				while (arr[i] % j == 0) {
					c++;
					arr[i] /= j;
				}
				if (cnt[j] < c) {
					cnt[j] = c;
				}
			}

		}

		ll ans = 1;
		for (int i = 2; i <= 1000; i++) {
			if (PRIME[i] == 1) continue;
			if (cnt[i] != 0) {
				for (int j = 0; j < cnt[i]; j++) {
					ans = (ans*i) % mod;
				}
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}