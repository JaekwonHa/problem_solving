#include <stdio.h>
#include <queue>

int low,high,ans;

struct Point {
	int t;
	int cnt;
};

void bfs() {
	std::queue<Point> Q;
	Point p;
	p.t = low, p.cnt=0;
	Q.push(p);
	while(!Q.empty()) {
		Point curr;
		curr = Q.front();
		Q.pop();
		if(curr.t == high) {
			ans = curr.cnt;
			return;
		}
		if(curr.t < high) {
			Point next1, next2, next3;
			next1.t = curr.t+1, next1.cnt = curr.cnt+1;
			next2.t = curr.t+5, next2.cnt = curr.cnt+1;
			next3.t = curr.t+10, next3.cnt = curr.cnt+1;
			Q.push(next1);
			Q.push(next2);
			Q.push(next3);
		} else {
			Point next1, next2, next3;
			next1.t = curr.t-1, next1.cnt = curr.cnt+1;
			next2.t = curr.t-5, next2.cnt = curr.cnt+1;
			next3.t = curr.t-10, next3.cnt = curr.cnt+1;
			Q.push(next1);
			Q.push(next2);
			Q.push(next3);
		}
	}
}

int main() {

	scanf("%d %d", &low, &high);

	bfs();

	printf("%d", ans);

	return 0;
}