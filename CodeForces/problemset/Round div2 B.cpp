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

int n, arr[101];
int ans = 0;

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);


	
	bool ok = true;
	while (ok) {
		ok = false;
		for (int i = 0; i < n-1; i++) {
			if (arr[i] > arr[i + 1]) {
				ok = true;
				swap(arr[i], arr[i + 1]);
				printf("%d %d\n", i+1, i + 2);
			}
		}
	}


	return 0;
}