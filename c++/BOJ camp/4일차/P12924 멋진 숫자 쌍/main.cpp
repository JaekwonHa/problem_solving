#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>

int moveNumber(int n, int len) {
	return n / 10 + (n % 10)*std::pow(10, len-1);
}

int main() {

	int A, B, len=0;
	scanf("%d %d", &A, &B);

	std::map<std::pair<int,int>, int> m;
	int temp = A;
	while (temp>0) {
		len++;
		temp /= 10;
	}
	for (int i = A; i <= B; i++) {
		temp = i;
		for (int j = 1; j < len; j++) {
			temp = moveNumber(temp, len);
			if (temp >= A && temp <= B && temp!=i) {
				int a = std::min(i, temp);
				int b = std::max(i, temp);
				m[std::make_pair(a,b)] = 0;
			}
		}
	}

	printf("%d\n", m.size());

	return 0;
}