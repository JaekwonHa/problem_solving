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


#define INF 9876543210
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int cnt['Z' + 1];

int main() {

	string str;
	cin >> str;

	if (str.length() % 2 == 1) {
		printf("-1\n");
	}
	else {
		for (char c : str) {
			cnt[c]++;
		}
		int ans = 0;
		if ((cnt['L'] + cnt['R']) % 2 == 1 && (cnt['U'] + cnt['D']) % 2 == 1) {
			ans = (abs(cnt['L'] - cnt['R']) + abs(cnt['U'] - cnt['D'])) / 2;
		}
		else {
			ans = abs(cnt['L'] - cnt['R'])/2 + abs(cnt['U'] - cnt['D'])/2;
		}
		printf("%d\n", ans);
	}


	return 0;
}