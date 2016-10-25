#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define INF 987654321

int N, S, X, Y;

int main() {

	scanf("%d %d", &X, &Y);
	if (X < 0) X = -X;
	if (Y < 0) Y = -Y;

	while ((X - 1) % 3 == 0 || X % 3 == 0 || (X + 1) % 3 == 0) {
		if (X % 3 == 0) {
			if ((Y + 1) % 3 == 0) {
				Y++;
			}
			else if ((Y - 1) % 3 == 0) {
				Y--;
			}
			else break;
		}
		else if (Y % 3 == 0) {
			if ((X + 1) % 3 == 0) {
				X++;
			}
			else if ((X - 1) % 3 == 0) {
				X--;
			}
			else break;
		}
		else {
			break;
		}
		X /= 3, Y /= 3;
	}
	if (X == 0 && Y == 0) {
		printf("1\n");
	}
	else printf("0\n");


	return 0;
}