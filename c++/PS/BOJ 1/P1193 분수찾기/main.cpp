#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
using namespace std;

#define INF 987654321
#define p 1000000007
typedef long long ll;


int main() {

	int N,x,y,d;
	scanf("%d", &N);

	int n = 1, sum = 1;
	while (sum<N) {
		n++;
		sum = ((n+1)*n) / 2;
	}
	n--;
	sum = ((n + 1)*n) / 2;
	d = N - sum - 1;
	if (n % 2 == 1) {
		x = 1 + d;
		y = n + 1 - d;
	}
	else {
		x = n + 1 - d;
		y = 1 + d;
	}
	printf("%d/%d\n", x, y);
	return 0;
}