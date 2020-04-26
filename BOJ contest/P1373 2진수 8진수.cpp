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

char a[1000010];
int arr[1000010];

int main() {

	scanf("%s", a);
	int len = strlen(a);
	unsigned long long sum = 0;
	unsigned long long cnt = 0;
	for (int i = len-1; i>=0; i -= 3) {
		unsigned long long temp = 0;
		for (int j = 0; j < 3 && i - j >= 0; j++) {
			if (a[i - j] - '0' == 0) continue;
			temp += pow(2.0, j);
		}
		arr[cnt] = temp;
		cnt++;
	}
	for (int i = cnt - 1; i >= 0; i--) {
		printf("%d", arr[i]);
	}

	return 0;
}