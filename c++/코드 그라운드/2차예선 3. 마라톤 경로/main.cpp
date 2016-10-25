#include <stdio.h>
#include <string.h>

#define TRUE (1)
#define FALSE (0)

int M,N,K;
int high[101][101],bottle[101][101],map[101][101];
int bottleX[10201], bottleY[10201];
int bottle_cnt;

int abs(int a) {
	if(a>0) return a;
	return -a;
}
int promise(int x, int y, int water) {
	int count=0;
	for(int i=0; i<bottle_cnt; i++) {
		if(x <= bottleX[i] && y <= bottleY[i]) {
			count++;
			if(water + count >= K) {
				break;
			}
		}
	}
	if(water + count >= K) return TRUE;
	return FALSE;
}

void solve(int x, int y, int cost, int water) {
	if(x>N || y>M) return;
	//if(promise(x,y,water) == FALSE) return;
	if(water>=K && cost >= map[N][M]) return;
	if(x==N && y==M) {
		water += bottle[x][y];
		if(water>=K && cost<map[N][M]) {
			map[N][M]=cost;
		}
		return;
	}
	water += bottle[x][y];

	solve(x+1,y,cost+abs(high[x][y]-high[x+1][y]) ,water);
	solve(x,y+1,cost+abs(high[x][y]-high[x][y+1]) ,water);
	/*\
	
	if(water>=K && map[x][y] != 0 && map[x][y] > cost)
		map[x][y]=cost;
	else if(water>=K && map[x][y] == 0)
		map[x][y]=cost;

	if(water>=K && map[x+1][y] != 0 && map[x+1][y] > cost+abs(high[x][y]-high[x+1][y])) {
		solve(x+1,y,cost+abs(high[x][y]-high[x+1][y]) ,water);
	} else if(map[x+1][y] == 0)
		solve(x+1,y,cost+abs(high[x][y]-high[x+1][y]) ,water);

	if(water>=K && map[x][y+1] != 0 && map[x][y+1] > cost+abs(high[x][y]-high[x][y+1])) {
		solve(x,y+1,cost+abs(high[x][y]-high[x][y+1]) ,water);
	} else if(map[x][y+1] == 0)
		solve(x,y+1,cost+abs(high[x][y]-high[x][y+1]) ,water);
		*/
}

int main(void) {
   	/* 아래 freopen 함수는 input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면
   	   그 아래에서 scanf 함수를 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
   	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
	// freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 '시간 초과'로 강제 종료 되었을 때,
	   printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	   시간 초과 전까지 실행된 결과 점수를 받고자 하신다면 "setbuf(stdout, NULL);" 를 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T,t;
	int test_case;

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		
        scanf("%d %d %d", &M, &N, &K);
		
		memset(map, 0, sizeof(map));
		memset(bottleX, 0, sizeof(bottleX));
		memset(bottleY, 0, sizeof(bottleY));
		bottle_cnt = 0;;

		for(int i=0; i<=N; i++)
			for(int j=0; j<=M; j++) {
				scanf("%d", &t);
				if(t<0) {
					high[i][j]=-t;
					bottle[i][j]=1;
					bottleX[bottle_cnt]=i;
					bottleY[bottle_cnt++]=j;
				} else {
					high[i][j]=t;
					bottle[i][j]=0;
				}
			}
		map[N][M]=0x7fffffff;
		solve(0,0,0,0);

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		printf("%d\n", map[N][M]);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}