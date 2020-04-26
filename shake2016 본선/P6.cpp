#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int S,P,ans,len;
char pass[1000010];
int minNumber[4];
int A[1000010],C[1000010],G[1000010],T[1000010];

int f(int n) {
	if(n+P-1 >= len) return 0;

	A[n]=A[n-1];
	C[n]=C[n-1];
	G[n]=G[n-1];
	T[n]=T[n-1];

	if(pass[n-1]=='A') {
		A[n]--;
	} else if(pass[n-1]=='C') {
		C[n]--;
	} else if(pass[n-1]=='G') {
		G[n]--;
	} else if(pass[n-1]=='T') {
		T[n]--;
	}

	if(pass[n+P-1]=='A') {
		A[n]++;
	} else if(pass[n+P-1]=='C') {
		C[n]++;
	} else if(pass[n+P-1]=='G') {
		G[n]++;
	} else if(pass[n+P-1]=='T') {
		T[n]++;
	}
	if(minNumber[0] > A[n]) {
		return 0;
	}
	if(minNumber[1] > C[n]) {
		return 0;
	}
	if(minNumber[2] > G[n]) {
		return 0;
	}
	if(minNumber[3] > T[n]) {
		return 0;
	}
	return 1;
}
void init() {
	for(int i=0; i<P; i++) {
		if(pass[i]=='A') {
			A[0]++;
		} else if(pass[i]=='C') {
			C[0]++;
		} else if(pass[i]=='G') {
			G[0]++;
		} else if(pass[i]=='T') {
			T[0]++;
		}
	}
	if(minNumber[0] > A[0]) {
		return;
	}
	if(minNumber[1] > C[0]) {
		return;
	}
	if(minNumber[2] > G[0]) {
		return;
	}
	if(minNumber[3] > T[0]) {
		return;
	}
	ans++;
	return;
}

int main() {
    
	cin>>S>>P>>pass>>minNumber[0]>>minNumber[1]>>minNumber[2]>>minNumber[3];
	len = strlen(pass);

	init();
	for(int i=1; i<=len-P; i++) {
		ans += f(i);
	}

	cout<<ans<<endl;

	return 0;
}