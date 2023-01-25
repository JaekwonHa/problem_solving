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

vector<pair<int,int>> ans;

int main() {

	int n,x;
	scanf("%d", &n);
	char str[10];

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		if (strcmp(str, "insert") == 0) {
			scanf("%d", &x);
			pq.push(x);
			ans.push_back(mp(0, x));
		}
		if (strcmp(str, "removeMin") == 0) {
			if (pq.empty()) {
				pq.push(0);
				ans.push_back(mp(0, 0));
			}
			pq.pop();
			ans.push_back(mp(1, 0));
		}
		if (strcmp(str, "getMin") == 0) {
			scanf("%d", &x);

			while (!pq.empty() && pq.top() < x) {
				ans.push_back(mp(1, 0));
				pq.pop();
			}
			if (pq.empty() || pq.top() != x) {
				ans.push_back(mp(0, x));
				pq.push(x);
			}
			ans.push_back(mp(2, x));
		}
	}

	printf("%d\n", ans.size());
	for (auto a : ans) {
		if (a.first == 0) {
			printf("insert %d\n", a.second);
		}
		if (a.first == 1) {
			printf("removeMin\n");
		}
		if (a.first == 2) {
			printf("getMin %d\n", a.second);
		}
	}

	return 0;
}