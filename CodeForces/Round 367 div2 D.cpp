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

struct Point {
	int one, zero, onePos, zeroPos;
} point[10000100];

int q, pos = 1;

int main() {

	scanf("%d", &q);
	char c;
	int a;
	for (int j =1; j <=q; j++) {
		if (j == 0)
		{
			c = '+';
			a = 0;
		}
		else scanf(" %c %d", &c, &a);
		
		int aa = a;
		int bit[32];
		for (int i = 0; i < 32; i++) {
			bit[i] = a % 2;
			a /= 2;
		}

		if (c == '+') {
			int v = 1;
			for (int i = 31; i >= 0; i--) {
				if (bit[i] == 1) {
					point[v].one++;
					if (point[v].onePos == 0) {
						point[v].onePos = ++pos;
					}
					v = point[v].onePos;
				}
				else {
					point[v].zero++;
					if (point[v].zeroPos == 0) {
						point[v].zeroPos = ++pos;
					}
					v = point[v].zeroPos;
				}
			}
		}
		else if (c == '-') {
			int v = 1;
			for (int i = 31; i >= 0; i--) {
				if (bit[i] == 1) {
					point[v].one--;
					v = point[v].onePos;
				}
				else {
					point[v].zero--;
					v = point[v].zeroPos;
				}
			}
		}
		else {
			int ans = 0;
			int v = 1;
			for (int i = 31; i >= 0; i--) {
				if (bit[i] == 1) {
					if (point[v].zero > 0) {
						ans += (1 << i);
						v = point[v].zeroPos;
					}
					else {
						
						v = point[v].onePos;
					}

				}
				else {
					if (point[v].one > 0) {
						v = point[v].onePos;
						ans += (1 << i);
					}
					else {
						v = point[v].zeroPos;
					}
				}
			}
			printf("%d\n", max(ans,aa));
		}
	}


	return 0;
}