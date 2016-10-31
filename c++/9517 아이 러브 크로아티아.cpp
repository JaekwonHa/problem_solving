#include <iostream>
#include <algorithm>
using namespace std;

int K,N;
int current_T,ans;
bool last;

int main() {
	int T;
	char Z;
	scanf("%d", &K);
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d %c", &T, &Z);
		current_T += T;
		if(current_T<=210) {
			ans=K;
			last = true;
		} else if(last==true) {
			ans=K;
			last=false;
		}
		if(Z=='T') {
			K = K+1;
			if(K>8) K=1;
		}
	}
	printf("%d\n", ans);


	return 0;
}