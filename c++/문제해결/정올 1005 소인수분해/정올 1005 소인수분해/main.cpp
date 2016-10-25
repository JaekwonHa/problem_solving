#include <iostream>
#include <math.h>

using namespace std;



int main() {

	int cases, i, j, input, max_prime, max_number;
	int prime[20001], prime_count[2262];
	for(i=0; i<20001; i++) prime[i]=i;
	prime[1]=0;

	for(i=2; i<sqrt(20001.0); i++) {
		for(j=i*2; j<20001; j+=i) {
			prime[j]=0;
		}
	}
	int count=0;
	for(i=0; i<20001; i++) {
		if(prime[i]!=0) {
			prime_count[count]=prime[i];
			count++;
		}
	}

	
	while(cin>>cases) {
		max_prime=0, max_number=0;
		for(i=0; i<cases; i++) {
			cin>>input;
			for(j=2261; j>=0; j--) {
				if(prime_count[j]<=input && input%prime_count[j]==0) {
					if(max_prime <prime_count[j]) {
						max_prime = prime_count[j];
						max_number = input;
					}
					break;
				}
			}
		}
		cout<<max_number<<endl;
	}
	

	return 0;
}