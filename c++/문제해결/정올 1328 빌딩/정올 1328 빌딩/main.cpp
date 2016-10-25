#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

struct Building {
	int high;
	int number;
};

int main() {

	int cases,i, result[100001];
	memset(result, 0 , 100001*sizeof(int));
	
	stack<Building> st;

	cin>>cases;
	Building *building;
	building = new Building[cases];

	for(i=1; i<=cases; i++) {
		cin>>building[i].high;
		building[i].number=i;

		if(st.size() == 0) {
			st.push(building[i]);
		}
		else {
			while(st.size() != 0 && building[i].high > st.top().high) {
				result[st.top().number]=i;
				st.pop();
			}
			st.push(building[i]);
		}
	}
	while(st.size() != 0) {
		result[st.top().number]=0;
		st.pop();
	}
	

	for(i=1; i<=cases; i++) {
		cout<<result[i]<<endl;
	}
	

	return 0;
}