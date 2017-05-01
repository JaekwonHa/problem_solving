#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N;
	long long int s1,s2;
	cin>>N;
	for(int i=0; i<N; i++) {
		cin>>s1>>s2;

		long long int a1,a2,answer;
		a1 = (s1+s2)/12;
		a2 = s1/5;

		cout<<min(a1,a2)<<endl;
	}

	return 0;
}