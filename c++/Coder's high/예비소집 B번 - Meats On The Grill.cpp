#include <iostream>
#include <algorithm>
using namespace std;

char map[15][15];
int H,W,T;

int main() {

	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &H, &W);
		for(int i=0; i<H; i++) {
			scanf("%s", &map[i]);
		}
		for(int i=H-1; i>=0; i--) {
			for(int j=0; j<W; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
	}


	return 0;
}