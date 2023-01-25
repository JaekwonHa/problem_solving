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


int main() {

	ll l1, r1, l2, r2, k;
	scanf("%I64d%I64d%I64d%I64d%I64d", &l1, &r1, &l2, &r2, &k);

	ll ans = 0;
	if (l1 <= l2) {
		if (r2 <= r1) {
			ans = r2 - l2 + 1;
			if (l2 <= k && k <= r2) {
				ans--;
			}
		}
		else if (r1 <= r2) {
			ans = r1 - l2 + 1;
			if (l2 <= k && k <= r1) {
				ans--;
			}
		}
	}
	else if(l2 <= r1) {
		if (r2 < l1) {
			ans = 0;
		}
		else if (r2 <= r1) {
			ans = r2 - l1 + 1;
			if (l1 <= k && k <= r2) {
				ans--;
			}
		}
		else {
			ans = r1 - l1 + 1;
			if (l1 <= k && k <= r1) {
				ans--;
			}
		}
	}
	else {
		ans = 0;
	}
	ans = max(ans, 0ll);
	printf("%I64d\n", ans);

	return 0;
}