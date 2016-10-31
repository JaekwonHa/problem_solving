#include <stdio.h>
int main() {
	unsigned int N,x,y;
	scanf("%d %d %d",&N,&x,&y);
	unsigned int i=0,M=1;
	while(N>M) {
		i++;
		M*=2;
	}
	if(x>y) {
		int temp = x;
		x = y;
		y= temp;
	}
	while(!( 1<=x && x<=M/2 && M/2<y && y<=M )) {
		i--;
		if(1<=x && x<=M/2 && 1<=y && y<=M/2) M/=2;
		else {
			x-=M/2, y-=M/2, M/=2;
		}
	}
	printf("%d", i);
	return 0;
 
  }