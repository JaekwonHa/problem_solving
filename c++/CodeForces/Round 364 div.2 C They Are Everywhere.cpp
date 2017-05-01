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

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int n, type, cnt;
char c;
char chk['z'+1];
int arr[100001];
int A[100001];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &c);
		if (chk[c] == 0) chk[c] = ++type, arr[i]=chk[c];
		else arr[i] = chk[c];
	}
	int last = 0;
	int ans = n;
	for (int i = 0; i < n; i++) {
		while (last < n && cnt < type) {
			if (A[arr[last]] == 0) A[arr[last]]++, cnt++;
			else A[arr[last]]++;
			last++;
		}
		if (cnt < type) break;
		ans = min(ans, last - i);
		A[arr[i]]--;
		if (A[arr[i]] == 0) cnt--;
	}
	printf("%d\n", ans);
	return 0;
}