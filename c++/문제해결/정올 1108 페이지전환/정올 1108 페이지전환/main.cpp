#include <iostream>
#include <math.h>
#include <boost/asio.hpp>

using namespace std;

#define MAX 501

int matrix[MAX][MAX];

int main() {

	int n,i,j,k,x,y,m;
	for(i=0; i<MAX; i++) {
		for(j=0; j<MAX; j++) {
			if(i==j) matrix[i][j]=0;
			else matrix[i][j]=MAX;
		}
	}
	n=0;
	cin>>m;
	for(i=1; i<=m; i++) {
		cin>>x>>y;
		matrix[x][y]=1;
		n = max(n,y);
	}
	for(k=1; k<=n; k++ ) {
		for(i=1; i<=n; i++) {
			for(j=1; j<=n; j++) {
				matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
			}
		}
	}
	double pair = n*(n-1);
	double sum = 0;
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			sum+=matrix[i][j];
		}
	}
	double solution = sum/pair;
	
	cout << fixed;
	cout.precision(3);
	cout<<solution<<endl;

	return 0;
}