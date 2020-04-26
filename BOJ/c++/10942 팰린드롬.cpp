#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 2010

int N,M,arr[MAXN],S,E;

int f(int s, int e) {
	while(s<=e) {
		if(arr[s]!=arr[e]) return 0;
		s++,e--;
	}
	return 1;
}

int main() {
	
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
	scanf("%d", &M);
	for(int i=0; i<M; i++) {
		scanf("%d %d", &S, &E);
		printf("%d\n", f(S,E));
	}



	return 0;
}
