#include <iostream>
#include <string.h>
using namespace std;

char arr[101];
char ans[101];

int main() {

	cin>>arr;
	int j=0;
	ans[j++] = arr[0];
	for(int i=1; i<strlen(arr); i++) {
		if(arr[i] == '-') {
			ans[j++] = arr[i+1];
		}
	}

	cout<<ans<<endl;

	return 0;
}