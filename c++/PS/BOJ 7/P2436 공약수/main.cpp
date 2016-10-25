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

int A, B;

ll GCD(ll A, ll B) {
	if (B == 0) return A;
	return GCD(B, A%B);
}

int main() {

	scanf("%d %d", &A, &B);


	if (A == B) {
		printf("%d %d\n", A, B);
		return 0;
	}

	ll ans1, ans2;
	ll a1 = A, a2 = B/A;

	ans1 = A, ans2 = B;

	ll r = B / A;

	for (int i = 1; i <= r; i++) {
		
		if (r%i == 0) {
			ll temp1 = A*i;
			ll temp2 = A*(r / i);

			if (temp1 > temp2) break;

			if (GCD(min(temp1,temp2), max(temp1, temp2)) != A) continue;
			if ((temp1*temp2) / GCD(min(temp1, temp2), max(temp1, temp2)) != B) continue;

			if (temp1 + temp2 < ans1 + ans2) {
				ans1 = temp1;
				ans2 = temp2;
			}
		}
	}
	printf("%lld %lld\n", min(ans1, ans2), max(ans1, ans2));

	return 0;
}