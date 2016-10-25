#include <stdio.h>
#include <algorithm>
#include <string.h>

int N,A[2001],B[2001],DT[2001][2001];

int f(int a, int b) {
	if(a==0 || b==0) return 0;
	int ret=DT[a][b];
	if(ret==-1) {
		ret = std::max(ret,f(a-1,b));
		ret = std::max(ret, f(a-1,b-1));
		if(A[a]>B[b]) ret = std::max(ret, f(a,b-1)+B[b]);
		DT[a][b]=ret;
	}
	return DT[a][b];
}

int main() {
	memset(DT,-1,sizeof(DT));
	scanf("%d", &N);
	for(int i=N; i>0; i--) scanf("%d", &A[i]);
	for(int i=N; i>0; i--) scanf("%d", &B[i]);

	printf("%d", f(N,N));

	return 0;
}