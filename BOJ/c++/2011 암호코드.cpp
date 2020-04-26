#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

#define MAXN 5010
#define p 1000000

int arr[MAXN],DP[MAXN],len;

// 0으로 시작하는 암호는 없다. !!

int f(int x) {
	if(x>len) return 1;
	if(arr[x]==0) return 0;
	int ret = DP[x];
	if(ret==-1) {
		DP[x]=0;
		if(x+1<=len) {
			if(arr[x]*10+arr[x+1]<=26)
				DP[x] = (DP[x]+f(x+2))%p;
		}
		DP[x] = (DP[x]+f(x+1))%p;
		ret = DP[x];
	}
	return ret;
}

int main() {
	string str;
	cin>>str;
	len = str.length();
	for(int i=1; i<=len; i++) arr[i]=str[i-1]-'0';
	fill(DP,DP+len+1,-1);

	printf("%d\n", f(1));
	return 0;
}