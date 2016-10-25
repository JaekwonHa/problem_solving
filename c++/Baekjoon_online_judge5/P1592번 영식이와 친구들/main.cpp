#include <iostream>
#include <algorithm>
using namespace std;

int arr[1010];

int main() {

	int N,M,L;
	scanf("%d %d %d", &N, &M, &L);
	int ans=0;
	int ball=1;
	arr[1]=1;
	while(1) {
		bool b=false;
		for(int i=1; i<=N; i++) {
			if(arr[i]>=M) {
				b=true;
				break;
			}
		}
		if(b==true) break;

		if(arr[ball]%2==0) {
			ball = ball+L;
			if(ball>N) {
				ball = ball-N;
			}
		} else {
			ball = ball-L;
			if(ball<=0) {
				ball = ball+N;
			}
		}
		ans++;
		arr[ball]++;
	}
	printf("%d\n", ans);
	return 0;
}