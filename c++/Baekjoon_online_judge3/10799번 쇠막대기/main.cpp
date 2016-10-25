#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

stack<char> S;
int ans;
bool laser;

int main() {

	string str;
	cin>>str;
	istringstream is(str);
	
	char temp;
	while(is>>temp) {
		if(temp=='(') {
			S.push(temp);
			laser=true;
		} else {
			if(laser==true) {
				laser=false;
				S.pop();
				ans+=S.size();
			} else {
				S.pop();
				ans+=1;
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}