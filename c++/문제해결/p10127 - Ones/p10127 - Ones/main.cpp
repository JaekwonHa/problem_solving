#include <iostream>

using namespace std;

int main() {

	int number, result, remainder;

	while(cin>>number) {
		remainder=0;
		result=0;
		do {
			remainder = remainder*10+1;
			result++;
			if(number > remainder) {
				continue;
			}
			remainder %= number;
		} while(remainder!=0);
		cout<<result<<endl;
	}

	return 0;
}