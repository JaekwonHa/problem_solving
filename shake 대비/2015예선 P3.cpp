#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int N;
vector<int> Ai[110];
int visit[110];
int maxIndex;

bool f(int n) {
	int cur;
	for(int i=0; i<Ai[n].size(); i++) {
		cur=Ai[n][i];
		if(visit[cur] == 0) visit[cur]=maxIndex++;
		if(visit[n] > visit[cur]) return false;
		if(f(cur)==false) return false;
	}
	return true;
}

int main() {

	cin>>N;
	int A,input,i,j;
	for(i=1; i<=N; i++) {
		cin>>A;
		for(j=0; j<A; j++) {
			cin>>input;
			Ai[i].push_back(input);
		}
	}
	bool answer=true;
	
	for(i=1; i<=N; i++) {
		maxIndex=1;
		memset(visit,0,sizeof(visit));
		if(visit[i]==0) visit[i] = maxIndex++;
		if(f(i)==false) answer = false;
	}

	if(answer==true) {
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}

	return 0;
}