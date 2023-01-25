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

int R, C, N;
map<pair<int, int>, int> v;

bool check(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	bool ok = true;

	if (x1 > 0 && x1 <= R && y1 > 0 && y1 <= C && x4 > 0 && x4 <= R && y4 > 0 && y4 <= C) {
		int cnt = 0;

		if (v.find(mp(x1, y1)) == v.end()) cnt++;
		if (v.find(mp(x2, y2)) == v.end()) cnt++;
		if (v.find(mp(x3, y3)) == v.end()) cnt++;
		if (v.find(mp(x4, y4)) == v.end()) cnt++;

		if (cnt == 1) {
			if (v.find(mp(x1, y1)) == v.end()) {
				int t = v[mp(x2, y2)] + v[mp(x3, y3)] - v[mp(x4, y4)];
				if (t < 0) ok = false;
				else {
					v[mp(x1, y1)] = t;
				}
			}
			if (v.find(mp(x2, y2)) == v.end()) {
				int t = v[mp(x1, y1)] + v[mp(x4, y4)] - v[mp(x3, y3)];
				if (t < 0) ok = false;
				else {
					v[mp(x2, y2)] = t;
				}
			}
			if (v.find(mp(x3, y3)) == v.end()) {
				int t = v[mp(x1, y1)] + v[mp(x4, y4)] - v[mp(x2, y2)];
				if (t < 0) ok = false;
				else {
					v[mp(x3, y3)] = t;
				}
			}
			if (v.find(mp(x4, y4)) == v.end()) {
				int t = v[mp(x2, y2)] + v[mp(x3, y3)] - v[mp(x1, y1)];
				if (t < 0) ok = false;
				else {
					v[mp(x4, y4)] = t;
				}
			}
		}
		else if (cnt == 0) {
			if (v[mp(x1, y1)] + v[mp(x4, y4)] != v[mp(x2, y2)] + v[mp(x3, y3)]) {
				ok = false;
			}
		}
	}
	return ok;
}

int main() {

	scanf("%d %d", &R, &C);
	scanf("%d", &N);
	
	
	bool ok = true;
	for (int i = 1; i <= N; i++) {
		int r, c, a;
		scanf("%d %d %d", &r, &c, &a);

		if (!ok) continue;

		if(v.find(mp(r,c)) == v.end()) v[mp(r,c)] = a;
		else {
			if (v[mp(r, c)] != a) {
				ok = false;
			}
		}
		
		ok &= check(r - 1, c - 1, r - 1, c, r, c - 1, r, c);
		ok &= check(r - 1, c, r - 1, c + 1, r, c, r, c + 1);
		ok &= check(r, c - 1, r, c, r + 1, c - 1, r + 1, c);
		ok &= check(r, c, r, c + 1, r + 1, c, r + 1, c + 1);
	}
	

	if (ok) printf("Yes\n");
	else printf("No\n");

	return 0;
}