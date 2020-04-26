#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int R, G, B;
	cin >> R >> G >> B;

	int r, g, b;
	r = R;
	g = G;
	b = B;

	int ans = min(r, min(g, b));
	R -= ans;
	G -= ans;
	B -= ans;

	if (R == 1 || G == 1 || B == 1) {
		R = max(R - 1, 0);
		G = max(G - 1, 0);
		B = max(B - 1, 0);
		ans++;
	}

	while (R!=0 && R / 3 != 0) {
		ans += R / 3;
		R = R % 3;
	}
	while (G != 0 && G / 3 != 0) {
		ans += G / 3;
		G = G % 3;
	}
	while (B != 0 && B / 3 != 0) {
		ans += B / 3;
		B = B % 3;
	}

	while (R != 0 && R / 2 != 0) {
		ans += R / 2;
		R = R % 2;
	}
	while (G != 0 && G / 2 != 0) {
		ans += G / 2;
		G = G % 2;
	}
	while (B != 0 && B / 2 != 0) {
		ans += B / 2;
		B = B % 2;
	}

	if (R >= 1 || G >= 1 || B >= 1) ans++;

	printf("%d\n", ans);


	return 0;
}