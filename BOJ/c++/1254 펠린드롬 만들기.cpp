#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int len,m;
string str;

bool isAnswer(int left, int right) {
	while(0<=left && right<len) {
		if(str[left]!=str[right]) {
			return false;
		}
		left--,right++;
	}
	return true;
}

int main() {

	cin>>str;
	len = str.length();

	int ans;
	m = len/2;
	while(1) {
		if(isAnswer(m-1,m)==true) {
			ans = m*2;
			break;
		}
		if(isAnswer(m,m)==true) {
			ans = m*2+1;
			break;
		}
		m++;
	}

	bool check=true;
	for(int i=1; i<len; i++) {
		if(str[0]!=str[i]) check=false;
	}
	if(check==true) ans=len;

	cout<<ans<<endl;
	return 0;
}