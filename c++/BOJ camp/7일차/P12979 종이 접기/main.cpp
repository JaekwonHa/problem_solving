#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main() {

	int W, H, A;
	scanf("%d %d %d", &W, &H, &A);
	int t = W;
	W = min(W, H);
	H = max(t, H);
	
	vector<pair<int, int>> v;
	int a1 = 1, a2 = A;
	for (int i = 1; i*i <= A; i++) {
		if (A%i == 0) {
			a1 = i, a2 = A / i;
			v.push_back(make_pair(a1, a2));
		}
	}
	int ans = 987654321;
	for (int i = 0; i < v.size(); i++) {
		tie(a1, a2) = v[i];
		if (a1 <= W && a2 <= H) {
			int ret = 0;
			while (a1 < W) {
				ret++, a1 *= 2;
			}
			while (a2 < H) {
				ret++, a2 *= 2;
			}
			ans = min(ans, ret);
		}
		tie(a2, a1) = v[i];
		if (a1 <= W && a2 <= H) {
			int ret = 0;
			while (a1 < W) {
				ret++, a1 *= 2;
			}
			while (a2 < H) {
				ret++, a2 *= 2;
			}
			ans = min(ans, ret);
		}
	}
	if (ans == 987654321) ans = -1;
	printf("%d\n", ans);
	
	return 0;
}

