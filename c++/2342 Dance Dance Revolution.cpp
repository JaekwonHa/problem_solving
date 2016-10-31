#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define INF 111111

int arr[100010],len,DP[100010][5][5];

int cal(int x, int y) {
	if(x==0) return 2;
	if(abs(x-y)==2) return 4;
	if(abs(x-y)==1 || abs(x-y)==3) return 3;
	return 1;
}

int f() {
	memset(DP,INF*4,sizeof(DP));

	DP[0][0][0]=0;
	for(int i=1; i<=len; i++) {
		for(int a=0; a<5; a++) {
			for(int b=0; b<5; b++) {
				if(arr[i]!=a)
					DP[i][a][arr[i]] = min(DP[i][a][arr[i]], DP[i-1][a][b]+cal(b,arr[i]));
				if(arr[i]!=b)
					DP[i][arr[i]][b] = min(DP[i][arr[i]][b], DP[i-1][a][b]+cal(a,arr[i]));
			}
		}
	}

	
	int ans=INF*4;
	for(int a=0; a<5; a++) {
		for(int b=0; b<5; b++) {
			ans=min(ans,DP[len][a][b]);
		}
	}
	return ans;
}

int main() {

	int i=1;
	while(1) {
		scanf("%d", &arr[i]);
		if(arr[i]==0) break;
		i++;
	}
	len = i-1;

	printf("%d\n", f());

	return 0;
}
