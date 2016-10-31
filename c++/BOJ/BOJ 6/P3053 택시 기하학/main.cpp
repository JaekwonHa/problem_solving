#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <math.h>
using namespace std;

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

//constexpr double const_pi() { return std::atan(1) * 4; }
double pi = M_PI;

int main() {

	double d;
	scanf("%lf", &d);
	printf("%.6lf\n%.6lf\n", d*d*pi, (2 * d)*d);

	return 0;
}