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

int arr[101];

int main() {

	int a, n, t;
	scanf("%d %d", &n, &a);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	a--;
	int left = a - 1, right = a + 1;
	int ans = 0;
	if (arr[a] == 1) ans++;
	for (; left >= 0 || right < n; ) {
		if (left >= 0 && right < n) {
			if (arr[left] == 1 && arr[right] == 1) {
				ans += 2;
			}
		}
		else if (left < 0 && right < n) {
			if (arr[right] == 1) {
				ans++;
			}
		}
		else if (left >= 0 && right >= n) {
			if (arr[left] == 1) {
				ans++;
			}
		}
		left--, right++;
	}

	printf("%d\n", ans);

	return 0;
}