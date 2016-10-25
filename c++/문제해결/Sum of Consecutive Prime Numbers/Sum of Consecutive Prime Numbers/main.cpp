#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>

using namespace std;

//int prime_table[10001];
int *prime_table;
int next_prime(int x) {

	while(x) {
		if(prime_table[x]) break;
		x++;
	}
	return x;
}

int main() {

	int i,j,k;
	//int dp[10001];
	int *dp;
	dp = (int*)malloc(sizeof(int)*10001);
	prime_table = (int*)malloc(sizeof(int)*10001);
	
	for(i=0; i<10002; i++) {
		prime_table[i]=i;
		dp[i]=0;
	}
	prime_table[1]=0;

	for(i=2; i<sqrt(10002.0); i++) {
		if(prime_table[i]==0) continue;
		for(j=i+i; j<10002; j+=i) {
			prime_table[j] = 0;
		}
	}

	int number;

	for(i=2; i<10002; i++) {
		i=next_prime(i);
		number=i;
		if(number>10000) break;
		dp[number]++;

		for(j=i+1; j<10002; j++) {
			j=next_prime(j);
			number += j;
			if(number>10000) break;
			dp[number]++;
		}
	}

	vector<int> result;
	while(true) {
		int input;
		cin>>input;
		if(input==0) break;

		result.push_back(input);
	}
	for(i=0; i<result.size(); i++)
		cout<<dp[result.at(i)]<<"\n";

	return 0;
}