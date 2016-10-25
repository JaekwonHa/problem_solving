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

char str[100010];
pair<char, int> arr[100001];

int main() {

	scanf("%s", str);

	int i = 0;
	for (char c : str) {
		arr[i] = mp(c, i);
		i++;
	}

	int len = strlen(str);
	sort(arr, arr + len, [](pair<char, int> a, pair<char, int> b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first > b.first;
	});

	char *ans = new char[len+1];
	int last = arr[0].second;
	ans[0] = arr[0].first;
	int j = 1;
	for (i = 1; i < len; i++) {
		if (last < arr[i].second) {
			ans[j++] = arr[i].first;
			last = arr[i].second;
		}
	}
	ans[j] = '\0';
	cout << ans << endl;
	

	return 0;
}