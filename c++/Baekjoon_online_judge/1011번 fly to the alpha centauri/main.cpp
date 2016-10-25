#include <iostream>

using namespace std;

int main() {

	long long int T,x,y,length;
	int answer;

	cin>>T;

	while(T--) {

		cin>>x>>y;
		length = y-x;

		long long int step=2;
		int count=1;
		while(step<length) {
			count++;
			step += (count*2);
		}

		( (step-count) < length && length <= step ) ? answer=count*2 : answer=count*2-1;
		
		cout<<answer<<endl;

	}

}