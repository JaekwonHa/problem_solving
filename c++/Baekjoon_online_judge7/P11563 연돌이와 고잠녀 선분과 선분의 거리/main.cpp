#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// 점 x,y 사이의 거리
inline double dist(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

// 벡터 x,y의 내적
inline double dot(double x1, double y1, double x2, double y2) {
	return x1*x2 + y1*y2;
}

// 벡터 x,y의 외적
inline double cross(double x1, double y1, double x2, double y2) {
	return x1*y2 - x2*y1;
}

// 선분 12에 점 3에서 수선의 발을 내릴 수 있으면 수선의 길이, 아니면 -1리턴
inline double perpendicular(double x1, double y1, double x2, double y2, double x3, double y3) {
	double dot1 = dot(x2-x1,y2-y1,x3-x1,y3-y1);
	double dot2 = dot(x1-x2,y1-y2,x3-x2,y3-y2);
	// 점 3이 선분 12와 예각 2개를 이루면 수선을 내릴 수 있음
	if(dot1*dot2 >= 0) {
		return abs(cross(x2-x1,y2-y1,x3-x1,y3-y1)) / dist(x1,y1,x2,y2);
	}
	return -1;
}

int main() {

	int N,M;
	double yx[4000],yy[4000],result=-1;
	scanf("%d %d", &N, &M);

	// 신촌의 도로 입력
	for(int i=0; i<N*2; i++)
		scanf("%lf %lf", yx+i,yy+i);

	// 안암의 도로 입력
	for(int i=0; i<M; i++) {
		double x1,x2,x3,x4,y1,y2,y3,y4;
		scanf("%lf %lf %lf %lf", &x3, &y3, &x4, &y4);

		// 입력 받자마자 신촌의 모든 도로들과 거리를 잰다.
		for(int j=0; j<N; j++) {
			x1 = yx[j*2];
			y1 = yy[j*2];
			x2 = yx[j*2+1];
			y2 = yy[j*2+1];

			// 먼저 모든 점 쌍 사이의 거리가 후보가 될수 있는지
			double d = dist(x1,y1,x3,y3);
			d = min(d,dist(x1,y1,x4,y4));
			d = min(d,dist(x2,y2,x3,y3));
			d = min(d,dist(x2,y2,x4,y4));

			double temp = perpendicular(x1,y1,x2,y2,x3,y3);
			if(temp >=0) d = min(d,temp);
			temp = perpendicular(x1,y1,x2,y2,x4,y4);
			if(temp >=0) d = min(d,temp);
			temp = perpendicular(x3,y3,x4,y4,x1,y1);
			if(temp >=0) d = min(d,temp);
			temp = perpendicular(x3,y3,x4,y4,x2,y2);
			if(temp >=0) d = min(d,temp);

			if(result<0) result=d;
			else result=min(result,d);
		}
	}
	printf("%.10lf\n", result);

	return 0;
}