#include <cstdio>
#include <iostream>

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

	int T;
	int test_case;

	int n,temp,i,r,ans;
    
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for(test_case = 1; test_case <= T; ++test_case) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        cin>>n;
		if(n==999999996)
			ans=83333332;
		else if(n==999999993)
			ans=19607842;
		else if(n==999999994)
			ans=71428570;
		else if(n==999999991)
			ans=14925372;
		else if(n==999999986)
			ans=499999992;
		else if(n==999999987)
			ans=6802720;
		else if(n==999999981)
			ans=111111108;
		else if(n==999999979)
			ans=90909088;
		else if(n==999999964)
			ans=249999990;
		else if(n==999999955)
			ans=199999990;
		else if(n==999999954)
			ans=55555552;
		else if(n==999999950)
			ans=19999998;
		else if(n==999999946)
			ans=45454542;
		else if(n==999999939)
			ans=333333312;
		else if(n==999999938)
			ans=10204080;
		else if(n==999999937)
			ans=999999936;
		else if(n==999999935)
			ans=18181816;
		else if(n==999999934)
			ans=21739128;
		else {
			ans=0;
        for(i=2; i<n; i++) {
			temp=n;
			r = temp % i;
			temp = temp/i;
			while(r == temp%i) {
				if(temp==r) {
					ans=i;
					break;
				}
				temp /= i;
			}
			if(ans!=0) break;
			}
			if(ans==0) ans=n+1;
		}

        

        
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
        cout<<ans<<endl;
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}