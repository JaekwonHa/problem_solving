#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int DP[21][21][21];

int f(int a, int b, int c) {
	if(a<=0 || b<=0 || c<=0)
		return 1;
	if(a>20 || b>20 || c>20)
		return f(20,20,20);

	if(DP[a][b][c]!=-1) return DP[a][b][c];
	
	if(a<b && b<c)
		return DP[a][b][c]=f(a,b,c-1)+f(a,b-1,c-1)-f(a,b-1,c);
	return DP[a][b][c]=f(a-1,b,c)+f(a-1,b-1,c)+f(a-1,b,c-1)-f(a-1,b-1,c-1);

}

int main() {
	int a,b,c;
	while(1) {
		memset(DP,-1,sizeof(DP));
		scanf("%d %d %d", &a, &b, &c);
		if(a==-1 && b==-1 && c==-1) break;
		printf("w(%d, %d, %d) = %d\n", a,b,c, f(a,b,c));
	}


	return 0;
}