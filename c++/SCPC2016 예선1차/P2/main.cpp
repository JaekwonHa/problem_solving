#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

#define p 1000000009
#define p2 2000000018

int N,K,L;
long long DP[51000][110];
bool mine[50010];

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	   C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	   따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T,t;
	int test_case;
    
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for(test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        
		memset(DP,0,sizeof(DP));
		memset(mine,false,sizeof(mine));

        scanf("%d %d %d",&N, &K, &L);
		if(L!=0) {
			for(int i=0; i<L; i++) {
				scanf("%d",&t);
				mine[t]=true;
			}
		}
		
		
		for(int i=1; i<=K; i++) {
			if(mine[i]==true) continue;
			DP[i][i]=1;
		}
		for(int i=1; i<=N; i++) {
			if(mine[i]==true) continue;
			for(int j=1; j<=K; j++)  {
				if(i-j<0) continue;
				if(DP[i-j][0]-DP[i-j][j]<0) DP[i][j]+=p;
				DP[i][j] += (DP[i-j][0]-DP[i-j][j]);
				DP[i][j] %= p;
			}
			for(int k=1; k<=K; k++) {
				DP[i][0] += DP[i][k];
				DP[i][0] %= p;
			}
		}
		DP[N][0] %= p;
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);		
		printf("%lld\n", DP[N][0]);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}