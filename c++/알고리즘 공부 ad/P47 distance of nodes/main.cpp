#include <stdio.h>

int n,m;

int abs(int a) {
	if( a< 0 )
		return -a;
	return a;
}


int f(int a, int b) {
	if( a==b ) {
		return 0;
	}
	if(a>b) {
		return f(a/2, b) + 1;
	}
	return f(a, b/2) + 1;
}

int main() {

	scanf("%d %d", &n, &m);

	printf("%d", f(n,m));

	return 0;
}