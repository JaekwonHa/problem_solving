// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <stdio.h>

//long long int N,K, x,y;
int N,K;
char d;

long long int startRoom(long long int count, int x, int y) {
	if(count < N+1) {
		return (count*(count-1)/2) +1;
	} else {
		count = 2*N-x-y+1;
		return (N*N) - (count*(count-1)/2) - count +1;
	}
}

long long int solve(int x, int y) {
	long long int roomStart, roomCount = x+y-1, step;
	if(roomCount <= N) {
		roomStart = startRoom(roomCount,x,y);
		if(roomCount%2==0) {	// 방 개수가 짝수개 </ 방향
			step = x-1;
		} else {			// 방 개수가 홀수개 /> 방향
			step = y-1;
		}
	}else {
		roomStart = startRoom(roomCount,x,y);
		long long int tempX, tempY;
		tempX = N-x+1, tempY = N-y+1;
		roomCount = 2*N-x-y+1;;
		if(roomCount%2==0) {	// 방 개수가 짝수개 </ 방향
			step = tempY-1;
		} else {			// 방 개수가 홀수개 /> 방향
			step = tempX-1;
		}
	}
	return roomStart + step;
}

long long int solve2(int x, int y) {
	long long int ret=0;
	if(x+y < N) {
		ret = (x+y+1)*(x+y)/2;
		if( (x+y)%2==0 ) ret += (y+1);
		else ret += (x+1);
		return ret;
	} else {
		 return N*N -solve2(N-x-1, N-y-1) +1;
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
        scanf("%lld %lld", &N, &K);
		int x=1,y=1;
		//int x=0,y=0;
		long long int ans=1;
		while(K>0) {
			scanf("%1s", &d);
			if(d=='U') {
				x--;
			} else if(d=='D') {
				x++;
			} else if(d=='L') {
				y--;
			} else if(d=='R') {
				y++;
			}
			ans += solve(x,y);
			//ans += solve2(x,y);
			K--;
		}

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n%lld\n", test_case, ans);
        
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}