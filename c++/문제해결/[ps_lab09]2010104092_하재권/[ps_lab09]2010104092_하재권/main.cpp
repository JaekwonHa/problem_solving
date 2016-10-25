#include <iostream>
#include <string.h>

using namespace std;

char matrix[75][75];
int check[75][75][2];
int cycle, maxlength,h,w;
int step[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int DetermineNextc(int a, int b, int c, int nexta, int nextb, int i) {
	int nextc = -1;

	switch(i) {
	case 0:
		if((c==0 && matrix[a][b]=='/')||(c==1 && matrix[a][b]=='\\')) {
			if(matrix[nexta][nextb]=='/') nextc=1;
			else nextc=0;
		}
		break;
	case 1:
		if(c==1) nextc=0;
		break;
	case 2:
		if((c==0 && matrix[a][b]=='\\')||(c==1&&matrix[a][b]=='/')) {
			if(matrix[nexta][nextb]=='/') nextc=0;
			else nextc=1;
		}
		break;
	case 3:
		if(c==0) nextc=1;
		break;
	}
	return nextc;
}

void DFS(int a, int b, int c, int depth) {
	int i, nexta, nextb, nextc;
	check[a][b][c] = depth;
	for(i=0; i<4; i++) {
		nexta = a+step[i][0];
		nextb = b+step[i][1];
		if(nexta<0 || nexta>=h || nextb<0 || nextb >= w)
			continue;
		nextc = DetermineNextc(a,b,c,nexta, nextb, i);

		if(nextc!=-1 && check[nexta][nextb][nextc]) {
			if(check[nexta][nextb][nextc] < depth-1) {
				cycle++;
				if(maxlength<depth) maxlength=depth;
			}
		} else if(nextc!=-1)
			DFS(nexta, nextb, nextc, depth+1);
	}
}

int main() {
	int n=1,i,j,k;

	while(1) {
		memset(check, 0, 75*75*2*sizeof(int));
		cycle=0, maxlength=0;
		cin>>w>>h;
		if(w==0 && h==0) break;
		for(i=0; i<h; i++) {
			for(j=0; j<w; j++) {
				cin>>matrix[i][j];
			}
		}
		for(i=0; i<h; i++) {
			for(j=0; j<w; j++) {
				for(k=0; k<2; k++) {
					if(!check[i][j][k])
						DFS(i,j,k,1);
				}
			}
		}
		
		cout<<"Maze #"<<n<<":"<<endl;
		if(cycle)
			cout<<cycle<<" Cycles; the longest has length "<<maxlength<<".\n";
		else
			cout<<"There are no cycles.\n";
		cout<<endl;
		
		n++;
	}
	return 0;
}