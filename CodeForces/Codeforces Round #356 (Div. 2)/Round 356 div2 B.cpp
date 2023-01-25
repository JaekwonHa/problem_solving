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

// ������ ll �̻��� ��� INF�� 98765432100000 �������� ũ�� �ؾ���
// �Է¹޴� ���� 10^9 �̰� ���� ���� �װ͵��� ���ϴ� �����̶�� ���� ll �ϼ� �ִ�
// priority_queue �� �⺻������ �������� �����̴�. ������������ �ϰ� �ʹٸ� priority_queue<int, vector<int>, greater<int>>
// queue���� pop�ϱ� ������ �ݵ�� empty�� ��츦 üũ�ϰ� ����ó�� �����


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