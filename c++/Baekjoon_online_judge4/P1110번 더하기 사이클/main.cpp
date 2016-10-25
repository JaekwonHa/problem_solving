#include <iostream>
#include <algorithm>
using namespace std;

int N;

int promise(int n) {
	int a = n%10;
	int b = (n/10 + n%10)%10;
	return a*10 + b;
}

int main() {

	scanf("%d", &N);

	int cnt=1,temp=promise(N);
	while(1) {
		if(temp==N) break;
		temp = promise(temp);
		cnt++;
	}

	printf("%d\n", cnt);


	return 0;
}