#include <stdio.h>

int T,N,arr[100000];

int f(int n) {
	
	for(int B=2; B<=64; B++) {
		int i=0,t=n;
		while(t>0) {
			arr[i++]=t%B;
			t /= B;
		}
		int lb=0,ub=i-1,ans=0;
		while(lb<=ub) {
			if(arr[lb++]!=arr[ub--]) {
				ans=1;
				break;
			}
		}
		if(ans==0) return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		printf("%s\n", (f(N))?"1":"0");
	}

	return 0;
}