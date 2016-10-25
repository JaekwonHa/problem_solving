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
#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;


int main() {

	char str[51];
	scanf("%s", str);

	int sum = 0, t = 0;
	int len = strlen(str);
	vector<int> pos;
	for (int i = 0; i < len; i++) {
		if (str[i] == '-') {
			pos.push_back(i);
		}
	}
	pos.push_back(len);
	for (int i = 0; i < pos[0]; i++) {
		if (str[i] == '+') {
			sum += t;
			t = 0;
		}
		else {
			t *= 10;
			t += str[i] - '0';
		}
	}
	sum += t;
	for (int i = 0; i < pos.size() - 1; i++) {
		t = 0;
		for (int j = pos[i] + 1; j < pos[i + 1]; j++) {
			if (str[j] != '+') {
				t *= 10;
				t += str[j] - '0';
			}
			else {
				sum -= t;
				t = 0;
			}
		}
		sum -= t;
		t = 0;
	}

	printf("%d\n", sum);

	return 0;
}