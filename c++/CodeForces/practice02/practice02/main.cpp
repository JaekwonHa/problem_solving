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
#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

// 입력받는 값이 10^9 이고 답이 뭔가 그것들을 더하는 연산이라면 답은 ll 일수 있다


int main() {

	int n, x;
	ll ans1=0, ans2=0;
	scanf("%d %d", &n, &x);
	ans1 = x;
	for (int i = 0; i < n; i++) {
		char c;
		int d;
		scanf(" %c %d", &c, &d);
		if (c == '+') ans1 += d;
		else {
			if (ans1 >= d) {
				ans1 -= d;
			}
			else {
				ans2++;
			}
		}
	}
	printf("%I64d %I64d\n", ans1, ans2);

	return 0;
}