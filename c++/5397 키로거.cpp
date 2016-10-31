#include <iostream>
#include <algorithm>
#include <list>
#include <string>
using namespace std;

list<char> pass;
list<char>::iterator point;
string str;

void move_left() {
	if(!pass.empty() && point!=pass.begin()) point--;
}

void move_right() {
	if(point!=pass.end()) point++;
}

int main() {

	int T;
	cin>>T;
	while(T--) {
		cin>>str;
		pass.clear();
		point = pass.begin();
		for(int i=0; i<str.length(); i++) {

			char word = str[i];
			if(word=='<') {
				move_left();
			} else if(word=='>') {
				move_right();
			} else if(word=='-') {
				if(pass.empty()) continue;
				move_left();
				if(point==pass.end()) {
					pass.pop_back();
					point=pass.end();
				} else if(point==pass.begin()) {
					pass.pop_front();
					point=pass.begin();
				} else {
					pass.erase(point);
				}
			} else {
				move_right();
				if(point==pass.end()) {
					pass.push_back(word);
					point=pass.end();
				} else if(point==pass.begin()) {
					pass.push_front(word);
					point = pass.begin();
					point++;
				} else {
					pass.insert(point,word);
				}
			}
		}
		list<char>::iterator it;
		for(it=pass.begin(); it!=pass.end(); it++) {
			cout<<*it;
		}
		cout<<endl;
	}
	return 0;
}