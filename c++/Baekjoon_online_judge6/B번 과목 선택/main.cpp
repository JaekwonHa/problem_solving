#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int arr1[4];
	int arr2[2];

	cin>>arr1[0]>>arr1[1]>>arr1[2]>>arr1[3];
	cin>>arr2[0]>>arr2[1];

	sort(arr1,arr1+4);
	sort(arr2,arr2+2);

	int ans=arr1[1]+arr1[2]+arr1[3]+arr2[1];
	cout<<ans<<endl;

	return 0;
}