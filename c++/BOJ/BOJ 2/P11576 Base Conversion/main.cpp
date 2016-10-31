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

int arr[30];
int ans[100];

int main() {

	int N, A, B,m;
	scanf("%d %d", &A, &B);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%d", arr + i);

	long long dec = 0;
	for (int i = m - 1, j=0; i >= 0; i--,j++) {
		dec += arr[i]*pow(A, j);
	}

	int cnt = 0;
	while (dec) {
		ans[cnt] = dec%B;
		dec /= B;
		cnt++;
	}
	for (int i = cnt - 1; i >= 0; i--) {
		printf("%d ", ans[i]);
	}


	return 0;
}