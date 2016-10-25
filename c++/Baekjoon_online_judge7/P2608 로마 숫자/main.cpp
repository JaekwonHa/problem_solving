#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int number1[100], number2[100];
char text1[100], text2[100];

int getNumber(char c) {
	switch(c) {
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	}
}

int main() {
	
	cin>>text1>>text2;
	int answer=0;
	number1[0]=getNumber(text1[0]);
	answer += number1[0];
	for(int i=1; i<strlen(text1); i++) {
		number1[i]=getNumber(text1[i]);
		if(number1[i] > number1[i-1]) {
			answer = answer - number1[i-1] + (number1[i]-number1[i-1]);
		} else {
			answer += number1[i];
		}
	}

	//answer=0;
	number2[0]=getNumber(text2[0]);
	answer += number2[0];
	for(int i=1; i<strlen(text2); i++) {
		number2[i]=getNumber(text2[i]);
		if(number2[i] > number2[i-1]) {
			answer = answer - number2[i-1] + (number2[i]-number2[i-1]);
		} else {
			answer += number2[i];
		}
	}

	
	
	
	int n=answer;
	
	//int n;
	int cnt=0;
	char answerT[1000];
	cin>>n;
	while(n) {
		if(n >= 1000) {
			answerT[cnt++]='M';
			n -= 1000;
		} else if(n >= 100) {

			if(n>=900) {
				answerT[cnt++]='C';
				answerT[cnt++]='M';
			} else if(n>=800) {
				answerT[cnt++]='D';
				answerT[cnt++]='C';
				answerT[cnt++]='C';
				answerT[cnt++]='C';
			} else if(n>=700) {
				answerT[cnt++]='D';
				answerT[cnt++]='C';
				answerT[cnt++]='C';
			} else if(n>=600) {
				answerT[cnt++]='D';
				answerT[cnt++]='C';
			} else if(n>=500) {
				answerT[cnt++]='D';
			} else if(n>=400) {
				answerT[cnt++]='C';
				answerT[cnt++]='D';
			} else if(n>=300) {
				answerT[cnt++]='C';
				answerT[cnt++]='C';
				answerT[cnt++]='C';
			} else if(n>=200) {
				answerT[cnt++]='C';
				answerT[cnt++]='C';
			} else if(n>=100) {
				answerT[cnt++]='C';
			}
			n = n%100;
		} else if(n >= 10) {
			if(n>=90) {
				answerT[cnt++]='X';
				answerT[cnt++]='C';
			} else if(n>=80) {
				answerT[cnt++]='L';
				answerT[cnt++]='X';
				answerT[cnt++]='X';
				answerT[cnt++]='X';
			} else if(n>=70) {
				answerT[cnt++]='L';
				answerT[cnt++]='X';
				answerT[cnt++]='X';
			} else if(n>=60) {
				answerT[cnt++]='L';
				answerT[cnt++]='X';
			} else if(n>=50) {
				answerT[cnt++]='L';
			} else if(n>=40) {
				answerT[cnt++]='X';
				answerT[cnt++]='L';
			} else if(n>=30) {
				answerT[cnt++]='X';
				answerT[cnt++]='X';
				answerT[cnt++]='X';
			} else if(n>=20) {
				answerT[cnt++]='X';
				answerT[cnt++]='X';
			} else if(n>=10) {
				answerT[cnt++]='X';
			}
			n = n%10;
		} else {
			if(n>=9) {
				answerT[cnt++]='I';
				answerT[cnt++]='X';
			} else if(n>=8) {
				answerT[cnt++]='V';
				answerT[cnt++]='I';
				answerT[cnt++]='I';
				answerT[cnt++]='I';
			} else if(n>=7) {
				answerT[cnt++]='V';
				answerT[cnt++]='I';
				answerT[cnt++]='I';
			} else if(n>=6) {
				answerT[cnt++]='V';
				answerT[cnt++]='I';
			} else if(n>=5) {
				answerT[cnt++]='V';
			} else if(n>=4) {
				answerT[cnt++]='I';
				answerT[cnt++]='V';
			} else if(n>=3) {
				answerT[cnt++]='I';
				answerT[cnt++]='I';
				answerT[cnt++]='I';
			} else if(n>=2) {
				answerT[cnt++]='I';
				answerT[cnt++]='I';
			} else if(n>=1) {
				answerT[cnt++]='I';
			}
			n=0;
		}
	}
	answerT[cnt]='\0';
	cout<<answer<<endl;
	cout<<answerT<<endl;
	return 0;
}