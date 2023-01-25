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
#include <sstream>
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


int n, m;
int a[110], b[110];

int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a%b);
}

int main() {
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i <= m; i++) {
		scanf("%d", &b[i]);
	}

	if (n > m) {
		if (a[0]*b[0] < 0) {
			printf("-");
		}
		printf("Infinity\n");
	}
	else if (n < m) {
		printf("0/1\n");
	}
	else {
		int divA = max(abs(a[0]), abs(b[0]));
		int divB = min(abs(a[0]), abs(b[0]));
		if (a[0] * b[0] < 0) printf("-");
		printf("%d/%d\n", abs(a[0] / GCD(divA, divB)), abs(b[0] / GCD(divA, divB)));
	}

	return 0;
}