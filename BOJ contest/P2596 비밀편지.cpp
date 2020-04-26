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

map<char, string> m = {
	{'A', "000000"},
	{'B', "001111"},
	{'C', "010011"},
	{'D', "011100"},
	{'E', "100110"},
	{'F', "101001"},
	{'G', "110101"},
	{'H', "111010"}
};
int N;
string str;
string ans;

int checkNumber(string str1, string str2) {
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		if (str1[i] != str2[i]) cnt++;
	}
	if (cnt >= 2) return 0;
	return 1;
}

int main() {

	scanf("%d", &N);
	cin >> str;

	for (int i = 0; i < str.length(); i += 6) {
		int cnt = 0;
		for (auto a : m) {
			int t = checkNumber(a.second, str.substr(i, i + 6));
			if (t == 1) {
				ans.push_back(a.first);
				cnt += t;
			}
		}
		if (cnt != 1) {
			printf("%d\n", i / 6 + 1);
			return 0;
		}
	}
	printf("%s\n", ans.c_str());

	return 0;
}