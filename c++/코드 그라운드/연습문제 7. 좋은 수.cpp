// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <stdio.h>
#include <string.h>
#include <algorithm>

int N,ans;
int A[5000];
int check[5000];

int search(int x, int sum) {
	int high, low, middle;
	low = x, high = N;

	while(low <= high) {
		middle = (low+high)/2;
		if(A[middle]==sum)
			return middle;
		if(A[middle] > sum) high=middle-1;
		else low = middle+1;
	}
	return -1;
}

void solve3(int x, int sum) {
	int middle = search(x, sum);
	if(middle!=-1 && check[middle]==0) {
		check[middle]=1, ans++;
	}
}


void solve2(int x, int sum) {
	for(int i=x; i<N; i++) {
		solve3(i, sum+A[i]);
	}
}

void solve1(int x, int sum) {
	for(int i=x; i<N; i++) {
		solve2(i, sum+A[i]);
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
        memset(A, 0, sizeof(A));
		memset(check, 0, sizeof(check));
		ans=0;

		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", &A[i]);

		std::sort(A, A+N);
		for(int i=0; i<N; i++)
			solve1(i, A[i]);

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n%d\n", test_case, ans);
        
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}