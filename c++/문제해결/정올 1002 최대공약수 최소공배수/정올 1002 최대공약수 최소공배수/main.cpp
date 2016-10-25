#include <iostream>
#include <string.h>

using namespace std;

int main() {
	
	int cases, i, j, max_number=0;
	int input[11];
	bool check2[11];
	int GCD, LCM;

	while(cin>>cases) {
		max_number=0;
		GCD=1,LCM=1;
		for(i=1; i<=cases; i++) {
			cin>>input[i];
			if(max_number < input[i])  max_number=input[i];
		}
		int count, check;
		
		for(i=2; i<=max_number; i++) {
			count=0, check=0;
			memset(check2, false, 11*sizeof(bool));
			for(j=1; j<=cases; j++) {
				if(input[j]%i == 0) {
					count++;
					//check |= j;
					check2[j]=true;
				}
			}
			if(count==cases) {
				max_number=0;
				for(j=1; j<=cases; j++) {
					input[j] /= i;
					if(input[j] > max_number) max_number = input[j];
				}
				GCD *= i;
				LCM *= i;
				i=1;
			} else if(count>=2) {
				max_number=0;
				for(j=1; j<=cases; j++) {
					if(check2[j]) {
						input[j] /= i;
					}
					if(input[j] > max_number) max_number = input[j];
				}
				LCM *= i;
				i=1;
			}
		}
		for(i=1; i<=cases; i++) {
			LCM *= input[i];
		}
		cout<<GCD<<" "<<LCM<<endl;
	}

	return 0;
}