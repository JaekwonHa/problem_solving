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

int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	for (int i = 0; i<A.size(); i++) {
		int sum1 = 0, sum2 = 0;
		for (int j = 0; j < i; j++) {
			sum1 += A[j];
		}
		for (int j = i + 1; j<A.size(); j++) {
			sum2 += A[j];
		}
		if (sum1 == sum2) {
			return i;
		}
	}
}


int main() {

	freopen("input.txt", "r", stdin);

	vector<int> v;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}

	printf("%d", solution(v));

	return 0;
}