#include <stdio.h>

int n,cnt;

bool isPrime(int num) {
	for(int i=2; i*i<num; i++)
		if(num%i==0) return false;
	return true;
}

void dfs(int num, int len) {
	if(len==n) {
		printf("%d\n", num);
		cnt++;
		return;
	}
	if(isPrime(num*10+1)) dfs(num*10+1, len+1);
	if(isPrime(num*10+3)) dfs(num*10+3, len+1);
	if(isPrime(num*10+7)) dfs(num*10+7, len+1);
	if(isPrime(num*10+9)) dfs(num*10+9, len+1);
}

int main() {

	scanf("%d", &n);

		dfs(2,1);
	dfs(3,1);
	dfs(5,1);
	dfs(7,1);

	printf("%d\n", cnt);

	return 0;
}