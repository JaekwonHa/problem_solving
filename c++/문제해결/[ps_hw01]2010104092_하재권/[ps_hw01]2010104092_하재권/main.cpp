#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {

	int member;
	int sum=0;
	int avg=0;
	float input;
	vector<int> inputs;

	while(cin>>member && member !=0) {

		if(member>1000) continue;

		for(int i=0; i<member; i++) {
			cin>>input;
			if(input > 10000.00) return 0;
			
			inputs.push_back((int)(input*100+0.5));
			//cout<<inputs.at(i)<<endl;
			sum += inputs.at(i);
		}
		avg = floor((float)sum/(float)member);

		int deposit=0, withraw=0;
		int result=0;
		int b;
		for(int i=0; i<member; i++) {
			b = inputs.at(i);
			if((b-avg)>0) deposit += (b-(avg+1));
			else if((b-avg)<0) withraw += (avg-b);
		}
		if(deposit>withraw) result=deposit;
		else if(deposit<=withraw) result=withraw;

		cout << fixed;
		cout.precision(2);
		cout <<"$" << (double)(result/100.0)  << endl;

		sum=0, avg=0;
		inputs.clear();
	}
	return 0;
}