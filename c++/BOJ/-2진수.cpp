#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

void dfs(ll cur, int pos, ll goal) {
	if (pos == 0) return;
	if (cur == goal) {
		printf("0");
		dfs(cur, pos - 1, goal);
		return;
	}
	ll next = goal - cur;
	if (next < 0) {
		ll a = -2;
		int length = 2;
		while (a > next) {
			length += 2;
			a = a + pow(-2, length-1);
		}
		for (int i = pos; i > length; i--) {
			printf("0");
		}
		printf("1");
		a = pow(-2, length - 1);
		dfs(cur + a, length-1, goal);
	}
	else {
		ll a = 1;
		int length = 1;
		while (a < next) {
			length += 2;
			a = a + pow(2, length - 1);
		}
		for (int i = pos; i > length; i--) {
			printf("0");
		}
		printf("1");
		a = pow(2, length - 1);
		dfs(cur + a, length-1, goal);
	}
}

int main()
{

		ll n;
		scanf("%lld", &n);

		int length = 0;
		ll a = 0;
		if (n == 0) {
			printf("0\n");
		}
		else if (n > 0) {
			if (n == 1) {
				printf("1\n");
				return 0;
			}
			length = -2;
			while (a < n) {
				length += 2;
				a = a + pow(2, length);
			}
			printf("1");
			a = pow(2, length);

			dfs(a, length, n);
		}
		else {
			ll a = -2;
			int length = 2;
			while (a > n) {
				length += 2;
				a = a + pow(-2, length - 1);
			}
			printf("1");
			a = pow(-2, length - 1);
			dfs(a, length - 1, n);
		}

		printf("\n");
}