#include <iostream>
#include <algorithm>
using namespace std;

struct tree{
	int minV,maxV;
} node[1<<20];

// N이 5만정도면 1<<20

int N,M,base;

int lg_Max(int a, int b) {
	int ans=0;
	while(a<b) {
		if(a%2==1) ans=max(ans,node[a].maxV),a++;
		if(b%2==0) ans=max(ans,node[b].maxV),b--;
		a>>=1;
		b>>=1;
	}
	if(a==b) ans = max(ans,node[a].maxV);
	return ans;
}

int lg_Min(int a, int b) {
	int ans=987654321;
	while(a<b) {
		if(a%2==1) ans=min(ans,node[a].minV),a++;
		if(b%2==0) ans=min(ans,node[b].minV),b--;
		a>>=1;
		b>>=1;
	}
	if(a==b) ans = min(ans,node[a].minV);
	return ans;
}

void update(int a, int b, int c) {
	node[a].minV=b;
	node[a].maxV=c;
	a>>=1;
	while(a) {
		node[a].minV = min(node[2*a].minV,node[2*a+1].minV);
		node[a].maxV = max(node[2*a].maxV,node[2*a+1].maxV);
		a>>=1;
	}
}

int main() {
	int a,b;
	scanf("%d %d", &N, &M);
	for(base=1; base<N; base*=2);
	//for(int i=1; i<base*2; i++) node[i].minV=987654321,node[i].maxV=0;
	for(int i=base; i<base+N; i++) {
		scanf("%d", &b);
		update(i,b,b);
	}
	for(int i=base+N; i<base*2; i++) {
		update(i,987654321,0);
	}
	for(int i=0; i<M; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", lg_Max(base+a-1,base+b-1)-lg_Min(base+a-1,base+b-1));
	}

	return 0;
}