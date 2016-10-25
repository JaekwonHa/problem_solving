#include <stdio.h>

int n, m;

int f(int a) {
	if(a==1) return 1;
	if(a==2) return 3;
	return f(a-1)%m + f(a-2)%m + 1;
}

long long int f2(int a) {
	if(a<=1) return 1;
	if(a==2) return 3;
	if(a%2) {
		return (f2(a/2)*f2(a/2+1) + 2*f2(a/2-1)*f2(a/2))%m;
	} else {
		return (f2(a/2)*f2(a/2) + f2(a/2-1)*f2(a/2-1)*2)%m;
		
	}
}

int main() {

	scanf("%d", &n);
	scanf("%d", &m);

	printf("%lld", f2(n));

	return 0;
}