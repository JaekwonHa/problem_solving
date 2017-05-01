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


int main() {

	ll n, m, a;
	scanf("%lld %lld %lld", &n, &m, &a);

	if (n%a != 0) n += a;
	if (m%a != 0) m += a;

	printf("%lld\n", (n / a)*(m / a));

	return 0;
}