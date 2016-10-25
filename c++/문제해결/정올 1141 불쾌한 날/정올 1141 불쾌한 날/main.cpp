#include <iostream>
#include <stack>

using namespace std;

int main() {

	int cases,i, high;
	unsigned int count=0;
	stack<int> cow;

	cin>>cases;

	for(i=0; i<cases; i++) {
		cin>>high;
		
		if(cow.size() == 0) cow.push(high);
		else {
			while(cow.size() != 0 && high >= cow.top()) cow.pop();
			count += cow.size();
			cow.push(high);
		}
	}
	cout<<count<<endl;

	return 0;
}