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

int prime[101];

int main() {

	char str[10];

	for (int i = 2; i <= 100; i++) {
		if (prime[i] == 0) {
			for (int j = i + i; j <= 100; j += i) {
				prime[j] = 1;
			}
		}
	}
	bool ok = false;
	int cnt = 0;
	for (int i = 2; i < 50; i++) {
		if (prime[i] == 0) {
			printf("%d\n", i);
			fflush(stdout);
			scanf("%s", str);
			if (str[0] == 'y' || str[0] == 'Y') {
				cnt++;
			}
			if (cnt >= 2) ok = true;
			if (ok == true) break;
			
			if (i*i < 100) {
				printf("%d\n", i*i);
				fflush(stdout);
				scanf("%s", str);
				if (str[0] == 'y' || str[0] == 'Y') {
					ok = true;
				}
			}
		}
	}

	ok ? printf("composite\n") : printf("prime\n");


	return 0;
}