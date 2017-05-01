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

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

const int HOUSE=1234567;
const int CAR=123456;
const int COM=1234;

int main() {
	
	int n;
	int a = 0, b = 0, c = 0;
	scanf("%d", &n);

	bool ok = false;
	for (; a*HOUSE + b*CAR + c*COM <= n; a++) {
		for (; a*HOUSE + b*CAR + c*COM <= n; b++) {
			if ((n - a*HOUSE - b*CAR) % COM == 0) {
				ok = true;
				break;
			}
		}
		b = 0;
		if (ok) break;
	}
	ok ? printf("YES\n") : printf("NO\n");

	return 0;
}