#include <iostream>
#include <string.h>

using namespace std;

char matrix[102][102];

int main() {

	int x,y,i,j,count=1;
	char mine;

	while(cin>>x>>y) {
		if(x == 0 && y==0) break;

		memset(matrix, '0', 102*102*sizeof(char));
		
		for(i=1; i<=x; i++) {
			for(j=1; j<=y; j++) {
				cin>>mine;
				if(mine=='*') {
					matrix[i][j]='*';
					if(matrix[i-1][j-1]!='*') matrix[i-1][j-1]++;
					if(matrix[i][j-1]!='*') matrix[i][j-1]++;
					if(matrix[i+1][j-1]!='*') matrix[i+1][j-1]++;
					if(matrix[i-1][j]!='*') matrix[i-1][j]++;
					if(matrix[i+1][j]!='*') matrix[i+1][j]++;
					if(matrix[i+1][j+1]!='*') matrix[i+1][j+1]++;
					if(matrix[i][j+1]!='*') matrix[i][j+1]++;
					if(matrix[i-1][j+1]!='*') matrix[i-1][j+1]++;
				}
			}
		}
		if(count!=1) cout<<endl;
		cout<<"Field #"<<count<<":\n";
		for(i=1; i<=x; i++) {
			for(j=1; j<=y; j++) {
				cout<<matrix[i][j];
			}
			cout<<"\n";
		}
		count++;
	}
	return 0;
}