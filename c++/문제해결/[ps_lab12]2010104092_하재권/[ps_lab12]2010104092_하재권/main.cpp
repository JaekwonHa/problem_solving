#include <iostream>
#include <iomanip>
#include <string>

#define NUMBERLENGTH 2500
#define ONEDIGIT 10000

using namespace std;

typedef struct _longlong {
	unsigned int h[NUMBERLENGTH];
} longlong;

static int k,d;

longlong assign(unsigned int b) {
	int i;
	longlong temp;
	for(i=0; i<NUMBERLENGTH; i++) {
		temp.h[i] = b%ONEDIGIT;
		b /= ONEDIGIT;
	}
	return temp;
}
longlong add(const longlong *a, const longlong *b) {
	int i,carry;
	longlong result = assign(0);
	carry = 0;
	for(i=0; i<NUMBERLENGTH; i++) {
		result.h[i] = a->h[i] + b->h[i] + carry;
		carry = result.h[i]/ONEDIGIT;
		result.h[i] %= ONEDIGIT;
	}
	return result;
}
int main() {

	int cases,i,j;
	cin>>cases;
	while(cases--) {
		string X,Z;
		cin>>X>>Z;
		longlong a,b;
		a = assign(1);
		for(j=0; j<X.length(); j++)
			if(X[j]==Z[j]) {

			} else {

			}


	}
}