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
#define p 1000000007
typedef long long ll;

vector<int> month = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main() {


	int x, y;
	cin >> x >> y;
	int sum = 0;
	for (int i = 1; i < x; i++) {
		sum += month[i];
	}
	sum += y;
	sum--;
	switch (sum % 7) {
	case 0:
		cout << "MON" << endl;
		break;
	case 1:
		cout << "TUE" << endl;
		break;
	case 2:
		cout << "WED" << endl;
		break;
	case 3:
		cout << "THU" << endl;
		break;
	case 4:
		cout << "FRI" << endl;
		break;
	case 5:
		cout << "SAT" << endl;
		break;
	case 6:
		cout << "SUN" << endl;
		break;
	}

	return 0;
}