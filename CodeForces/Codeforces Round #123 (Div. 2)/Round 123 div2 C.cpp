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

int n, pos, parent;
tuple<string, string, int> tree[1000000];
int start;

stack<tuple<string, string, int>> st;

int main() {

	char str[101];
	pos = 1;

	scanf("%d", &n);

	string ans;
	bool ok = false;
	bool isMeetThrow = false;
	string throwName;
	int tryCnt = 0;
	fgets(str, 100, stdin);

	for (int i = 0; i < n; i++) {
		fgets(str, 100, stdin);

		if (ok) continue;

		int length = strlen(str);
		for (int j = 0; j < length-1; j++) {
			if (str[j] == 't' && str[j+1] == 'r') {
				if (isMeetThrow) {
					tryCnt++;
				}
				break;
			}
			if (str[j] == 't' && str[j + 1] == 'h') {
				isMeetThrow = true;
				int cur = j;
				while (str[cur] != '(') {
					cur++;
				}
				cur++;
				while (str[cur] == ' ') {
					cur++;
				}
				string s1, s2;
				while (str[cur] != ' ' && str[cur] != ')') {
					throwName.push_back(str[cur]);
					cur++;
				}
				break;
			}
			if (str[j] == 'c') {

				parent--;
				int cur = j;
				while (str[cur] != '(') {
					cur++;
				}
				cur++;
				while (str[cur] == ' ') {
					cur++;
				}
				string s1, s2;
				while (str[cur] != ',' && str[cur] != ' ') {
					s1.push_back(str[cur]);
					cur++;
				}
				while (str[cur] != '\"') {
					cur++;
				}
				cur++;
				while (str[cur] != '\"') {
					s2.push_back(str[cur]);
					cur++;
				}
				if (isMeetThrow && tryCnt == 0) {
					if (s1.compare(throwName) == 0) {
						ans = s2;
						ok = true;
					}
				}
				if (isMeetThrow && tryCnt > 0) {
					tryCnt--;
				}
				break;
			}
		}
	}
	if (ok) {
		printf("%s\n", ans.c_str());
	}
	else {
		printf("Unhandled Exception\n");
	}
	


	return 0;
}