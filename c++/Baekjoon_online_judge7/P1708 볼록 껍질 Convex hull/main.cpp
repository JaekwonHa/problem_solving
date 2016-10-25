#include <cstdio>
#include <cmath>
#include <tuple>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef tuple<double, double, double> Point;

// 두 점 사이의 거리
double distance(Point A, Point B) {
	return sqrt(pow(get<1>(A)-get<1>(B),2.0) + pow(get<2>(A)-get<2>(B),2.0));
}
double ccw(Point A, Point B, Point C) {
	return (get<2>(B)-get<2>(A))*(get<1>(C)-get<1>(A))-(get<1>(B)-get<1>(A))*(get<2>(C)-get<2>(A));
}

int main() {

	int N;
	scanf("%d", &N);
	vector<Point> p(N);
	for(int i=0; i<N; i++) {
		double x,y;
		scanf("%lf %lf", &x, &y);
		p[i]=Point(0,y,x);
	}
	// 가장 아래 왼쪽에 있는 점을 하나 찾음
	sort(p.begin(), p.end());
	for(int i=1; i<N; i++)
		get<0>(p[i]) = (get<2>(p[i])-get<2>(p[0]))/distance(p[0],p[i]);
	sort(p.begin()+1, p.end());

	// 처음 두개의 점을 넣고 시작
	stack<Point> s;
	s.push(p[0]);
	s.push(p[1]);
	int next=2;

	while(next<N) {
		while(s.size()>=2) {
			Point first,second;
			first = s.top();
			s.pop();
			second = s.top();
			if(ccw(second,first,p[next])<0) {
				s.push(first);
				break;
			}
		}
		s.push(p[next++]);
	}
	printf("%d\n", s.size());

	return 0;
}