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

int n,a;

int main() {

	scanf("%d", &n);

	vector<int> v;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		v.push_back(a);
	}
	int cur = 1;
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (v[i] >= cur) cur++;
	}

	printf("%d\n", cur);

	return 0;
}