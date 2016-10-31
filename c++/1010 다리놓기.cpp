#include <iostream>
#include <string.h>

using namespace std;

int binomial(int n, int k) {

	int i,j;
	int **arr = (int **)malloc(sizeof(int *) * (n+1));
    for(i = 0; i < n+1; i++)       
         arr[i] = (int *)malloc(sizeof(int *) * (k+1));

	for(i = 0; i<n+1; i++) {
		for(j = 0; j<min(i,k)+1; j++) {
			if(i==j || j==0) {
				arr[i][j] = 1;
				//cout<<"arr["<<i<<"]["<<j<<"] : "<<arr[i][j]<<endl;
			} else if(i>j && j>0) {
				arr[i][j] = arr[i-1][j] + arr[i-1][j-1]; // nCk = n-1Ck + n-1Ck-1
				//cout<<"arr["<<i<<"]["<<j<<"] : "<<arr[i][j]<<endl;
			}
		}
	}
	return arr[n][k];
}

int main() {

	int T,N,M;

	cin>>T;

	while(T--) {
		cin>>N>>M;

		if(N<M)
			swap(N,M);
 		
		cout<<binomial(N,M)<<endl;
	}

}