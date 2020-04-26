#include <iostream>
using namespace std;

int w[100][100],n;
int sum[100];

void TS(void) {
	int rest = n;
	int i,j;
	while(rest--) {
		for(i=0; i<n; i++) {
			if(sum[i]==0) break;
		}
		// 현재 처리되는 작업
		sum[i]=-1;
		cout<<i+1<<" ";

		// 현재 작업이 이전 작업의 합계에 더해진 작업들에 대해서
		// 이전 작업 합계를 1씩 감소시킨다.
		for(j=0; j<n; j++) {
			if(w[i][j]) sum[j]--;
		}
	}
}

int main() {
	int m,a,b;
	cin>>n>>m;
	while(m--) {
		cin>>a>>b;

		w[a-1][b-1]=1;
		sum[b-1]++;
	}

	TS();

	return 0;
}