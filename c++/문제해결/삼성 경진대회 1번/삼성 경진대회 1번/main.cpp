#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int T;
	int test_case;
    
	scanf("%d", &T);

	int *stone;
	stone = new int[1000000];
	int N,K,i,temp, ex_temp;

	for(test_case = 1; test_case <= T; ++test_case) {
        
		cin>>N;
		cin>> stone[0];
		ex_temp = stone[0];
		for(i=1; i<N; i++) {
			cin>>temp;
			stone[i] = temp - ex_temp;
			ex_temp = temp;
			//cout<<"-"<<stone[i];
		}
		cin>>K;
		int pos=0, count=0;
		i=0;
		while(1) {
			if(i==N) {
				count++;
				break;
			}
			if(pos==0 && stone[i]>K) {
				count=-1;
				break;
			}
			if(pos + stone[i] > K) {
				count++;
				pos=0;
				continue;
			}
			pos += stone[i];
			i++;
		}
        
		printf("Case #%d\n", test_case);
		cout<<count<<endl;
        
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}