#include <stdio.h>
int G(int a, int b) {
	int r = a%b;
	if(r==0) return b;
	else return G(b,r); }
int main() {
	int a,b,c,d,GCD,x,y;
	scanf("%d %d\n%d %d",&a,&b,&c,&d);
	GCD = G(a,b);
	a /= GCD, b /= GCD;
	GCD = G(c,d);
	c /= GCD, d /= GCD;
	x = b*d, y = a*d + b*c;
	GCD = G(x,y);
	x /= GCD, y /= GCD;
	printf("%d %d", y,x);
	return 0;
}