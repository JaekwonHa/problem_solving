#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int S,N;

int main() {
    
	scanf("%d", &S);

	printf("%d\n", S+3);
	printf("1 2\n");
	printf("2 3\n");
	printf("3 4\n");
	for(int i=5; i<=S+3; i++) {
		printf("3 %d\n", i);
	}

	return 0;
}