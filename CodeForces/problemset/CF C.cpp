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

char str[100010];
int K;

int main() {

	scanf("%s", str);
	scanf("%d", &K);

	int MAX = 'z' + 1;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] == 'a') continue;
		int d = MAX - str[i];
		if (d <= K) {
			str[i] = 'a';
			K -= d;
		}
	}
	for (int i = 0; i < len; i++) {
		int d = MAX - str[i];
		if (d <= K) {
			str[i] = 'a';
			K -= d;
		}
	}
	if (K != 0) {
		int t = str[len - 1] - 'a';
		t = (t + K) % 26;
		str[len - 1] = 'a' + t;
	}
	printf("%s\n", str);

	return 0;
}