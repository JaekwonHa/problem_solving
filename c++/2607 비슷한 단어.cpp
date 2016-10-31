#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N,ans;
char arr[110][15];
int index1['Z'+2],index2['Z'+2];

void solve() {
	int i,j,t;
	for(i=0; i<strlen(arr[0]); i++) index1[arr[0][i]]++;

	
	for(i=1; i<N; i++) {
		t=0;
		memset(index2,0,sizeof(index2));
		for(j=0; j<strlen(arr[i]); j++) index2[arr[i][j]]++;
		for(j='A'; j<='Z'; j++) {
			if(index1[j]!=index2[j]) {
				t += abs(index1[j]-index2[j]);
			}
		}
		if(strlen(arr[0]) != strlen(arr[i])) {
			if(t<=1) ans++;
		} else {
			if(t<=2) ans++;
		}
		
	}
}

int main() {

	cin>>N;
	for(int i=0; i<N; i++) cin>>arr[i];


	solve();

	cout<<ans<<endl;

	return 0;
}