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

char str1[1010], str2[1010];
int DP[1010][1010];
int len, len1, len2;

int f(int pos1, int pos2) {
	if (pos1 >= len1 || pos2 >= len2) return 0;
	
	int& ret = DP[pos1][pos2];
	if (ret != -1) return ret;

	ret = 0;
	ret = max(ret, f(pos1 + 1, pos2));
	ret = max(ret, f(pos1, pos2 + 1));
	if (str1[pos1] == str2[pos2]) {
		ret = max(ret, 1 + f(pos1 + 1, pos2 + 1));
	}

	return ret;
}

void print_path() {
	int pos1 = 0, pos2 = 0, offset, cnt=0;

	while (cnt < len) {
		offset = 0;
		while (DP[pos1][pos2] == DP[pos1][pos2 + offset]) {
			offset++;
		}
		offset--;
		pos2 += offset;

		offset = 0;
		while (DP[pos1][pos2] == DP[pos1 + offset][pos2]) {
			offset++;
		}
		offset--;
		pos1 += offset;

		printf("%c", str1[pos1]);
		cnt++, pos1++, pos2++;
	}
	printf("\n");
}

int main() {

	scanf("%s", str1);
	scanf("%s", str2);

	memset(DP, -1, sizeof(DP));
	len1 = strlen(str1);
	len2 = strlen(str2);
	if (len1 < len2) {
		swap(str1, str2);
		swap(len1, len2);
	}

	len = f(0, 0);
	printf("%d\n", len);
	print_path();

	return 0;
}