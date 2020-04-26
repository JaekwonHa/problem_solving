#include <stdio.h>
#include <math.h>

int n,ans;

void f(int n) {

	if(n<=0) return;
	printf("%d", n%10);
	f(n/10);
}

void f2(int n) {
	if(n<=0) return;
	int digit = log10((double)n);
	ans += pow((double)10, digit) * (n%10);
	f2(n/10);
}


int main() {

	scanf("%d", &n);

	//f(n);
	f2(n);
	printf("%d", ans);

	return 0;
}