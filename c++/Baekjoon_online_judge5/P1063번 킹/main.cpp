#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int kingRow, kingCol;
int stoneRow, stoneCol;

int main() {

	char r[2];
	char move[2];
	scanf("%s", &r);
	kingCol = r[0]-'A'+1;
	kingRow = r[1]-'1'+1;
	scanf("%s", &r);
	stoneCol = r[0]-'A'+1;
	stoneRow = r[1]-'1'+1;
	scanf("%d", &N);

	for(int i=0; i<N; i++) {
		scanf("%s", &move);
		int moveR=0, moveC=0;
		if(strcmp(move,"R")==0) {
			moveC++;
		} else if(strcmp(move,"L")==0) {
			moveC--;
		} else if(strcmp(move,"B")==0) {
			moveR--;
		} else if(strcmp(move,"T")==0) {
			moveR++;
		} else if(strcmp(move,"RT")==0) {
			moveC++;
			moveR++;
		} else if(strcmp(move,"LT")==0) {
			moveC--;
			moveR++;
		} else if(strcmp(move,"RB")==0) {
			moveC++;
			moveR--;
		} else if(strcmp(move,"LB")==0) {
			moveC--;
			moveR--;
		}
		if(kingRow+moveR<1 || kingRow+moveR>8 || kingCol+moveC<1 || kingCol+moveC>8) continue;
		
		if(kingRow+moveR==stoneRow && kingCol+moveC==stoneCol) {
			if(stoneRow+moveR<1 || stoneRow+moveR>8 || stoneCol+moveC<1 || stoneCol+moveC>8) {
			} else {
				kingRow+=moveR, kingCol+=moveC, stoneRow+=moveR, stoneCol += moveC;
			}
		} else {
			kingRow+=moveR, kingCol+=moveC;
		}
	}
	r[0]=kingCol+'A'-1;
	r[1]=kingRow+'1'-1;
	printf("%s\n", r);
	r[0]=stoneCol+'A'-1;
	r[1]=stoneRow+'1'-1;
	printf("%s\n", r);


	return 0;
}