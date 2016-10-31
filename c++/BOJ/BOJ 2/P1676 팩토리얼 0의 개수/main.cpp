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


int main() {

	int n;
	scanf("%d", &n);
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		int t = i;
		while (t%2 == 0) {
			a++;
			t /= 2;
		}
		t = i;
		while (t % 5 == 0) {
			b++;
			t /= 5;
		}
	}
	printf("%d\n", min(a, b));
	return 0;
}