#include <stdio.h>

int n, left, right;
int weight[8]={1,3,9,27,81,243,729}, chk[8], end;

void solve(int left, int right) {
	if(end) return;
	if(left == right) {
		printf("%d", n);
		for(int c=1; c<3; c++) {
			for(int i=0; i<7; i++) {
				if(chk[i]==c)
					printf(" %d", weight[i]);
			}
			if(c==1)
				printf(" 0");
		}
		end=1;
		return;
	}
	for(int i=0; i<7; i++) {
		if(chk[i]==0) {
			chk[i]=2;
			solve(left, right+weight[i]);
			chk[i]=1;
			solve(left+weight[i], right);
			chk[i]=0;
		}
	}
}

int main() {

	scanf("%d", &n);
	solve(n, 0);

	return 0;
}