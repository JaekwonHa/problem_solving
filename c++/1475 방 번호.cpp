#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int set[10];
int ans;

int main() {

	char number[10];
	cin>>number;

	for(int i=0; i<strlen(number); i++) {
		set[number[i]-'0']++;
	}
	set[6] += set[9];
	set[6] = (set[6]+1)/2;
	set[9] = 0;

	for(int i=0; i<10; i++) {
		ans = max(ans,set[i]);
	}

	cout<<ans<<endl;

	return 0;
}