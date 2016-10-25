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
	int cnt = 0;
	int len = strlen(a);
	for (int i = len - 1; i >= 0; i--) {
		int b = a[i] - '0';
		if (b == 1) {
			arr[cnt] = 1;
		}
		else if (b == 2) {
			arr[cnt+1] = 1;
		}
		else if (b == 3) {
			arr[cnt] = 1;
			arr[cnt+1] = 1;
		}
		else if (b == 4) {
			arr[cnt+2] = 1;
		}
		else if (b == 5) {
			arr[cnt] = 1;
			arr[cnt+2] = 1;
		}
		else if (b == 6) {
			arr[cnt+1] = 1;
			arr[cnt+2] = 1;
		}
		else if (b == 7) {
			arr[cnt] = 1;
			arr[cnt+1] = 1;
			arr[cnt+2] = 1;
		}
		cnt++, cnt++, cnt++;
	}
	while (arr[cnt] == 0) cnt--;
	for (int i = cnt--; i >= 0; i--) {
		printf("%d", arr[i]);
	}

	return 0;
}