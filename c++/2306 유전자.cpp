#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char str[510];
int DP[510][510];
int len;

int f(int left, int right) {
	if(left>=right) return 0;

	int &ret = DP[left][right];
	if(ret != -1) return ret;

	ret = 0;
	if(str[left]=='a' && str[right]=='t') ret = 2+f(left+1,right-1);
	if(str[left]=='g' && str[right]=='c') ret = 2+f(left+1,right-1);

	for(int k=left; k<right; k++) {
		ret = max(ret, f(left,k)+f(k+1,right));
	}

	return ret;
}

int main() {

	scanf("%s", &str);
	len = strlen(str);
	memset(DP,-1,sizeof(DP));

	printf("%d\n", f(0,len-1));

	return 0;
}