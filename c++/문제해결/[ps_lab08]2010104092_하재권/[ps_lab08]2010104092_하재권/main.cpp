#include <iostream>

using namespace std;


static int puzzle[4][4],cost,solved,mtop,movestack[50];
static int dir[4][2]={ {1,0}, {0,1},{-1,0}, {0,-1}};
static char step[4]={ 'D', 'R','U', 'L'};
static int CumScore;
int conv[16]={0,1,5,9,13,2,6,10,14,3,7,11,15,4,8,12};
int cnvp[16]={0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15};

int Manhatoncost() {
	
	int i,j,md1=0,md2=0,inv1=0,inv2=0,id1,id2,lowb1,lowb2,board[16];
	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			if(puzzle[i][j]!=0) {
				int a,b;
				a = (i-((puzzle[i][j]-1)/4));
				if(a<0) a=-a;
				b = (j-((puzzle[i][j]-1)%4));
				if(b<0) b=-b;
				md1 += a;
				md2 += b;
			}
			board[i*4+j] = puzzle[i][j];
		}
	}
	for(i=0; i<16; i++) {
		for(j=i+1; j<16; j++) {
			if(conv[board[cnvp[j]]] && (conv[board[cnvp[j]]] < conv[board[cnvp[i]]]))
				inv2++;
			if(board[j] && (board[j]<board[i]))
				inv1++;
		}
	}
	id1 = (inv1/3) + (inv1%3);
	id2 = (inv2/3) + (inv2%3);
	lowb1 = (id1>md1)?id1:md1;
	lowb2 = (id2>md2)?id2:md2;
	return lowb1+lowb2;
}
void back(int a,int x,int y) {
	
	int newx, newy,i,j;
	cost = Manhatoncost();

	if(cost==0) {
		solved=1;
		return;
	}
	if(a+cost>CumScore) return;
	for(i=0; i<4; i++) {
		if((movestack[mtop-1]+2)%4==i) continue;
		newx=x+dir[i][0];
		newy=y+dir[i][1];
		if(0<=newx && newx<4 && 0<=newy && newy<4) {
			puzzle[x][y]=puzzle[newx][newy];
			puzzle[newx][newy]=0;
			movestack[mtop]=i;
			mtop++;
			back(a+1, newx, newy);
			if(solved==1) return;
			mtop--;
			puzzle[newx][newy]=puzzle[x][y];
			puzzle[x][y]=0;
		}
	}
}

int main() {
	int cases,i,j,c;
	cin>>cases;

	for(c=0; c<cases; c++) {
		int value=1,k,l,x,y;
		solved=0, mtop=0;

		for(i=0; i<4; i++)
			for(j=0; j<4; j++)
				cin>>puzzle[i][j];
		
		for(i=0; i<4; i++)
			for(j=0; j<4; j++) {
				if(puzzle[i][j]==0) {
					value += i;
					x=i,y=j;
					continue;
				}
				l=j+1;
				for(k=i; k<4; k++) {
					for(; l<4; l++) {
						if(puzzle[k][l]!=0 && puzzle[i][j] > puzzle[k][l]) value++;
					}
					l=0;
				}
			}
		if(value%2==1) {
			cout<<"This puzzle is not solvable."<<endl;
			continue;
		}

		for(CumScore=Manhatoncost(); solved==0 && CumScore<=50; CumScore += 2)
			back(0,x,y);

		if(solved==0)
			cout<<"This puzzle is not solvable."<<endl;
		else {
			if(mtop>0) {
				for(i=0; i<mtop; i++)
				cout<<step[movestack[i]];
				
			}
			cout<<endl;
		}
	}
	return 0;
}