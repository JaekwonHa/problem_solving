#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define INF 987654321
typedef long long ll;

int d[2000000 * 4];

int main() {

	int base = 1;
	while (base <= 2000000) base *= 2;
	base--;

	int n, t, x, p;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &t, &x);
		if (t == 1) {
			p = base + x;
			while (p) d[p]++, p /= 2;
		}
		else {
			p = 1;
			while (p <= base) {
				if (d[p*2] >= x) p *= 2;
				else x -= d[p*2], p = p * 2 + 1;
			}
			printf("%d\n", p - base);
			while (p) d[p]--, p /= 2;
		}
	}

	return 0;
}

