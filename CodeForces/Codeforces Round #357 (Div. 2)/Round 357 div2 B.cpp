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

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

const int HOUSE=1234567;
const int CAR=123456;
const int COM=1234;

int main() {
	
	int n;
	int a = 0, b = 0, c = 0;
	scanf("%d", &n);

	bool ok = false;
	for (; a*HOUSE + b*CAR + c*COM <= n; a++) {
		for (; a*HOUSE + b*CAR + c*COM <= n; b++) {
			if ((n - a*HOUSE - b*CAR) % COM == 0) {
				ok = true;
				break;
			}
		}
		b = 0;
		if (ok) break;
	}
	ok ? printf("YES\n") : printf("NO\n");

	return 0;
}