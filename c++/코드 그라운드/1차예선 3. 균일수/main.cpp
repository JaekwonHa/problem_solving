// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 55555555
			
int N;
int mem[MAX];

int f(int x, int b, int num) {
	if(num==0) return 0;
	if(x==0) return b;
	
	/*
	if(num==t)
		return f(x/b,b,t);
	return -1;
	*/

	if(x<MAX) mem[x]=mem[x/b];
	if(x/b<MAX && mem[x/b]!=0 && mem[x/b]==num) {
		return mem[x/b];
	} else {
		int t = x%b;
		if(num==t) {
			int ans = f(x/b,b,t);
			if(ans==-1) {
				if(x<MAX) mem[x]=0;
				return -1;
			}
		} else {
			if(x<MAX) mem[x]=0;
			return 0;
		}
	}
}

int main(void) {
   	/* 아래 freopen 함수는 input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면
   	   그 아래에서 scanf 함수를 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
   	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
	// freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);
	for(test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        
		//memset(mem,0,sizeof(mem));

        scanf("%d", &N);

		double start = clock();
	


		int i,ans;
		if(N==1) ans=2;
		for(i=2; i<N; i++) {
			if(N/i<MAX && mem[N/i]!=0 && mem[N/i]==N%i) {
				
				ans = mem[N/i];
				break;
			} else {
				ans = f(N/i,i,N%i);
			}
			if(ans!=0) {
				if(N<MAX) mem[N]=ans;
				break;
			}
		}
		if(i==N)
			ans = N+1;
        

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n%d\n", test_case, ans);
        printf("\nresult=%.3lf(sec)\n",(double)(clock()-start)/CLOCKS_PER_SEC);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}