#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

char display[23][96];

void write(int number, int x, int size) {
	int i,j;

	display[0][x]=' ';
	display[0][x+size+1]=' ';
	if(number == 1 || number == 4) for(i=1; i<=size; i++) display[0][x+i]=' ';
	else for(i=1; i<=size; i++) display[0][x+i]='-';

	if(number == 1 || number ==2 || number == 3 || number ==7) {
		for(j=1; j<=size; j++) {
				display[j][x+size+1]='|';
		}
	} else if(number == 5 || number ==6) {
		for(j=1; j<=size; j++) {
			display[j][x]='|';
		}
	} else {
		for(j=1; j<=size; j++) {
			display[j][x]='|';
			display[j][x+size+1]='|';
		}
	}

	display[size+1][x] = ' ';
	display[size+1][x+size+1] = ' ';
	if(number == 1 || number == 7 || number == 0) for(i=1; i<=size; i++) display[size+1][x+i]=' ';
	else for(i=1; i<=size; i++) display[size+1][x+i]='-';

	if(number == 1 || number ==3 || number == 4 || number == 5 || number == 7 || number == 9) {
		for(j=1; j<=size; j++) {
			display[size+1+j][x+size+1]='|';
		}
	} else if(number == 2) {
		for(j=1; j<=size; j++) {
			display[size+1+j][x]='|';
		}
	} else {
		for(j=1; j<=size; j++) {
			display[size+1+j][x]='|';
			display[size+1+j][x+size+1]='|';
		}
	}

	display[2*size+2][x] = ' ';
	display[2*size+2][x+size+1] = ' ';
	if(number == 1 || number == 4 || number == 7) for(i=1; i<=size; i++) display[2*size+2][x+i]=' ';
	else for(i=1; i<=size; i++) display[2*size+2][x+i]='-';

}

int main () {

	int s, input, number[8], digit, count,i,j;
	char in[8];
	memset(in, 0, 8*sizeof(char));

	int flag=0;

	while(cin>>s>>in) {
		//if(s==0 && input==0) break;
		if(s==0) break;
		/*
		if(!flag) {
			flag=1;
		} else {
			cout<<"\n";
		}
		*/
		memset(display, ' ', 23*96*sizeof(char));

		int digit=0;
		while(in[digit]!=0) {
			number[digit] = in[digit] - '0';
			digit++;
		}
		digit--;
		for(i=0; i<=digit; i++) {
			write(number[i], i*(s+2), s);
		}
		
		for(j=0; j<2*s+3; j++) {
			if(j!=0) cout<<"\n";
			for(i=0; i<=digit; i++) {
				if(i!=0) cout<<" ";
				for(int k=0; k<s+2; k++) {
					cout<<display[j][i*(s+2) + k];
				}
			}
		}
		cout<<"\n";
		cout<<"\n";
		memset(in, 0, 8*sizeof(char));
	}

	return 0;
}