#include <iostream>
#include <algorithm>
using namespace std;

int x,b;

int main() {

	scanf("%d %d", &x, &b);
	int sum=0,i=0;

	if(x<0) {

	} else if(b<0) {
		b*=-1;
		int carry=0;
		while(0<x) {
			int a = x%b;
			x /= b;
			if(i%2==0) {
				sum+= (a+carry)*pow((double)10.0,i++);
				carry++;
			} else {
				sum+= ((b-a))*pow((double)10.0,i++);
			}
		}
		if(i%2==0) {
			sum += pow((double)10.0,i);
		}
	} else {
		while(0<x) {
			int a = x%b;
			x /= b;
			sum+= a*pow(10.0,i++);
		}
	}
	printf("%d\n", sum);

	return 0;
}