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

	map<int,int> m;
	int a;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a);
		m[a % 42]++;
	}

	printf("%d\n", m.size());

	return 0;
}