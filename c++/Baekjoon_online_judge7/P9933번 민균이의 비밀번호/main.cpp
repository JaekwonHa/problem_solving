#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
char pass[101][15];
char ans[15];

bool checkPass(int x, int y) {
	for(int i=0; i<strlen(pass[x]); i++){
		if(pass[x][i] != pass[y][strlen(pass[y])-i-1]) return false;
	}
	return true;
}

int main() {

	cin>>N;
	for(int i=0; i<N; i++) {
		cin>>pass[i];
	}
	bool chk = true;
	strcpy(ans, pass[0]);
	for(int i=0; i<N; i++) {
		for(int j=i+1; j<N; j++) {
			if(strlen(pass[i]) == strlen(pass[j])) {
				if(checkPass(i,j)) strcpy(ans, pass[i]), chk=false;
			}
			if(!chk) break;
		}
		if(!chk) break;
	}

	cout<<strlen(ans)<<" "<<ans[strlen(ans)/2];


	return 0;
}