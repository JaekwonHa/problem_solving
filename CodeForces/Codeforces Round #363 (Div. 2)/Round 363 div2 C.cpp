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

int n;
int arr[101];
int DP[101][3];

int f(int pos, int type) {
	int &ret = DP[pos][type];
	if (ret != -1) return ret;
	
	ret = 0;
	if (pos == n) return ret;

	// 1�� ��ѳ�. 2�� ���׽�Ʈ �ѳ�
	if (type != 1) {
		// ������ ��ѳ��� �ƴϸ� ��� �� �� �ִ�.
		if (arr[pos] == 2 || arr[pos] == 3) {
			ret = max(ret, 1 + f(pos + 1, 1));
		}
		else {
			ret = max(ret, f(pos + 1, 0));
		}
	}
	if (type != 2) {
		// ������ ���׽�Ʈ���� �ƴϸ� ���׽�Ʈ�� �� �� �ִ�.
		if (arr[pos] == 1 || arr[pos] == 3) {
			ret = max(ret, 1 + f(pos + 1, 2));
		}
		else {
			ret = max(ret, f(pos + 1, 0));
		}
	}
	
	return ret;
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	memset(DP, -1, sizeof(DP));

	printf("%d\n", n-f(0, 0));

	return 0;
}