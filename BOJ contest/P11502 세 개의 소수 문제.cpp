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

int primeTable[1200];
vector<int> v;
vector<int> ans;

pair<int,int> DP[1200][4];

bool f(int n, int pos, int cnt) {
	if (n == 0 && cnt == 0) return true;
	if (cnt <= 0 || pos < 0 || n < 0) return false;
	
	//if (n > v[pos] * cnt) return false;
	/*
	int retN, retPos;
	tie(retN, retPos) = DP[n][cnt];

	if (retN != -1) {
		ans.push_back(n);
		return f(retN, retPos, cnt - 1);
	}
	*/

	if (f(n, pos - 1, cnt)) {
		//DP[n][cnt] = mp(n, cnt);
		return true;
	}
	if (f(n - v[pos], pos, cnt - 1)) {
		ans.push_back(v[pos]);
		//DP[n][cnt] = mp(n - v[pos], cnt);
		return true;
	}
	return false;
}

int main() {

	for (int i = 2; i <= 1100; i++) {
		if (primeTable[i] == 0) {
			for (int j = i + i; j <= 1100; j += i) {
				primeTable[j] = 1;
			}
		}
	}
	for (int i = 2; i <= 1100; i++) {
		if (primeTable[i] == 0) {
			v.push_back(i);
		}
	}
	for (int i = 0; i < 1100; i++) {
		DP[i][0] = mp(-1, -1);
		DP[i][1] = mp(-1, -1);
		DP[i][2] = mp(-1, -1);
		DP[i][3] = mp(-1, -1);
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		ans.clear();
		int a;
		scanf("%d", &a);

		int start = 0;
		while (v[start] <= a) {
			start++;
		}
		start--;

		if (!f(a, start, 3)) {
			printf("0\n");
		}
		else {
			sort(ans.begin(), ans.end());
			for (int i : ans) {
				printf("%d ", i);
			}
			printf("\n");
		}
	}

	return 0;
}