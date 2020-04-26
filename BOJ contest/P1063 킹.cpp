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


#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int dx[8] = { 0,0,-1,1,-1,-1,1,1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
int kx, ky, sx, sy;
map<string, int> m = {
	{ "R", 0 },
	{ "L", 1 },
	{ "B", 2 },
	{ "T", 3 },
	{ "RT", 6 },
	{ "LT", 7 },
	{ "RB", 4 },
	{ "LB", 5 }
};

int main() {

	string str;
	int N;
	cin >> str;
	kx = str[1];
	ky = str[0];
	cin >> str;
	sx = str[1];
	sy = str[0];
	cin >> N;
	while (N--) {
		cin >> str;
		int nextKX, nextKY;
		nextKX = kx + dx[m[str]];
		nextKY = ky + dy[m[str]];
		if (nextKX < '1' || nextKX > '8' || nextKY < 'A' || nextKY > 'H') continue;
		if (nextKX == sx && nextKY == sy) {
			int nextSX = sx + dx[m[str]];
			int nextSY = sy + dy[m[str]];
			if (nextSX < '1' || nextSX > '8' || nextSY < 'A' || nextSY > 'H') continue;
			sx = nextSX;
			sy = nextSY;
		}
		kx = nextKX;
		ky = nextKY;
	}

	cout << (char)ky << (char)kx << endl;
	cout << (char)sy << (char)sx << endl;

	return 0;
}