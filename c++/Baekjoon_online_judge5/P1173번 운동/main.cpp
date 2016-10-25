#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N,m,M,T,R;
	scanf("%d %d %d %d %d", &N, &m, &M, &T, &R);

	int t=0;
	int mac=m;
	long long ans=0;

	if(mac+T>M) {
		ans=-1;
	} else {
		while(t<N) {
			ans++;
			if(mac+T <= M) {
				mac+=T;
				t++;
			} else {
				mac-=R;
				if(mac<m) mac=m;
			}
			if(ans>100000000) {
				ans=-1;
				break;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}