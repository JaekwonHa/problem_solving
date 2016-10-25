#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int N,arr[110];
stack<int> s1,s2;

int main() {

	cin>>N;
	for(int i=1; i<=N; i++) cin>>arr[i];

	for(int i=1; i<=N; i++) {
		for(int j=0; j<arr[i]; j++) {
			if(s1.empty()) break;
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(i);
		while(!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}
	int i=1;
	while(!s1.empty()) {
		arr[i++]=s1.top();
		s1.pop();
	}
	for(i=N; i>0; i--) {
		if(i!=N) cout<<" ";
		cout<<arr[i];
	}
	return 0;
}