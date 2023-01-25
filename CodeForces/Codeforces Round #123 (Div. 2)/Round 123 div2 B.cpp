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

	int n, m;
	scanf("%d %d", &n, &m);

	int middle = (m + 1) / 2;
	int left = middle - 1;
	int right = middle + 1;
	int leftCnt = 0;
	int rightCnt = 0;
	int cnt = m;

	for (int i = 1; i <= n; i++) {
		if (cnt==m) {
			printf("%d\n", middle);
			cnt = 1;
			left = middle - 1;
			right = middle + 1;
			leftCnt = 0;
			rightCnt = 0;
			continue;
		}
		if (leftCnt <= rightCnt && left==0) {
			rightCnt++;
			cnt++;
			printf("%d\n", right++);
			continue;
		}
		if (((double)m+1)/2-left <= right-((double)m+1)/2) {
			leftCnt++;
			cnt++;
			printf("%d\n", left--);
			continue;
		}
		else {
			rightCnt++;
			cnt++;
			printf("%d\n", right++);
			continue;
		}
	}

	return 0;
}