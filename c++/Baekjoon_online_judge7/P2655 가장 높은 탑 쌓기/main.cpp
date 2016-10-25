#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

#define INF 987654321

typedef struct {
	int index;
	int width;
	int height;
	int weight;
} Brick;

int N;
int DP[110];
int parent[110];
Brick brick[110];

bool compare(Brick a, Brick b) {
	return a.width > b.width;
}

int f(int n) {
	//if(n>=N) return 0;

	int& ret = DP[n];
	if(ret != -1) return ret;

	ret = brick[n].height;
	for(int i=n+1; i<N; i++) {
		if(brick[n].weight > brick[i].weight) {
			int a = f(i)+brick[n].height;
			if(a>ret) parent[n]=i, ret=a;
		}
	}
	return ret;
}

int main() {

	cin>>N;
	for(int i=0; i<N; i++) {
		brick[i].index=i+1;
		cin>>brick[i].width>>brick[i].height>>brick[i].weight;
	}

	memset(DP,-1,sizeof(DP));
	memset(parent,-1,sizeof(parent));
	sort(brick,brick+N,compare);

	int ans=f(0),maxIndex=0;
	for(int i=1; i<N; i++) {
		if(ans < f(i)) maxIndex=i;
	}

	vector<int> list;
	int n=maxIndex;
	list.push_back(n);
	while(parent[n] != -1) {
		n = parent[n];
		list.push_back(n);
	}
	cout<<list.size()<<endl;
	for(int i=list.size()-1; i>=0; i--) {
		cout<<brick[list[i]].index<<endl;
	}
	return 0;
}