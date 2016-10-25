#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int main() {

	int cases, i, j,count;
	int input[3010];
	int check[3010];

	while(cin>>cases) {
		count=0;
		for(i=0; i<3010; i++) check[i]=0;
		cin>>input[0];
		for(i=1; i<cases; i++) {
			cin>>input[i];
			
			if(abs(input[i]-input[i-1]) < cases && abs(input[i]-input[i-1]) > 0) {
				if(check[abs(input[i]-input[i-1])]==0) {
					check[abs(input[i]-input[i-1])]=1;
					count++;
				}
			}			
		}
		if(count == cases-1) cout<<"Jolly"<<endl;
		else cout<<"Not jolly"<<endl;

	}

	return 0;
}