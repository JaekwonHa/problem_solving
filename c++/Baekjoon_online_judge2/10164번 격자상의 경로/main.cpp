#include <stdio.h>

int N,M,K,map[16][16],DT[16][16];

int f(int a, int b) {
	for(int i=0; i<a; i++) {
		DT[i][0]=1;
	}
	for(int i=0; i<b; i++) {
		DT[0][i]=1;
	}
	for(int i=1; i<a; i++) {
		for(int j=1; j<b; j++) {
			DT[i][j]=DT[i-1][j]+DT[i][j-1];
		}
	}
	return DT[a-1][b-1];
}

int main() {

	scanf("%d %d %d", &N, &M, &K);

	int r,w,ans = 0;
	if(K==0) {
		ans = f(N, M);
	} else if(N*M==K) {
		ans = f(N, M);
	} else {
		r = K/M+1;
		w = K%M;
		if(w==0) {
			r--;
			w=M;
		}
		//if(w==0) w=1;

		ans = f(r,w);
		ans = ans*f(N-r+1, M-w+1);
	}

	printf("%d", ans);

	return 0;
}