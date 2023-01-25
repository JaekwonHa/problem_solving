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


int main() {

	int a, b, r;
	scanf("%d %d %d", &a, &b, &r);
	
	r *= 2;
	int cnt = (a/r) * (b/r);

	if (a < r || b < r) {
		printf("Second\n");
		return 0;
	}

	if (a / r == 1) {
		cnt = b / r;
	}
	else if (b / r == 1) {
		cnt = a / r;
	}
	else {
		cnt = a / r + b / r + a / r + b / r - 4;
	}

	if (cnt % 2 == 0) {
		printf("Second\n");
	}
	else {
		printf("First\n");
	}
	

	return 0;
}