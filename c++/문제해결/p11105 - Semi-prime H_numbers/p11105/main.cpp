#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {

	long start = (long) clock() / (long) CLOCKS_PER_SEC;

	int *arr;
	arr = (int*)malloc(sizeof(int)*1000002);
	int i,j;
	for(i=0; i<1000002; i++) arr[i]=0;

	for(i=5; i<1000002; i+=4) {
		if(arr[i]==0) arr[i]=1;
		//for(j=i; j<1000002&&(j*i)<1000002; j += 4) {
		for(j=5; j<=i && (j*i)<1000002; j += 4 ) {
			if(j*i > 1000001) break;
			arr[i*j] = arr[i] + arr[j];
		}
	}
	int count=0;
	int *dp;
	dp = (int*)malloc(sizeof(int)*1000002);
	for(i=1; i<1000002; i++) {
		if(arr[i]==2) count++;
		dp[i] = count;
	}
	long end = (long) clock() / (long) CLOCKS_PER_SEC;

	//cout<<end-start<<endl;

	vector<int> result;
	while(true) {
		int input;
		cin>>input;
		if(input==0) break;

		result.push_back(input);
	}

	for(i=0; i<result.size(); i++) {
		cout<<result.at(i)<<" "<<dp[result.at(i)]<<"\n";
	}


	return 0;
}