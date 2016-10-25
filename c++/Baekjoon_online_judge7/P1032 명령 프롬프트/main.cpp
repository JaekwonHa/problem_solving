#include <iostream>
#include <string.h>
using namespace std;

int N;

int main() {

	
	char arr[50][51];
	char ans[51];

	memset(arr,0,sizeof(arr));
	memset(ans,0,sizeof(ans));

	cin>>N;
	for(int i=0; i<N; i++) {
		cin>>arr[i];
	}
	bool chk = true;
	for(int i=0; i<strlen(arr[0]); i++) {
		chk = true;
		for(int j=1; j<N; j++) {
			if(arr[j-1][i] != arr[j][i]) {
				chk = false;
			}
		}
		if(chk) {
			ans[i] = arr[0][i];
		} else {
			ans[i] = '?';
		}
	}

	cout<<ans<<endl;

	return 0;
}