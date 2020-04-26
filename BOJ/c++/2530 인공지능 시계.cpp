#include <iostream>
#include <algorithm>
using namespace std;

int A,B,C,D;

int main() {

	scanf("%d %d %d", &A, &B, &C);
	scanf("%d", &D);

	C = C+D;
	B = B+ C/60;
	C = C%60;
	A = A+ B/60;
	B = B%60;

	if(A>23) {
		A = A%24;
	}

	printf("%d %d %d", A,B,C);

	return 0;
}