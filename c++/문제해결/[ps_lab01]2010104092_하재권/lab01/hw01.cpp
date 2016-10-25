#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int member; 
	int sum=0;
	int avg=0;
	float input;
	int inputs[1000];

	while(cin>>member && member!=0) {

		for(int i=0; i<member; i++) {
			cin>>input;

			if(input==0) return 0;
			
			inputs[i] = input*100+0.5;

			sum += inputs[i];
		}
		avg = floor((float)sum/(float)member);

		int deposit=0, withraw=0;
		int result=0;
		for(int i=0; i<member; i++) {
			if((inputs[i]-avg)>0) deposit += (inputs[i]-(avg+1));
			else if((inputs[i]-avg)<0) withraw += (avg-inputs[i]);
		}
		if(deposit>withraw) result=deposit;
		else if(deposit<=withraw) result=withraw;

		cout.precision(2);

		cout << "$" << fixed<< (float)result/100 << "\n";

		sum=0, avg=0;
	}
	return 0;
}