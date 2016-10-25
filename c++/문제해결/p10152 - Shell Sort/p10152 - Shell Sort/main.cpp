#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

using namespace std;

map<string, int> position;

bool compare(string s1, string s2) {
	return position[s1] > position[s2];
}

int main() {

	int cases,i,j,tutle_count;
	string tutle_name;

	vector<string> start;
	vector<string> end;
	vector<string> result;

	cin>>cases;

	for(int c=0; c<cases; c++) {
		start.clear();
		end.clear();
		result.clear();
		position.clear();

		cin>>tutle_count;
		char *a = new char[1];
		gets(a);
		for(i=0; i<tutle_count; i++) {
			getline(cin, tutle_name);
			start.push_back(tutle_name);
		}
		for(i=0; i<tutle_count; i++) {
			getline(cin, tutle_name);
			//end.push_back(tutle_name);
			position[tutle_name] = i;
		}

		int shift=0;
		for(i=tutle_count-1; i>=0; i--) {
			if(i+shift != position[start.at(i)]) {
				result.push_back(start.at(i));
				shift++;
			}
		}
		sort(result.begin(), result.end(), compare);
		for(i=0; i<result.size(); i++) cout<<result.at(i)<<endl;
		cout<<endl;
	}

	return 0;
}