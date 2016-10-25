#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,Xi[1010],Yi[1010],Ri[1010];
vector<int> list;

int dist(int x1, int y1, int x2, int y2) {
	return sqrt( pow(abs(x1-x2),2.0) + pow(abs(y1-y2),2.0) );
}

bool solve(int n) {

	if(Xi[n] == -1000 || Xi[n] == 1000 || Yi[n] == -1000 || Yi[n] == 1000) return true;

	if(-1000 < Xi[n] && Xi[n] < 1000) {
		if(Yi[n] < -1000) {
			//case 8
			if(dist(Xi[n],Yi[n],Xi[n],-1000) < Ri[n]) return true;
		} else if(1000 < Yi[n]) {
			//case 2
			if(dist(Xi[n],Yi[n],Xi[n],1000) < Ri[n]) return true;
		} else {
			//case 5
			return true;
		}
	}

	if(-1000 < Yi[n] && Yi[n] < 1000) {
		if(Xi[n] < -1000) {
			//case 4
			if(dist(Xi[n],Yi[n],-1000,Yi[n]) < Ri[n]) return true;
		} else if(1000 < Xi[n]) {
			//case 6
			if(dist(Xi[n],Yi[n],1000,Yi[n]) < Ri[n]) return true;
		}
	}

	if(Xi[n] < -1000 && 1000 < Yi[n]) {
		//case 1
		if(dist(Xi[n],Yi[n],-1000,1000) < Ri[n]) return true;
	}
	if(1000 < Xi[n] && 1000 < Yi[n]) {
		//case 3
		if(dist(Xi[n],Yi[n],1000,1000) < Ri[n]) return true;
	}
	if(Xi[n] < -1000 && Yi[n] < -1000) {
		//case 7
		if(dist(Xi[n],Yi[n],-1000,-1000) < Ri[n]) return true;
	}
	if(1000 < Xi[n] && Yi[n] < -1000) {
		//case 9
		if(dist(Xi[n],Yi[n],1000,-1000) < Ri[n]) return true;
	}
	return false;
}

int main() {

	cin>>N;
	for(int i=0; i<N; i++) cin>>Xi[i]>>Yi[i]>>Ri[i];

	for(int i=0; i<N; i++) {
		if(solve(i)) list.push_back(i);
	}

	cout<<list.size()<<endl;
	for(int i=0; i<list.size(); i++) {
		cout<<list[i]+1<<endl;
	}


	return 0;
}