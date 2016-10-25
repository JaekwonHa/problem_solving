#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	long long int a;
	cin>>a;

	vector<int> ans;
	while(a>0) {
		if(a%2==1) ans.push_back(1);
		else {
			ans.push_back(0);
		}
		a /= 2;
	}
	for(int i = ans.size()-1; i>=0; i--) {
		printf("%d", ans[i]);
	}

	printf("\n");

	return 0;
}