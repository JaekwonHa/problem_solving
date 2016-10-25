#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

int N;
stack<int> st;

int main() {

	scanf("%d", &N);
	for(int t=0; t<N; t++) {
		char input[6];
		int a;
		scanf("%s", &input);
		if(strcmp(input,"push")==0) {
			scanf("%d", &a);
			st.push(a);
		} else if (strcmp(input,"pop")==0) {
			if(st.empty()) printf("-1\n");
			else {
				a = st.top();
				printf("%d\n", a);
				st.pop();
			}
		} else if (strcmp(input,"size")==0) {
			printf("%d\n", st.size());
		} else if (strcmp(input,"empty")==0) {
			printf("%d\n", st.empty()?1:0);
		} else if (strcmp(input,"top")==0) {
			if(st.empty()) printf("-1\n");
			else printf("%d\n", st.top());
		}
	}

	return 0;
}