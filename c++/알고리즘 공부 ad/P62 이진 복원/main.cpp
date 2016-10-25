#include <stdio.h>
#include <string.h>

int n;
char S[1<<19];

void f(int x, int k) {
	if( S[x] == '-' ) {
		f(x+1, k+1);
		f(x+2, k+1);
		return;
	}
	if( S[x] == '1' ) {
		for(int i=0; i<n/k; i++)
			printf("%s", "1");
		return;
	}
	if( S[x] == '0' ) {
		for(int i=0; i<n/k; i++)
			printf("%s", "0");
		return;
	}
}

int main() {

	scanf("%d %s", &n, S);

	f(0, 1);

	return 0;
}