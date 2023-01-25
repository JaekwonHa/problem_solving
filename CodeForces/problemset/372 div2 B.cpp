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

string str;
int cnt;
int dup['Z' + 1];

bool valid(int start, int first) {
	bool ok = false;
	if (first) {
		for (int i = start; i < start + 26; i++) {
			if (str[i] == '?') cnt++;
			else {
				dup[str[i]]++;
				if (dup[str[i]] == 1) cnt++;
			}
		}

		if (cnt == 26) ok = true;
	}
	else if(str.length() - start >= 26) {
		if (str[start-1] != '?') {
			dup[str[start-1]]--;
			if (dup[str[start-1]] == 0) cnt--;
		}
		else {
			cnt--;
		}
		if (str[start + 25] != '?') {
			dup[str[start + 25]]++;
			if (dup[str[start + 25]] == 1) cnt++;
		}
		else {
			cnt++;
		}

		if (cnt == 26) ok = true;
	}

	return ok;
}

void fillStr(int start) {
	int cur = 'A';
	while (dup[cur] > 0) cur++;
	for (int i = start; i < start + 26; i++) {
		if (str[i] == '?') {
			str[i] = cur;
			dup[cur]++;
			while (dup[cur] > 0) cur++;
		}
	}
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '?') {
			str[i] = 'A';
		}
	}
}

int main() {

	cin >> str;

	bool ok = false;
	if (str.length() >= 26) {
		for (int i = 0; i <= str.length() - 25; i++) {
			ok = valid(i, i == 0 ? 1 : 0);
			if (ok) {
				fillStr(i);
				break;
			}
		}
	}
	

	ok ? cout << str << endl : cout << "-1" << endl;

	return 0;
}