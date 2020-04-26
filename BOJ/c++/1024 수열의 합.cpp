#include <iostream>

using namespace std;

int main() {

	//while(1) {
	int N,L,i,j,answer=-1;
	cin>>N>>L;

	for(i=1; i<=N; i++) {
		if(N%i == 0 && i==L-1 && N/i==1) {		// 0부터 시작하는 답을 거르기 위한 조건문
			answer = 0;
			i++;
			break;
		}
		if(N%i == 0 && i>=L) {
			answer = N / i;
			break;
		}
		N-=i;
	}
	if(answer==-1 || i>100) cout<<"-1"<<endl;
	else {
		for(j=0; j<i; j++) {
			if(j!=0) cout<<" ";
			cout<<answer++;
		}
		cout<<endl;
	}
	//}

	return 0;
}