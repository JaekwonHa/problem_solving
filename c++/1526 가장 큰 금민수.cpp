#include <iostream>
#include <algorithm>
using namespace std;

int N;
bool isPromise(int n) {
	while(n>0) {
		if(n%10!=4 && n%10!=7) return false;
		n/=10;
	}
	return true;
}

int main() {

	scanf("%d", &N);
	while(N>0) {
		if(isPromise(N)) break;
		N--;
	}
	printf("%d\n", N);

	return 0;
}