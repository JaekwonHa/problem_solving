#include <iostream>
#include <algorithm>
using namespace std;

char map[800][800];
int chk[800][800][4];
int R,C;

int main() {
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++)
		scanf("%s", map[i]);

	for(int i=R-1; i>=0; i--) {
		for(int j=C-1; j>=0; j--) {
			chk[i][j][0] = chk[i][j][1] = (map[i][j]=='1')?1:0;
			//chk[i][j][0] = chk[i][j][1] = map[i][j]=='1';
			if(chk[i][j][0]==0) continue;
			if(i+1<R && j-1>=0)
				chk[i][j][0] = chk[i+1][j-1][0]+chk[i][j][0];
			if(i+1<R && j+1<C)
				chk[i][j][1] = chk[i+1][j+1][1]+chk[i][j][1];
		}
	}

	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			chk[i][j][2] = chk[i][j][3] = (map[i][j]=='1')?1:0;
			//chk[i][j][2] = chk[i][j][3] = map[i][j]=='1';
			if(chk[i][j][2]==0) continue;
			if(i-1>=0 && j-1>=0)
				chk[i][j][2] = chk[i-1][j-1][2]+chk[i][j][2];
			if(i-1>=0 && j+1<C)
				chk[i][j][3] = chk[i-1][j+1][3]+chk[i][j][3];
		}
	}

	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			chk[i][j][0] = chk[i][j][1] = min(chk[i][j][0],chk[i][j][1]);
			chk[i][j][2] = chk[i][j][3] = min(chk[i][j][2],chk[i][j][3]);
		}
	}
	int ans=0;

	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			for(int k=ans+1; k<=chk[i][j][0]; k++) {
				int oi = i+(k-1)*2;
				if(oi>=R) continue;
				if(chk[oi][j][2]>=k) ans = k;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}