#include <iostream>
#include <math.h>

using namespace std;

int x1, y2, r1;
int x2, y3, r2;

double dis() {
	return sqrt(pow(x1-x2, 2.0) + pow(y2-y3, 2.0));
}
int calculate() {
	double d = dis();
	if(abs(r1-r2) < d && d < r1+r2) return 2;
	if(abs(r1-r2) == d || d == r1+r2) return 1;
	if(abs(r1-r2) > d || d > r1+r2) return 0;
}



int main() {

	int count;

	cin>>count;
	while(count--) {
		cin>>x1>>y2>>r1>>x2>>y3>>r2;
		if(x1==x2 && y2 == y3 && r1 == r2) {
			cout<<-1<<endl;
			continue;
		}
		cout<<calculate()<<endl;
	}

}

