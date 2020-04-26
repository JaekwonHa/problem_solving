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

// 정답이 ll 이상일 경우 INF를 98765432100000 정도까지 크게 해야함
// 입력받는 값이 10^9 이고 답이 뭔가 그것들을 더하는 연산이라면 답은 ll 일수 있다
// priority_queue 는 기본적으로 내림차순 정렬이다. 오름차순으로 하고 싶다면 priority_queue<int, vector<int>, greater<int>>
// queue에서 pop하기 전에는 반드시 empty인 경우를 체크하고 예외처리 해줘라


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