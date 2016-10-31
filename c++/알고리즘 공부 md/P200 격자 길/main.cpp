#include <stdio.h>

int h,w,ans;
double angle;

void solve(int x, int y) {

	if(x<0 || x>h || y<0 || y>w)
		return;
	if(h!=x) {
		double curr_angle = (double)(w-y) / (h-x);
		if(angle > curr_angle)
			return;
	}
	if(x==h && y==w) {
		ans++;
		return;
	}
	solve(x+1, y);
	solve(x, y+1);
}

int main() {

	scanf("%d %d", &h, &w);
	angle = (double)w/h;

	solve(0,0);

	printf("%d", ans);

	return 0;
}