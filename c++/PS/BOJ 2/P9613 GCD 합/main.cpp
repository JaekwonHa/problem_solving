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

long long gcd(long long a, long long b) {
	long long r = a%b;
	if (r != 0) return gcd(b, r);
	return b;
}
long long lcm(long long a, long long b) {
	return (a*b) / gcd(a, b);
}

int main() {

	long long a, b;
	int n,t;
	cin >> t;
	while (t--) {
		cin >> n;
		long long sum = 0;
		int *arr = new int[n];
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		printf("%lld\n", sum);
	}


	return 0;
}