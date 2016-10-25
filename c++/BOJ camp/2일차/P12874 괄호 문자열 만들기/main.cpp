#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

#define p 1000000007

long long DP[101][101];
char str[110];

long long f(int n, int open) {
	if (open < 0) return 0;

	long long &ret = DP[n][open];
	if (ret != -1) return ret;

	if (open == 0) ret = 1;
	else ret = 0;
	
	char type;
	int plus;
	for (int i = 0; i < 2; i++) {
		if (i == 0) type = '(', plus=1;
		else type = ')', plus=-1;
		for (int j = n+1; j < strlen(str); j++) {
			if (type == str[j]) {
				ret += f(j, open + plus);
				break;
			}
		}
	}
	ret = ret%p;
	return ret;
}

int main() {

	str[0] = ' ';
	cin >> str+1;
	memset(DP, -1, sizeof(DP));
	
	cout << f(0, 0)-1 << endl;

	return 0;
}