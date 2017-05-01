#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

int B,len;
string N;

int trans(char b) {
	if(b<'A') return b-'0';
	return b-'A'+10;
}

int main() {

	cin>>N;
	cin>>B;
	len=N.length();

	int ans=0;
	for(int i=len-1; i>=0; i--) {
		int a = trans(N[i]);
		ans += a*pow((double)B,len-i-1);
	}

	printf("%d\n", ans);
	return 0;
}