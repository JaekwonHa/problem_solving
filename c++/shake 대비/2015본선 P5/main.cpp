#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N,M,K;
int matrix[50][50];
bool answer=false;

bool check(int x, int y, int type) {
	
	bool check_row = false, check_col = false;
	for(int i=0; i<3; i++) {
		bool c1=true,c2=true;
		for(int j=0; j<3; j++) {
			if(matrix[x+i][y+j] != type) c1=false;
			if(matrix[x+j][y+i] != type) c2=false;
		}
		if(c1==true) check_row=true;
		if(c2==true) check_col=true;
	}
	if(check_row == true && check_col == true) return true;
	return false;
}

void solve() {
	for(int i=1; i<=N-2; i++) {
		for(int j=1; j<=M-2; j++) {
			for(int type=0; type<K; type++) {
				if(check(i,j,type)) {
					answer = true;
					return;
				}
			}
		}
	}
	return;
}

int main() {

	memset(matrix,-1,sizeof(matrix));

	cin>>N>>M>>K;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			cin>>matrix[i][j];
	
	if(N>=3 && M>=3) solve();

	if(answer==true) {
		cout<<"Yes";
	} else {
		cout<<"No";
	}
	cout<<endl;

	return 0;
}