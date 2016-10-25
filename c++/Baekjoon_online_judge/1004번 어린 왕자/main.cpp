#include <iostream>
#include <math.h>

using namespace std;

#define IN 0
#define OUT 1

int calculate(int x, int y, int cx, int cy, int r) {
	return (sqrt(pow(x-cx,2.0) + pow(y-cy,2.0)) > r) ? OUT : IN;
}

int main() {

	int T,x1,y1,x2,y2,n,cx,cy,r;

	cin>>T;

	while(T--) {
		int answer=0;

		cin>>x1>>y1>>x2>>y2>>n;

		for(int i=0; i<n; i++) {
			cin>>cx>>cy>>r;
			if( calculate(x1,y1,cx,cy,r) != calculate(x2,y2,cx,cy,r)) answer++;
		}
		cout<<answer<<endl;
	}
}