#include <iostream>
#include <vector>

using namespace std;

bool check[1000001] = {false};

int main() {
	
	long long int min, max, result=0;
	long long int i,j;

	cin>>min>>max;

	vector<long long int> pow_array;

	for(i=2; i*i<=max; i++) {
		pow_array.push_back(i*i);
	}
	int size = pow_array.size();
	for(int i=0; i<size; i++) {
		for(j=(min/pow_array[i])*pow_array[i]; j<=max; j+=pow_array[i]) {
			if(j-min < 0 ) continue;
			if(check[j-min]==false) {
				check[j-min] = true;
				result++;
			}
		}
	}
	cout<<max-min - result +1<<endl;
	
}