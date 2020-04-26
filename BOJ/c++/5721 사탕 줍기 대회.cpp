#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAXN 100010

int M,N;
int DP[MAXN][5],DP2[MAXN];

int main() {

	while(1) {
		
		scanf("%d %d", &M, &N);
		if(M==0 && N==0) break;
		int temp;
		int ans=0;
		memset(DP,0,sizeof(DP));
		for(int i=1; i<=M; i++) {
			for(int j=1; j<=N; j++) {
				scanf("%d", &temp);
				DP[i][j%5]=temp+max(DP[i][(j+2)%5],DP[i][(j+3)%5]);
			}
			DP[i][0]=max(DP[i][0],DP[i][1]);
			DP[i][0]=max(DP[i][0],DP[i][2]);
			DP[i][0]=max(DP[i][0],DP[i][3]);
			DP[i][0]=max(DP[i][0],DP[i][4]);
		}

		DP2[0]=0, DP2[1]=DP[1][0], DP2[2]=DP[2][0];
		for(int i=3; i<=M; i++) {
			DP2[i]=DP[i][0]+max(DP2[i-2],DP2[i-3]);
		}
		for(int i=0; i<=M; i++)
			ans = max(ans,DP2[i]);
		printf("%d\n", ans);
	}
	return 0;
}