#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

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

	int T,i,j,count,N;
	int test_case;

	int **map;
	map = new int*[1000];
	for(i=0; i<1000; i++) map[i]=new int[1000];
	
	int **checked;
	checked = new int*[1000];
	for(i=0; i<1000; i++) checked[i]=new int[1000];

	char input[1001];

	int Dx1[4] = {0, -1, 0, 1};
	int Dy1[4] = {-1, 0, 1, 0};
	int Dx2[4] = {0, 1, 0, -1};
	int Dy2[4] = {1, 0, -1, 0};

	int x,y,d;
    
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for(test_case = 1; test_case <= T; ++test_case) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        
        cin>>N;
		for(i=0; i<N; i++) {
			cin>>input;
			for(j=0; j<N; j++) {
				map[j][i] = input[j]-'0';
				checked[j][i]=0;
			}
		}
		x=0,y=0,d=0,count=0;
		while(x>=0 && x<N && y>=0 && y<N) {
			switch (map[x][y]) {
			case 1:
				if(!checked[x][y]) {
					count++;
					checked[x][y]=1;
				}
				x = x+Dx1[d];
				y = y+Dy1[d];
				switch(d) {
				case 0:
					d=3;
					break;
				case 1:
					d=2;
					break;
				case 2:
					d=1;
					break;
				case 3:
					d=0;
					break;
				}
				break;
			case 2:
				if(!checked[x][y]) {
					count++;
					checked[x][y]=1;
				}
				x = x+Dx2[d];
				y = y+Dy2[d];
				switch(d) {
				case 0:
					d=1;
					break;
				case 1:
					d=0;
					break;
				case 2:
					d=3;
					break;
				case 3:
					d=2;
					break;
				}
				break;
			case 0:
				int goX, goY;
				switch(d) {
				case 0:
					goX=1, goY=0;
					break;
				case 1:
					goX=0, goY=1;
					break;
				case 2:
					goX=-1, goY=0;
					break;
				case 3:
					goX=0, goY=-1;
					break;
				}
				x = x+goX;
				y = y+goY;
				break;
			}
		}
        
        
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
        cout<<count<<endl;
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}