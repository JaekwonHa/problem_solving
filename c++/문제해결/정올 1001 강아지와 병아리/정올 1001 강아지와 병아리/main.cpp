#include <iostream>

using namespace std;

int main() {

	int sum1, sum2;

	while(cin>>sum1>>sum2) {
		if(sum1 == 0) break;
		if(sum1>1000 || sum2>4000) {
			cout<<"INPUT ERROR!"<<endl;
			continue;
		}
		if(sum2%2!=0) {
			cout<<"0"<<endl;
			continue;
		}
		sum2/=2;
		int a = sum2 - sum1;
		int b = sum1 - a;

		if(a<0 || b<0) {
			cout<<"0"<<endl;
			continue;
		}
		cout<<a<<" "<<b<<endl;
	}

	return 0;
}