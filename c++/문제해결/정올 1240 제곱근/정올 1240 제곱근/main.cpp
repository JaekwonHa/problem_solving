#include <iostream>

using namespace std;

int main() {

	double number,X;
	int i;

	cin>>number;

	X = number;
	i=500;
	while(i--) {
		X = (X+number/X)/2;
	}
	cout<<(long long int)X<<endl;

	return 0;
}