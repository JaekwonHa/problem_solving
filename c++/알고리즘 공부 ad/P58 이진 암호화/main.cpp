#include <stdio.h>
#include <vector>

int n;
char S[1<<19];

void f(int x, int size) {
	if(size==1) {
		if(S[x]=='1')
			printf("1");
		else
			printf("0");
		return;
	}
	int check=S[x];
	for(int i=x; i<x+size; i++) {
		if(S[i] != check) {
			check=-1;
			break;
		}
	}
	if(check==-1) {
		printf("-");
		f(x, size/2);
		f(x+size/2, size/2);
		return;
	}
	if(check=='1')
		printf("1");
	else
		printf("0");

	return;
}

int main() {

	scanf("%d", &n);
	scanf("%s", S);

	f(0,n);

	return 0;
}