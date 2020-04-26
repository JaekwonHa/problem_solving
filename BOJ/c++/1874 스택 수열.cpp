#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int N, arr[100010];
stack<int> st;
vector<char> ans;

int main() {

	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d", &arr[i]);
	}

	int i=1,j=1;
	bool b=true;
	while(j<=N) {
		if(st.empty()) {
			st.push(i++);
			ans.push_back('+');
			continue;
		}
		if(st.top()==arr[j]) {
			st.pop(), j++;
			ans.push_back('-');
			continue;
		}
		if(st.top()<arr[j]) {
			st.push(i++);
			ans.push_back('+');
			continue;
		}
		if(st.top()>arr[j]) {
			b=false;
			break;
		}
	}
	if(j!=N+1) b=false;

	if(b) {
		for(int i=0; i<ans.size(); i++) printf("%c\n", ans[i]);
	} else {
		printf("NO\n");
	}


	return 0;
}