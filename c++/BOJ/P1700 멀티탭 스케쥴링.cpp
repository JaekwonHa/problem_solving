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

int arr[200];
int multiTap[200];

int n, k, a, ans = 0;

int main() {

	freopen("input.txt", "r", stdin);

	
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) scanf("%d", &arr[i]);
	
	

	for (int i = 0; i < k; i++) {
		int last = 0;
		int switchMultiTap = 0;
		for (int j = 1; j <= n; j++) {
			if (arr[i] == multiTap[j]) { last = 0; break; }
			if (multiTap[j] == 0) {
				last = 0;
				multiTap[j] = arr[i];
				break;
			}
			int last2 = 0;
			for (int z = i + 1; z < k; z++) {
				if (multiTap[j] == arr[z]) { last2 = z; break; }
			}
			if (last2 == 0) { last2 = INF; }
			if (last2 > last) {
				last = last2;
				switchMultiTap = j;
			}
		}
		if (last == 0) continue;
		multiTap[switchMultiTap] = arr[i];
		ans++;
	}


	printf("%d\n", ans);

	return 0;
}