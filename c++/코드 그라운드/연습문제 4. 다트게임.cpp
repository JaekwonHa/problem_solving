// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <stdio.h>
#include <cmath>

#define PI 3.1415926535

int A,B,C,D,E,N, ans;
int X[10000], Y[10000];
int pointPlus[20] = {6, 13, 13, 4, 4, 18, 18, 1, 1, 20, 20, 5, 5, 12, 12, 9, 9, 14, 14, 11};
int pointMinus[20] = {6, 10, 10, 15, 15, 2, 2, 17, 17, 3, 3, 19, 19, 7, 7, 16, 16, 8, 8, 11};
int point[20] = {6,13,4,18,1,20,5,12,9,14,11,8,16,7,19,3,17,2,15,10};

double DDDD(int x, int y) {
	double arctanV = (atan2((double)y, (double)x) / PI) * 180.0; // arctan Value 계산
	if(arctanV >= -9.0 && arctanV < 9.0) return 6;
	else if(arctanV >= 9.0 && arctanV < 27.0) return 13;
	else if(arctanV >= 27.0 && arctanV < 45.0) return 4;
	else if(arctanV >= 45.0 && arctanV < 63.0) return 18;
	else if(arctanV >= 63.0 && arctanV < 81.0) return 1;
	else if(arctanV >= 81.0 && arctanV < 99.0) return 20;
	else if(arctanV >= 99.0 && arctanV < 117.0) return 5;
	else if(arctanV >= 117.0 && arctanV < 135.0) return 12;
	else if(arctanV >= 135.0 && arctanV < 153.0) return 9;
	else if(arctanV >= 153.0 && arctanV < 171.0) return 14;
	else if(arctanV >= 171.0 || arctanV < -171.0) return 11; // OR 조건(경계값)임에 주의
	else if(arctanV >= -171.0 && arctanV < -153.0) return 8;
	else if(arctanV >= -153.0 && arctanV < -135.0) return 16;
	else if(arctanV >= -135.0 && arctanV < -117.0) return 7;
	else if(arctanV >= -117.0 && arctanV < -99.0) return 19;
	else if(arctanV >= -99.0 && arctanV < -81.0) return 3;
	else if(arctanV >= -81.0 && arctanV < -63.0) return 17;
	else if(arctanV >= -63.0 && arctanV < -45.0) return 2;
	else if(arctanV >= -45.0 && arctanV < -27.0) return 15;
	else if(arctanV >= -27.0 && arctanV < -9.0) return 10;
	else return 0;
}

double getDistance(int x, int y) {
	return sqrt((double)x*x + (double)y*y);
}
double getDegree(int x, int y) {
	return (atan2((double)y,(double)x))*180/PI;
}

int getScore(int x, int y) {

	double R = getDistance(x, y);
	int score;
	if(R < A) return 50;
	else if( R < B) score = 1;
	else if( R < C) score = 3;
	else if( R < D) score = 1;
	else if( R < E) score = 2;
	else return 0;

	//return score * DDDD(x,y);

	/*
	double degree = getDegree(x, y);
	if(degree >= 0) {
		degree = (degree)/9;
		return score * pointPlus[(int)degree];
	} else {
		degree *= -1;
		degree = (degree)/9;
		return score * pointMinus[(int)degree];
	}
	*/
	double degree = getDegree(x, y)+9;
	if(degree<0)
		degree+=360;
	return score*point[(int)degree/18];
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
        ans=0;
        scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			scanf("%d %d", &X[i], &Y[i]);
			ans += getScore(X[i], Y[i]);
		}
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n%d\n", test_case, ans);
        
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}