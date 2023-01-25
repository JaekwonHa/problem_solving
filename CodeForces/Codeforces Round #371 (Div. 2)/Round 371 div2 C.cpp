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

int arr[300000];

int makeBinary(ll z) {
	int aux;
	int pot = 1;
	int ans = 0;
	while (z > 0) {
		aux = z % 10;
		if (aux % 2 == 1) ans += pot;
		pot *= 2;
		z /= 10;
	}
	return ans;
}

int main() {

	char op[10];
	int n;
	ll a;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %I64d", op, &a);
		ll x = makeBinary(a);
		if (op[0] == '+') {
			arr[x]++;
		}
		else if (op[0] == '-') {
			arr[x]--;
		}
		else {
			printf("%d\n", arr[x]);
		}
	}

	return 0;
}