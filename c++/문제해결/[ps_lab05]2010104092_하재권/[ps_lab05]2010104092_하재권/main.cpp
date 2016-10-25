#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {

	int n, i, u, t, j;
	int sum[36];
	int ans[9];
	int checked[36];

	while(cin>>n) {
		memset(sum, 0, 36*sizeof(int));
		memset(ans, 0, 9*sizeof(int));

		for(i=0; i<n*(n-1)/2; i++) cin>>sum[i];
		sort(sum, sum+(n*(n-1)/2));

		for(u=2; u<n; u++) {
			memset(checked, 0, 36*sizeof(int));
			swap(sum[2], sum[u]);
			t = sum[0] + sum[1] + sum[2];
			if(t%2 == 1) continue;
			t /= 2;
			ans[2] = t - sum[0];
			ans[1] = t - sum[1];
			ans[0] = t - ans[1] - ans[2];

			for(i=3; i<n; i++) {
				t=3;
				while(checked[t]) t++;
				ans[i] = sum[t] - ans[0];
				for(j=0; j<i; j++) {
					while(t<n*(n-1)/2 && (checked[t] || sum[t] != ans[i]+ans[j])) t++;
					if(t==n*(n-1)/2) i=9999;
					checked[t]=1;
				}
			}
			if(i!=10000) {
				for(i=0; i<n; i++) {
					cout<<ans[i];
					if(i!=n-1) cout<<" ";
				}

				cout<<"\n";
				u=9999;
			}
		}
		if(u!=10000) cout<<"Impossible"<<"\n";
	
	}

	return 0;
}