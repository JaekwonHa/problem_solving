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

int N;
int arr[100001];
map<int, int> m;

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		m[a] = 1;
	}

	if (m.size() <= 2) {
		printf("YES\n");
	}
	else if (m.size() == 3) {
		int m1 = INF, m2 = 0;
		for (auto a : m) {
			m1 = min(m1, a.first);
			m2 = max(m2, a.first);
		}
		auto a = m.begin();
		a++;
		int w = a->first;
		if (2 * w == m1 + m2) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	else {
		printf("NO\n");
	}

	return 0;
}