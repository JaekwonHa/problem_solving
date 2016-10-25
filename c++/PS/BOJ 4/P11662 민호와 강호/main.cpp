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

	ll Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &Ax, &Ay, &Bx, &By, &Cx, &Cy, &Dx, &Dy);

	ll a, b, c, d;
	double t;
	a = Cx - Ax;
	b = Dx - Cx - Bx + Ax;
	c = Cy - Ay;
	d = Dy - Cy - By + Ay;
	t = -((a*b + c*d) / (double)(b*b + d*d));

	double dist = 0;

	if (t < 0+1e-9 || b == 0 && d == 0) {
		dist = a*a + c*c;
	}
	else {
		if (t > 1 + 1e-9) {
			dist = (Bx - Dx)*(Bx - Dx) + (By - Dy)*(By - Dy);
		}
		else {
			dist = a*a + c*c - (a*b + c*d)*(a*b + c*d) / (double)(b*b + d*d);
		}
	}
	printf("%.10lf\n", sqrt(dist));

	return 0;
}