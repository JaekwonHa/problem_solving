#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int DP[31];

int f(int n) {
	if(n==0 || n==1) return 1;
	if(n<0) return 0;

	int& ret = DP[n];
	if(ret!=-1) return ret;

	ret = 0;
	if(n%2==0) {
		ret = f(n/2) * f(n/2) + 2*f(n/2-1) * f(n/2-1);
	} else {
		ret = f(n/2) * f(n/2+1) + 2*f(n/2-1) * f(n/2);
	}
	return ret;
}

int main() {

	cin>>N;

	memset(DP,-1,sizeof(DP));
	/*
	int s=f(N/2+!(N%2));
	printf("%d",f(N)-(f(N)-s)/2);

	*/
	if(N%2==0) {
		cout<<f(N)-f(N/2)<<endl;
	} else {
		cout<<f(N)-f(N/2)<<endl;
	}
	

	return 0;
}