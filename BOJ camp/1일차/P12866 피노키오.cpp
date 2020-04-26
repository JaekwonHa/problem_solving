#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

#define p 1000000007

int N;
long long number[4];
char arr[1000010];

int main() {

	scanf("%d", &N);
	scanf("%s", arr);

	for (int i = 0; i < N; i++) {
		if (arr[i] == 'A') number[0]++;
		if (arr[i] == 'C') number[1]++;
		if (arr[i] == 'G') number[2]++;
		if (arr[i] == 'T') number[3]++;
	}

	long long ans1 = (number[0] * number[1]) % p;
	long long ans2 = (number[2] * number[3]) % p;
	long long ans = (ans1*ans2) % p;

	printf("%ld", ans);

	return 0;
}
