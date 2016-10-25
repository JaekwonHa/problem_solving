#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int main() {

	int answer_cases, i,j, test_cases, count=1;
	char input[1000];
	string answer_digit, test_digit, answer, test;
	while(gets(input) != NULL) {
		answer_cases = atoi(input);
		if(answer_cases == 0) break;

		answer_digit = "", test_digit = "", answer = "", test = "";
		for(i=0; i<answer_cases; i++) {
			gets(input);
			
			if(i!=0) answer += "\n";
			answer += input;
			for(j=0; j<strlen(input); j++) {
				if(isdigit(input[j]))	answer_digit += input[j];
			}
			
		}
		gets(input);
		test_cases = atoi(input);
		for(i=0; i<test_cases; i++) {
			gets(input);
			if(i!=0) test += "\n";
			test += input;
			for(j=0; j<strlen(input); j++) {
				if(isdigit(input[j]))	test_digit += input[j];
			}
			
		}

		bool AC=true, PE=false;
		if(answer_digit != test_digit) AC=false;
		if(answer != test) PE=true;

		cout<<"Run #"<<count<<": ";

		if(!AC) cout<<"Wrong Answer"<<"\n";
		else if(AC && PE) cout<<"Presentation Error"<<"\n";
		else cout<<"Accepted"<<"\n";
		count++;
	}

	return 0;
}