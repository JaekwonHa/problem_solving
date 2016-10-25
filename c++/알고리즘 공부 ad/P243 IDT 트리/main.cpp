#include <stdio.h>

int IDT[1<<18], N, base;

int lg_sum(int a,int b) {
	int sum=0;
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
	while(a) {
		IDT[a]=IDT[2*a]+IDT[2*a+1];
		a>>=1;
	}
}

int main(){
	scanf("%d", &N);
	for(base=1; base<N; base*=2);
	for(int i=base; i<N+base; i++) {
		scanf("%d", &IDT[i]);
	}
	for(int i=base-1; i>0; i--) {
		IDT[i]=IDT[2*i]+IDT[2*i+1];
	}

	int q;
	printf("쿼리 개수 입력 : ");
	scanf("%d", &q);
	while(q--) {
		int c,a,b;
		printf("쿼리 입력 : ");
		scanf("%d %d %d", &c, &a, &b);
		if(c==1) {
			printf("%d\n", lg_sum(base+a-1, base+b-1));
		} else {
			update(base+a-1,b);
		}
	}

	return 0;
}