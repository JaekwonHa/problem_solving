#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main() {

	int cases, x[101], i;
	double sum=0, avg=0, M=0;

	cin>>cases;
	
	for(i=1; i<=cases; i++) {
		cin>>x[i];
		sum+=x[i];
	}
	avg = sum/cases;

	avg *= 10;
	avg -= 0.5;
	avg = ceil(avg);
	avg /= 10;

	for(i=1; i<=cases; i++) {
		M += pow(abs(x[i]-avg), 2.0);
	}
	M /= cases;
	M = sqrt(M);

	M *= 10;
	M -= 0.5;
	M = ceil(M);
	M /= 10;

	cout<<sum<<endl<<avg<<endl<<M<<endl;
	
	return 0;
}