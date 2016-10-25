#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

#define pi acos((double)-1)

int main() {
	int cases,a,b,c,i;
	double degree[1000], max_gap;

	while(cin>>cases) {
		if(cases==0) break;
		max_gap = 0;

		for(i=0; i<cases; i++) {
			cin>>a>>b>>c;
			degree[i] = atan2((double)(b-a), (double)(c-a));
		}

		sort(degree, degree+cases);
		
		for(i=1; i<cases; i++) max_gap = max(max_gap, degree[i] - degree[i-1]);

		if(max_gap<=pi && degree[cases-1] - degree[0] >= pi) {
			cout<<"Yes"<<endl;
			continue;
		}
		cout<<"No"<<endl;
	}
	return 0;
}