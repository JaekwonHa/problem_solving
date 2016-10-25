#include <iostream>

using namespace std;

int main() {
	
	int cases;
	

	cin>>cases;

	while(cases--) {
	
		int weight[100];
		int total=0;
		int num,i,j;

		cin>>num;
		for(i=0; i<num; i++) {
			cin>>weight[i];
			total+=weight[i];
		}

		long long dp[45001];
		for(int i=0; i<45002; i++) dp[i]=0;
		dp[0]=1;

		for(i=0; i<num; i++) {
			for(j=total; j>=weight[i]; j--) {
				dp[j] = dp[j] | (dp[j-weight[i]] << 1);
			}
		}

		int half = total/2;
		long long bit = num/2;
		bit = (long long)1 << bit;
		int median;
		for(i=half, j=half; i>=0 && j<=total; i--, j++) {
			if(dp[i] & bit) {
				median = i;
				break;
			}
			if(dp[j] & bit) {
				median = j;
				break;
			}
		}

		if(total-median < median) cout<<total-median<<" "<<median<<endl;
		else cout<<median<<" "<<total-median<<endl;

		if(cases!=0) cout<<"\n";
	}

	return 0;
}