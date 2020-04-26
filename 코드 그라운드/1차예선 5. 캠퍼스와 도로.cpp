// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define INF 9999999

int N,M,map[1001][1001],check[1001];

int MAX(int a, int b) {
	if(a>b) return a;
	return b;
}
int MIN(int a, int b) {
	if(a<b) return a;
	return b;
}

void solve(int x) {

	int value[1001];
	int f[1001];
	int index[1001];

	memset(index, 0, sizeof(index));
	
	for(int i=1; i<=N; i++) {
		value[i]=INF;
		f[i]=0;
	}
	value[x]=0;

	for(int i=1; i<=N; i++) {
		int min=INF, p;
		for(int j=1; j<=N; j++) {
			if(f[j]==0 && value[j]<min) {
				p=j;
				min = value[j];
			}
		}
		f[p]=1;
		for(int j=1; j<=N; j++) {
			if(value[p]+map[p][j] < value[j]) {
				value[j] = value[p]+map[p][j];
				index[j]=p;
			}
		}
	}
	for(int i=1; i<=N; i++) {
		if(index[i]!=0) {
			int j = index[i];
			while(j!=0) {
				if(index[j]!=0)
					check[j]=1;
				j=index[j];
			}
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
        int a,b,c;
		memset(check,0,sizeof(check));

        scanf("%d %d", &N, &M);
		
		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				map[i][j]=INF;
		for(int i=1; i<=M; i++) {
			scanf("%d %d %d", &a, &b, &c);
			map[a][b]=c;
			map[b][a]=c;
		}

		for(int i=1; i<=N; i++)
			solve(i);

		std::vector<int> list;
		for(int i=1; i<=N; i++)
			if(check[i]==0) list.push_back(i);
		std::sort(list.begin(), list.end());

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		if(list.size()==0) {
			printf("0\n");
		} else {
			printf("%d ", list.size());
			for(int i=0; i<list.size(); i++) {
				printf("%d ", list[i]);
			}
			printf("\n");
		}
		
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}