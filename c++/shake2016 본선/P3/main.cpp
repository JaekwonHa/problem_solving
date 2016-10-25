#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define p 1000000007

int N;
long long fac[100010];
long long power[100010];

long long comp(int n, int i) {
	if(n==1) return 1;
	if(n==i) return 1;
	if(i==0) return 1;

	return (comp(n-1,i)+comp(n-1,i-1))%p;
}

void makeFac(int n) {
	fac[1]=1;
	for(int i=2; i<=n; i++) {
		if(fac[i-1]*i > p) {
			fac[i]=(fac[i-1]*i)%p;0000







				  
		} else {
			fac[i]=fac[i-1]*i;
		} 
	}
}
void makePow(int n) {
	power[1]=2;
	for(int i=2; i<=n; i++) {
		if(power[i-1]*2 > p) {
			power[i]=(power[i-1]*2)%p;
		} else {
			power[i]=power[i-1]*2;
		}
	}
}

int main() {
    
	cin>>N;

	makeFac(N);
	makePow(N);
	long long ans=0,C=0;
	//int d = (fac[1000]+p)/fac[1]/fac[999];
	for(int i=1; i<N; i++) {
		if(fac[N] < fac[i]) {
			C = (fac[N]+p)/fac[i];
		} else {
			C = fac[N]/fac[i];
		}
		if(C < fac[N-i]) {
			C = (C+p)/fac[N-i];
		} else {
			C = C/fac[N-i];
		}
		power[i] = (C*power[i])%p;
		ans = (ans + power[i])%p;
	}
	ans = (ans + power[N])%p;
	cout<<ans;

	return 0;
}