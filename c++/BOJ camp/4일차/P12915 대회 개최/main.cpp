#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

void divideProblem(int &a, int &b, int &c) {
	if (a < c) {
		a += 1;
		b -= 1;
	}
	else {
		c += 1;
		b -= 1;
	}
}

int main() {

	int E, EM, M, MH, H;
	scanf("%d %d %d %d %d", &E, &EM, &M, &MH, &H);


	while (EM > 0 || MH > 0) {
		if (EM == 0) {
			divideProblem(M, MH, H);
		}
		else if (MH == 0) {
			divideProblem(M, EM, E);
		}
		else {
			if (EM < MH) {
				divideProblem(M, MH, H);
			}
			else {
				divideProblem(M, EM, E);
			}
		}
	}
	int ans = std::min(E, M);
	ans = std::min(ans, H);

	printf("%d\n", ans);

	return 0;
}