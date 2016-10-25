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
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;

const int TSIZE = 500001;
int n;
pair<int,int> arr[TSIZE];
int BIT[TSIZE];

ll query(int i) {
	ll ret = 0;
	while (i>0) {
		ret += BIT[i];
		i -= i&-i;
	}
	return ret;
}
void update(int i, int val) {
	while (i< TSIZE) {
		BIT[i] += val;
		i += i&-i;
	}
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	sort(arr + 1, arr + n + 1, [](pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first > b.first;
	});
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += query(arr[i].second);
		update(arr[i].second, 1);
	}
	printf("%lld\n", ans);

	// 내림차순 정렬하는 이유
	// 일단 query 날렸을때 걸렸다는 말은 자기보다 index가 작았다는 말이다.
	// index가 작다 = 기존에 자기보다 앞에 있었다
	// 근데 먼저 업데이트가 됬다 - 자기보다 큰 숫자가
	// 이 두가지 상황을 보고 자기보다 앞에 큰 숫자가 몇개 있었는지를 알 수 있다.

	return 0;
}