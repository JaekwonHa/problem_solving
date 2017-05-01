#include <stdio.h>

int T,x,y;

int gcd(int a, int b) {
	int r = a%b;
	if(r==0) return b;
	return gcd(b,r);
}

void solve() {
	int a=1,b=2;
	while(x!=1) {
		if(x*b - y*a > 0) {
			x = x*b - y*a;
			y = y*b;
		}
		b++;
	}
}
void solve2() {
	int b;
	while(x!=1) {
		b = y/x+1;
		x = x*b - y;
		y = y*b;
		int r = gcd(y,x);
		x = x/r;
		y = y/r;
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &x, &y);
		solve2();
		printf("%d\n", y);
	}

	return 0;
}