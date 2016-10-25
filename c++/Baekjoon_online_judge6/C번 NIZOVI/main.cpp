#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;



void print_left(int indent) {
	for(int i=0; i<indent; i++) {
		printf("  ");
	}
}


int main() {

	string str;
	cin>>str;
	int indent=0;
	bool first=true;
	for(int i=0; i<str.length(); i++) {
		if(str[i]=='{') {
			print_left(indent);
			printf("{\n");
			indent++;
		} else if(str[i]=='}') {
			if(!first) {
				printf("\n");
			}
			indent--;
			print_left(indent);
			printf("}");
			first=true;
			if(i+1 < str.length()) {
				if(str[i+1]=='}') {
					first=false;
				}
			}
			
		} else if(str[i]==',') {
			printf(",\n");
			first=true;
		} else {
			if(first) {
				print_left(indent);
			}
			printf("%1c", str[i]);
			first=false;
		}
	}


	return 0;
}