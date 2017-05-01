#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 1000000

int N,M,K;
long long IDT[3*MAXN+100];
int base;

long long range_sum(int a, int b) {
	long long sum=0;
	while(a<b) {
		if(a%2==1) sum+=IDT[a],a++;
		if(b%2==0) sum+=IDT[b],b--;
		a>>=1, b>>=1;
	}
	if(a==b) sum+=IDT[a];
	return sum;
}

void update(int a, int b) {
	IDT[a]=b;
	a>>=1;
	while(a>0) {
		//IDT[a]=IDT[a<<1]+IDT[(a<<1)+1];
		IDT[a]=IDT[a*2]+IDT[a*2+1];
		a>>=1;
	}
}

int main() {

	scanf("%d %d %d", &N, &M, &K);
	for(base=1; base<N; base*=2) {}
	for(int i=base; i<N+base; i++) {
		scanf("%lld", &IDT[i]);
	}

	for(int i=base-1; i>0; i--) {
		IDT[i]=IDT[i*2] + IDT[i*2+1];
	}

	int a,b,c;
	for(int i=0; i<M+K; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if(a==1) {
			update(base+b-1,c);
		} else {
			printf("%lld\n", range_sum(base+b-1,base+c-1));
		}
	}


	return 0;
}