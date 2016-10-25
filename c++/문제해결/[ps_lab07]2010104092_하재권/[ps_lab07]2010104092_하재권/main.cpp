#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

#define max 65000

int table[max];

unsigned int power(unsigned int a,unsigned int b,unsigned int n) {
	if(b==0) return 1;
	if(b==1) return a%n;
	if(b%2) return (power(a,b-1,n) * a%n)%n;
	else {
		int temp = power(a,b/2,n);
		return (temp*temp)%n;
	}
}


int main() {

	memset(table, 0, max*sizeof(int));

	unsigned int i,j;

	for(i=2; i<sqrt((double)max); i++) {
		for(j=i+i; j<max; j=j+i) {
			table[j]=1;
		}
	}
	for(i=2; i<max; i++) {
		if(table[i]==1) {
			for(j=2; j<i; j++) {
				if(power(j,i,i)!=j) {
					table[i]=0;
					break;
				}
			}
		}
	}

	int n;
	while(1) {
		cin>>n;
		if(n==0) break;

		if(table[n]) cout<<"The number "<<n<<" is a Carmichael number."<<endl;
		else cout<<n<<" is normal."<<endl;
	}


	return 0;
}