#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
typedef unsigned long long ull;

int T,N;
ull DP[300];

// big integer를 사용해야 하는 문제이다. 여기서는 덧셈 연산을 구현할 필요가 있다.
// 푼대로 string을 사용하여 할 수도 있다. 여기서 안 점은 c에서 %s 는 char* 타입을 말한다. string을 출력하면 error가 나는데 이를 위해 c_str 을 통한 캐스팅이 필요하다.
// 또한 덧셈만 필요하다면 다음과 같이 구현할수도 있다.

/*
#include <stdio.h>
 
#define KK 1000000000
#define MAX 11
unsigned int d[251][MAX], N, max=1;
void sum(int a,int b,int k) {
    for (int n = 0; n < max; n++) 
        d[a][n] += d[b][n] * k;
 
     
    for (int n = 0; n < max; n++) {
        d[a][n+1] += d[a][n] / KK;
        d[a][n] %= KK;
    }
    if (d[a][max]>0) max++;
}
int main() {    
    d[0][0] = d[1][0] = 1;
    for (int n = 2; n <= 250; n++) {
        for (int m = 0; m < max; m++)
            d[n][m] = d[n - 1][m];
        sum(n, n - 2, 2);
    }
    while (scanf("%d", &N) != EOF) {
        int i = max;
        while (d[N][i] == 0)i--;
        printf("%d", d[N][i--]);
        while (i >= 0) printf("%09d", d[N][i--]);
        printf("\n");
    }
}


*/

ull f(int n) {
	if(n==0 || n==1) return 1;
	ull& ret = DP[n];
	if(ret!=-1) return ret;
	ret = (ull)f(floor(n/2.0))*(ull)f(ceil(n/2.0)) + (ull)f(floor(n/2.0)-1)*(ull)f(ceil(n/2.0)-1)*2;

	return ret;
}

string string_add(string a, string b) {
	string new_str="";
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	string long_s;
	string short_s;
	if(a.size() >= b.size()) {
		long_s = a;
		short_s = b;
	} else {
		long_s = b;
		short_s = a;
	}
	int carry = 0;
	int dif = long_s.size() - short_s.size();
	for(int i=0; i<dif; i++) {
		short_s += "0";
	}
	for(int i=0; i<long_s.size(); i++) {
		int hab = stoi(long_s.substr(i,1)) +stoi(short_s.substr(i,1)) + carry;
		if(hab > 9) {
			carry = 1;
			hab -= 10;
		} else {
			carry = 0;
		}
		new_str += to_string((long long)hab);
	}
	if(carry !=0) new_str += to_string((long long)carry);
	reverse(new_str.begin(), new_str.end());
	return new_str;
}

int main() {

	while(scanf("%d", &N) != EOF) {
		//memset(DP,-1,sizeof(DP));
		string d[251];
		d[0]="1";
		d[1]="1";
		for(int i=2; i<=N; i++) {
			d[i] = string_add(string_add(d[i-2],d[i-2]), d[i-1]);
		}
		printf("%s\n", d[N].c_str());
	}

	return 0;
}