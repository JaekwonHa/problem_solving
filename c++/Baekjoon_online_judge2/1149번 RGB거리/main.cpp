#include <stdio.h>

int min(int a, int b) { 
	if(a<b) return a;return b; 
}

int N;
int color[1000][3];
int DT[1000][3];

int f(int x, int c) {
	if(x<0) return 0;
	int two, three;
	if(DT[x-1][(c+1)%3]==0) two = DT[x-1][(c+1)%3] = f(x-1,(c+1)%3);
	two = DT[x-1][(c+1)%3];
	if(DT[x-1][(c+2)%3]==0) three = DT[x-1][(c+2)%3] = f(x-1,(c+2)%3);
	three = DT[x-1][(c+2)%3];

	return color[x][c] + min( two, three);
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d %d", &color[i][0], &color[i][1], &color[i][2]);

	int R = f(N-1, 0);
	int G = f(N-1, 1);
	int B = f(N-1, 2);
	int ans = min(R,G);
	ans = min(ans,B);

	printf("%d\n", ans);

	return 0;
}