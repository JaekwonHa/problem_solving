#include <stdio.h>
#define INF 987654321

int m[21][21], col_check[21],n;
int bit;
int DT[1<<20];

void input() {
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &m[i][j]);
}

int min(int a, int b) {return (a>b)? b:a;}

int solve(int row) {
	int ans=INF;
	if(row==n) return 0;
	for(int i=0; i<n; i++) {
		if(col_check[i]==0) {
			col_check[i]=1;
			ans=min(ans, solve(row+1)+m[row][i]);
			col_check[i]=0;
		}
	}
	return ans;
}

int f(int row) {
	int ans=INF;
	if(row==n) return 0;
	for(int i=0; i<n; i++) {
		if((bit&(1<<i))==0) {
			bit+=(1<<i);
			ans = min(ans, f(row+1)+m[row][i]);
			bit-=(1<<i);
		}
	}
	return ans;
}
int f2(int row, int bit) {
	if(row==n) return 0;
	if(DT[bit]==0) {
		DT[bit]=INF;
		for(int i=0; i<n; i++) {
			if((bit&(1<<i))==0) {
				DT[bit]=min(DT[bit], f2(row+1, bit+(1<<i))+m[row][i]);
			}
		}
	}
	return DT[bit];
}

int main() {

	input();
	printf("%d", solve(0));
	return 0;
}