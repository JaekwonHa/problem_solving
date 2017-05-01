#include <iostream>
#include <algorithm>
#include <string.h>
//#include <stack>
using namespace std;

int N;
char arr[15][15];
bool visit[15];
//stack<int> s;

bool solve(int n,int cnt) {
	bool chk=true;
	for(int i=0; i<N; i++) {
		if(visit[i]==false) chk=false;
	}
	if(chk==true) return true;

	int len=strlen(arr[n]);
	char end = arr[n][len-1];

	for(int i=0; i<N; i++) {
		if(visit[i]==true) continue;
		if(end==arr[i][0]) {
			visit[i]=true;
			//s.push(i);
			if(solve(i,cnt+1)==true) {
				return true;
			}
			visit[i]=false;
			//s.pop();
		}
	}
	return false;
}

int main() {
    
	cin>>N;
	for(int i=0; i<N; i++) {
		cin>>arr[i];
	}

	bool ans=false;
	for(int i=0; i<N; i++) {
		//memset(visit,false,sizeof(visit));
		visit[i]=true;
		//s.push(i);
		if(solve(i,1)==true) {
			ans=true;
			break;
		}
		visit[i]=false;
		//s.pop();
	}
	
	if(ans==true) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}

	return 0;
}