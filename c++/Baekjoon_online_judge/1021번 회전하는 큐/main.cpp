#include <iostream>
#include <string.h>
#include <list>
#include <math.h>
#include <vector>
#include <deque>

using namespace std;

int main() {

	int N,M,m,answer=0;
	cin>>N>>M;

	deque<int> deq;
	vector<int> vec;
	for(int i=1; i<=N; i++) {
		deq.push_back(i);
	}
	for(int i=0; i<M; i++) {
		cin>>m;
		vec.push_back(m);
	}
	for(int i=0; i<M; i++) {
		int current = vec.front();
		int f2 = abs(1 - current);
		int f3 = abs(1+N - current);
		if(f2<=f3) {
			for(int i=0; i<f2; i++) {
				int a = deq.front();
				deq.pop_front();
				deq.push_back(a);
			}
			deq.pop_front();
			answer+=f2;
		} else {
			for(int i=0; i<f3; i++) {
				int a = deq.back();
				deq.pop_back();
				deq.push_front(a);
			}
			deq.pop_front();
			answer+=f3;
		}
		
		vec.erase(vec.begin());
		for(int j=0; j<deq.size(); j++) {
			deq.at(j)=j+1;
		}
		for(int j=0; j<vec.size(); j++) {
			(vec[j] - current >= 0 ) ? vec[j] = abs(vec[j] - current) : vec[j] = abs(vec[j]+N - current);
		}
		N--;
		
	}

	cout<<answer<<endl;
}