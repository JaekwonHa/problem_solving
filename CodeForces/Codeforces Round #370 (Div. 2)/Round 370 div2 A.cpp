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
ll A[100001];
ll B[100001];

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%I64d", &A[i]);
	}

	B[N - 1] = A[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		B[i] = A[i + 1] + A[i];
	}

	for (int i = 0; i < N; i++) {
		printf("%I64d ", B[i]);
	}

	return 0;
}