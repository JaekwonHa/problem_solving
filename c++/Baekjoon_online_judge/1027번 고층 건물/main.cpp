#include <iostream>

using namespace std;

int N;
double B[51];

int calc(int x) {
	//left
	int answer=0;
	double left=-9999999999, right=-9999999999, angle=1;
	for(int i=x-1; i>0; i--) {
		angle = (B[i]-B[x]) / (x-i);
		if(angle > left) {
			answer++;
			left = angle;
		}
	}
	for(int i=x+1; i<=N; i++) {
		angle = (B[i]-B[x]) / (i-x);
		if(angle > right) {
			answer++;
			right = angle;
		}
	}

	return answer;
}

int main() {

	int i;
	cin>>N;

	for(i=1; i<=N; i++) {
		cin>>B[i];
	}
	int answer = 0;
	for(i=1; i<=N; i++) {
		answer = max(answer, calc(i));
	}
	cout<<answer<<endl;
}