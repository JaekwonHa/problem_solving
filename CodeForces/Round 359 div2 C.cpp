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

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;


int main() {

	ll n, m;
	scanf("%I64d %I64d", &n, &m);

	int len1 = 1, len2 = 1;
	ll nn = n, mm = m;
	n = --n / 7;
	m = --m / 7;
	while (n) {
		len1++;
		n /= 7;
	}
	while (m) {
		len2++;
		m /= 7;
	}
	ll ans = 0;
	if (len1 + len2 <= 8) {
		for (int i = 0; i < nn; i++) {
			for (int j = 0; j < mm; j++) {

				vector<int> cnt(7,0);
				int t1 = i, t2 = j;
				for (int ii = 0; ii < len1; ii++) {
					cnt[t1 % 7]++;
					t1 /= 7;
				}
				for (int ii = 0; ii < len2; ii++) {
					cnt[t2 % 7]++;
					t2 /= 7;
				}
				if (*max_element(cnt.begin(), cnt.end()) <= 1) ans++;
			}
		}
	}
	
	printf("%I64d\n", ans);

	return 0;
}