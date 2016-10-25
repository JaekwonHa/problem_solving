#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int *prime_table;

int next_prime(int x) {
	x++;
	while(!prime_table[x]) x++;
	return x;
}

int main() {
	
	int i,j,k;
	prime_table = (int*)malloc(sizeof(int)*1121);
	for(i=0; i<1121; i++) prime_table[i]=i;

	for(i=2; i<1121; i++) {
		if(prime_table[i] == 0) continue;
		for(j=i+i; j<1121; j+=i) prime_table[j]=0;
	}

	int dp[1121][15];
	memset(dp, 0, 1121*15*sizeof(int));
	dp[0][0]=1;

	for(i=2; i<1121;) {
		for(j=1120; j>=i; j--) {
			for(k=1; k<15; k++) {
				dp[j][k] = dp[j][k] + dp[j-i][k-1];
			}
		}
		i = next_prime(i);
	}

	while(1)
    {
        cin>>i>>j;
        if(i==0 && j==0) break;
        cout<<dp[i][j]<<endl;
    }

	return 0;
}