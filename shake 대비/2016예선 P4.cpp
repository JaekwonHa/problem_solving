#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define INF 987654321

int N,len;
int DP[1010];
char arr[1010];

int f(char type, int n) {
	if(n==len-1) return 0;
	if(n>=len) return INF;
	
	int& ret = DP[n];
	if(ret != -1) return ret;

	char nextType;
	if(type=='B') nextType='O';
	if(type=='O') nextType='J';
	if(type=='J') nextType='B';
	ret=INF;
	for(int i=n+1; i<len; i++) {
		if(arr[i]==nextType) {
			ret = min(ret,f(nextType,i)+(i-n)*(i-n));
		}
	}
	return ret;
}

int main() {

	cin>>N;
	cin>>arr;
	len=strlen(arr);
	memset(DP,-1,sizeof(DP));

	int ans = f('B',0);
	(ans>=INF)?cout<<-1<<endl : cout<<ans<<endl;

	return 0;
}