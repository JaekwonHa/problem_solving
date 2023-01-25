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
pair<char, int> arr[100001];

int main() {

	scanf("%s", str);

	int i = 0;
	for (char c : str) {
		arr[i] = mp(c, i);
		i++;
	}

	int len = strlen(str);
	sort(arr, arr + len, [](pair<char, int> a, pair<char, int> b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first > b.first;
	});

	char *ans = new char[len+1];
	int last = arr[0].second;
	ans[0] = arr[0].first;
	int j = 1;
	for (i = 1; i < len; i++) {
		if (last < arr[i].second) {
			ans[j++] = arr[i].first;
			last = arr[i].second;
		}
	}
	ans[j] = '\0';
	cout << ans << endl;
	

	return 0;
}