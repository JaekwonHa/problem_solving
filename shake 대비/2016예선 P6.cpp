#include <iostream>
#include <algorithm>
using namespace std;

char matrix[15][15];
char answer[15][15];

int colorIn(char type) {
	if(type=='R') return 1;
	if(type=='G') return 2;
	if(type=='B') return 4;
	return 0;
}

char colorOut(int type) {
	if(type==1) return 'R';
	if(type==2) return 'G';
	if(type==4) return 'B';
	if(type==3) return 'Y';
	if(type==5) return 'M';
	if(type==6) return 'C';
	if(type==7) return 'W';
}

char f(int x, int y) {
	int bit=0;

	bit = bit|colorIn(matrix[x][y]);
	bit = bit|colorIn(matrix[x-1][y]);
	bit = bit|colorIn(matrix[x+1][y]);
	bit = bit|colorIn(matrix[x][y-1]);
	bit = bit|colorIn(matrix[x][y+1]);

	return colorOut(bit);
}

int main() {

	for(int i=1; i<=10; i++)
		for(int j=1; j<=10; j++)
			cin>>matrix[i][j];

	for(int i=1; i<=10; i++) {
		for(int j=1; j<=10; j++) {
			answer[i][j] = f(i,j);
			cout<<answer[i][j];
			if(j!=10) cout<<" ";
		}
		cout<<endl;
	}

	return 0;
}