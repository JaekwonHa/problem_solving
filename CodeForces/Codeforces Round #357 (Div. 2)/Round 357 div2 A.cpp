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

int n;
char str[11];
int before, after;

int main() {
	bool ok = false;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", str, &before, &after);
		if (before >= 2400 && after > before) {
			ok = true;
		}
	}

	ok ? printf("YES\n") : printf("NO\n");


	return 0;
}