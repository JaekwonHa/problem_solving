// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <stdio.h>
#include <string.h>

int N, map[1000][1000];
int visit[1000][1000];

int f(int x, int y, int d, int cost) {
	if(x<0 || x>=N || y<0 || y>=N)
		return cost;
	if(visit[x][y]==0 && map[x][y]!=0) {
		visit[x][y]=1;
		cost++;
	}

	if(d==1) {
		if(map[x][y]==0) return f(x,y+1,d,cost);
		if(map[x][y]==1) return f(x-1,y,4,cost);
		if(map[x][y]==2) return f(x+1,y,2,cost);
	}
	if(d==2) {
		if(map[x][y]==0) return f(x+1,y,d,cost);
		if(map[x][y]==1) return f(x,y-1,3,cost);
		if(map[x][y]==2) return f(x,y+1,1,cost);
	}
	if(d==3) {
		if(map[x][y]==0) return f(x,y-1,d,cost);
		if(map[x][y]==1) return f(x+1,y,2,cost);
		if(map[x][y]==2) return f(x-1,y,4,cost);
	}
	if(d==4) {
		if(map[x][y]==0) return f(x-1,y,d,cost);
		if(map[x][y]==1) return f(x,y+1,1,cost);
		if(map[x][y]==2) return f(x,y-1,3,cost);
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
        scanf("%d", &N);
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				scanf("%1d", &map[i][j]);

		memset(visit, 0, sizeof(visit));
		int ans = f(0,0,1,0);
        

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
        
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}