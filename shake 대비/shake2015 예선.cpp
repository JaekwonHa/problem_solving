#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N;
	double point[4],answer;

	cin>>N;
	while(N--) {
		cin>>point[0]>>point[1]>>point[2]>>point[3];

		if(point[0]==0.0 || point[1]==0.0 || point[2]==0.0 || point[3]==0.0) {
			cout<<"NOT ATTENDED"<<endl;
			continue;
		}

		answer =( point[0] + point[1] + point[2] + point[3] )/4;

		answer *= 100;

		int a = answer;
		int b = 0;
		if(a%100 <25) {
			b=0;
		} else if(a%100 <75) {
			b=5;
		} else {
			a+=100;
		}
		cout<<a/100<<"."<<b<<endl;
	}

	return 0;
}