#include <stdio.h>
#include <algorithm>


struct P {int s,p; } S[500001];
int IDT[1<<21];

void update(int n) {
	while(n) {
		IDT[n]=IDT[n*2]+IDT[n*2+1];
		n>>=1;
	}
}

int lg_sum(int a, int b) {
	int sum=0;
	while(a<b) {
		if(b%2==0) sum+=IDT[b],b--;
		if(a%2==1) sum+=IDT[a],a++;
		a>>=1,b>>=1;
	}
	if(a==b) sum+=IDT[b];
	return sum;
}


int main() {
	int n,base;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &S[i].s), S[i].p=i;
	}
	std::sort(S, S+n, [](const P &a, const P &b) {
		return a.s<b.s;
	});
	for(int i=0; i<n; i++) S[i].s=i;
	std::sort(S, S+n, [](const P &a, const P &b) {
		return a.p<b.p;
	});
	for(base=1; base<n; base*=2);
	for(int i=0; i<n; i++) {
		IDT[base+S[i].s]=1;
		update((base+S[i].s)>>1);
		printf("%d\n", lg_sum(base+S[i].s+1, base+n)+1);
	}

	return 0;
}