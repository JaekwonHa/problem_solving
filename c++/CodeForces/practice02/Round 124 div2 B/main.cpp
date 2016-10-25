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


int n, m;
int a[110], b[110];

int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a%b);
}

int main() {
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i <= m; i++) {
		scanf("%d", &b[i]);
	}

	if (n > m) {
		if (a[0]*b[0] < 0) {
			printf("-");
		}
		printf("Infinity\n");
	}
	else if (n < m) {
		printf("0/1\n");
	}
	else {
		int divA = max(abs(a[0]), abs(b[0]));
		int divB = min(abs(a[0]), abs(b[0]));
		if (a[0] * b[0] < 0) printf("-");
		printf("%d/%d\n", abs(a[0] / GCD(divA, divB)), abs(b[0] / GCD(divA, divB)));
	}

	return 0;
}