#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

char before[1001];
char after[1001];

int main() {

	cin>>before;

	for(int i=0; i<strlen(before); i++) {
		after[i] = before[i]-3;
		if(after[i] < 'A') {
			after[i] = after[i] + 'Z' - 'A' +1;
		}
	}

	cout<<after<<endl;

	return 0;
}