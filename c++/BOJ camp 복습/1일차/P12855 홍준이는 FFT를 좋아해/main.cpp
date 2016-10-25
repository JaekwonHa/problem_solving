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

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

ll x;
int n, d;
int a[100005], b[100005], one[100005];

ll getNextX() {
	x = (x * 37 + 10007) % 1000000007;
	return x;
}
void initAB() {
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		swap(a[i], a[getNextX() % (i + 1)]);
	}
	for (int i = 0; i < n; i++) {
		if (i < d)
			b[i] = 1;
		else
			b[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		swap(b[i], b[getNextX() % (i + 1)]);
	}
}

int main() {

	scanf("%d %d %I64d", &n, &d, &x);
	initAB();


	/*
	A배열에 어떤 수들이 저장되던지 B배열에는 0과 1밖에 없다. Ci 에 저장되는 원소들은 A배열의 i 포함 이전의 원소들 중 B배열의 1과 곱해진 수로 한정된다는 말이다.
	그리고 i가 결정되면 B배열의 j번째도 자동으로 결정된다. 이말은 Ai 이전의 원소들을 내림차순 정렬해둔 상태에서 가장 먼저 1과 곱해지는 수가
	C배열의 원소가 된다는 말이다.

	여기서 d가 1일때 예외처리를 해주어야 하는 것같다.
	내 생각으로 d가 1이면 B배열에 원소 1이 딱 1개가 생긴다.
	위치는 알 수 없지만 이 녀석을 찾는데 set을 쓰는 것보다 배열을 쓰는게 빠르기에
	d가 작을때는 배열을 쓰게 해야 할 것 같다.
	*/

	int vn = 0;
	for (int i = 0; i < n; i++) {
		if (b[i]) {
			one[++vn] = i;
		}
	}

	set<pair<int, int>> s;
	for (int i = 0; i < n; i++) {
		s.insert(mp(-a[i], i));
		int ans = 0;
		if (d == 1) {
			for (int j = 1; j <= vn; j++) {
				if (one[j] > i) break;
				ans = max(ans, a[i - one[j]]);
			}
		}
		else {
			for (auto ss : s) {
				if (b[i - ss.second] == 1) {
					ans = max(ans, -ss.first);
					break;
				}
			}
		}

		printf("%d ", ans);
	}

	return 0;
}