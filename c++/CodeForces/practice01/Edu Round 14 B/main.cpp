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

map<char, char> m = {
	{ 'A','A' },
	{ 'b','d' },
	{ 'd','b' },
	{ 'H','H' },
	{ 'I','I' },
	{ 'M','M' },
	{ 'O','O' },
	{ 'o','o' },
	{ 'p','q' },
	{ 'q','p' },
	{ 'T','T' },
	{ 'U','U' },
	{ 'V','V' },
	{ 'v','v' },
	{ 'W','W' },
	{ 'w','w' },
	{ 'X','X' },
	{ 'x','x' },
	{ 'Y','Y' }
};


int main() {

	int s;
	char str[1500];
	scanf("%s", str);

	int len = strlen(str);

	int l = 0, r = len - 1;
	bool ok = true;
	if (len == 1) {
		if (m.find(str[l]) == m.end()) ok = false;
		else {
			if (str[l] == 'b' || str[l] == 'p' || str[l] == 'd' || str[l] == 'q') ok = false;
		}
	}
	else {
		while (l < r) {
			if (m.find(str[l]) == m.end()) ok = false;
			else if (m[str[l]] != str[r]) {
				ok = false;
			}
			l++, r--;
		}
		if (len%2==1) {
			int mid = len / 2;
			if (m.find(str[mid]) == m.end()) ok = false;
			else {
				if (str[mid] == 'b' || str[mid] == 'p' || str[mid] == 'd' || str[mid] == 'q') ok = false;
			}
		}
	}
	
	ok ? printf("TAK\n") : printf("NIE\n");

	return 0;
}