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


#define INF 9876543210
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;


int main() {

	int x, y;
	scanf("%d%d", &x, &y);

	int ans = 0;
	int a, b, c;
	a = b = c = y;
	while (a != x || b != x || c != x) {
		if (a <= b && a <= c) {
			a = min(x, abs(b + c) - 1);
		}
		else if (b <= a&& b <= c) {
			b = min(x, abs(a + c) - 1);
		}
		else {
			c = min(x, abs(a + b) - 1);
		}
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}