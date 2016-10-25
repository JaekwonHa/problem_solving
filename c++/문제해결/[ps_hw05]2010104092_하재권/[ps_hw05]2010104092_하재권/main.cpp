#include <iostream>
#include <math.h>

using namespace std;

double log2(double p) {
	return log10(p)/log10(2.0);
}

int main() {

	double left, right_digit;
	double lower, upper;

	while(cin>>left) {
		lower = log2(left);
		upper = log2(left+1);
		right_digit = ceil(log10(left+0.5))+1;

		while(ceil(lower+right_digit*log2(10)) != floor(upper+right_digit*log2(10))) right_digit++;

		cout<<ceil(lower+right_digit*log2(10))<<endl;
		
	}

	return 0;
}