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

	vector<int> v(101, 0);
	int a;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &a);
		v[a]++;
	}
	int sum = 0;
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		sum += i*v[i];
		if (v[i] == 2) {
			ans = max(ans, i * 2);
		}
		if (v[i] >= 3) {
			ans = max(ans, i * 3);
		}
	}

	printf("%d\n", sum - ans);

	return 0;
}