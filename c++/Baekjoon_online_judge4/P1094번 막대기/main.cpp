#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int a,b;
	scanf("%d", &a);
	
	int i=64,cnt=0;
	while(a>0) {
		if(i>a) i/=2;
		else a-=i,cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}