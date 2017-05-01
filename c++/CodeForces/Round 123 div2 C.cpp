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

// 정답이 ll 이상일 경우 INF를 98765432100000 정도까지 크게 해야함
// 입력받는 값이 10^9 이고 답이 뭔가 그것들을 더하는 연산이라면 답은 ll 일수 있다
// priority_queue 는 기본적으로 내림차순 정렬이다. 오름차순으로 하고 싶다면 priority_queue<int, vector<int>, greater<int>>
// queue에서 pop하기 전에는 반드시 empty인 경우를 체크하고 예외처리 해줘라


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