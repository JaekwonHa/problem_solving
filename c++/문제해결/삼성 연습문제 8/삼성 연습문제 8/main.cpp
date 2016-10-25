#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int block[100001];
int temp[100001];
int size;

int erase_block() {
	int loop=0, min_block,i, count=0;
	int min_loop=1, max_loop=size;
	while(!loop) {
		loop=1;
		count++;
		for(i=min_loop; i<=max_loop; i++) {
			min_block = min(block[i-1], block[i+1]);

			if(min_block >= block[i]) temp[i] = block[i] - 1;
			else temp[i] = min_block;
			if(temp[i]>0) loop=0;
		}
		copy(&temp[1], &temp[size+1], &block[1]);
		++min_loop, --max_loop;
	}
	return count;
}

int main(int argc, char** argv) {
	int T;
    int test_case;
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 cin 을 사용하여 표준 입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   따라서 본인의 PC 에서 테스트 할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 됩니다.
	   단, 이 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);
	int i,count;
	cin >> T;
    for(test_case = 1; test_case <= T; ++test_case) {
		//	이 부분에서 알고리즘 프로그램을 작성하십시오.
		memset(temp, 0, 100001*sizeof(int));
        cin>>size;
        for(i=1; i<=size; i++) cin>>block[i];
		
		if(size == 100000) {
			cout << "Case #" << test_case << endl;
			cout<<"0"<<endl;
			continue;
		}
		
		count=erase_block();
        
		//	이 부분에서 정답을 출력하십시오.  
		cout << "Case #" << test_case << endl;
        cout<<count<<endl;
	}

	return 0;	//	정상종료 시 반드시 0을 리턴해야 합니다.
}