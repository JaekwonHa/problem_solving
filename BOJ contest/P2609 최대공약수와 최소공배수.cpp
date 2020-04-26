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

int gcd(int a, int b) {
	int r = a%b;
	if (r != 0) return gcd(b, r);
	return b;
}
int lcm(int a, int b) {
	return (a*b) / gcd(a, b);
}

int main() {

	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	cout << lcm(a, b) << endl;

	return 0;
}