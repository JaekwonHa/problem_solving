#include <stdio.h>

int T,H,W,N,ans;

void solve() {
	if(N%H==0) {
		ans = H*100 + (N/(H));
	} else 	ans = (N%(H))*100 + (N/(H)+1);
}

int main() {

	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d", &H, &W, &N);
		if(H*W==N) printf("%d\n", H*100 + W);
		else {solve();
			printf("%d\n", ans);
		}
	}

	return 0;
}