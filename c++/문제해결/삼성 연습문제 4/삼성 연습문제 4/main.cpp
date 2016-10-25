#include <cstdio>
#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int pt_n[21] = {0, 6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8,16,7,19,3,17,2,15,10};
double upper[21] = {0, 9, 27, 45, 63, 81, 99, 117, 135, 153, 171, -171, -153, -135, -117, -99, -81, -63, -45, -27, -9};
double lower[21] = {0, -9, 9, 27, 45, 63, 81, 99, 117, 135, 153, 171, -171, -153, -135, -117, -99, -81, -63, -45, -27};
int bull, t_st, t_end, d_st, d_end;

double GetDegree(int x, int y) {
	return -(atan2(-(double)y,(double)x)*180/3.1415926535);
}
double GetDistance(int x, int y) {
	if(x==0) return abs(y);
	else if(y==0) return abs(x);

	return sqrt((double)x*x + y*y);
}
int GetPoint(int x, int y) {
	int t=1, count=0, result=1;

	double dis = GetDistance(x,y);

	if(dis<=bull) result = 50;
	else if(dis<=t_end && dis>=t_st) result = 3;
	else if(dis<=d_end && dis>=d_st) result = 2;
	else if (dis>=d_end) result = 0;

	if(result != 50 && result != 0) {
		double degree = floor(GetDegree(x,y));
		if(degree >= 0) {
			t=11;
			while(1) {
				if(lower[t] <= degree) break;
				--t;
			}
		} else {
			t=11;
			while(1) {
				if(upper[t] >= degree) break;
				++t;
			}
		}
	result *= pt_n[t];
	}
	

	

	return result;
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
	int i,result;
	int darts;
	int dart[10000][2];
	cin >> T;
    for(test_case = 1; test_case <= T; ++test_case) {
		//	이 부분에서 알고리즘 프로그램을 작성하십시오.
		memset(dart, 0, 10000*2*sizeof(int));
        result=0;
		cin>>bull>>t_st>> t_end>> d_st >> d_end;
		cin>>darts;
		for(i=0; i<darts; i++) cin>>dart[i][0]>>dart[i][1];
        for(i=0; i<darts; i++) result+=GetPoint(dart[i][0], dart[i][1]);
		
		//	이 부분에서 정답을 출력하십시오.  
		cout << "Case #" << test_case << endl;
        cout<<result<<endl;
	}

	return 0;	//	정상종료 시 반드시 0을 리턴해야 합니다.
}