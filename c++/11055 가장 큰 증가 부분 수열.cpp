#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

int N, arr[1001];
long long DT[1001];
std::vector<int> lis;
std::vector<int> parent(1001, -1);

long long max(long long a, long long b) { return (a>b)?a:b;}

long long f(int n) {

	lis.push_back(arr[0]);
	for(int i=1; i<n; i++) {
		int last = lis.back();
		if(last < arr[i]) {
			lis.push_back(arr[i]);
			parent[arr[i]]=last;
		} else {
			std::vector<int>::iterator it = std::lower_bound(lis.begin(), lis.end(), arr[i]);
			*it = arr[i];
			if(it != lis.begin()) {
				parent[arr[i]]=*(--it);
			}
		}
	}
	long long ans=0;
	for(int i=n-1; i>=0; i--) {
		int j = arr[i];
		long long temp=0;
		while(parent[j] != -1) {
			temp += j;
			j = parent[j];
		}
		ans = max(ans,temp+j);
	}
	return ans;
}

long long f2(int n) {
	memset(DT,-1,sizeof(DT));
	//parent[0]=0;
	for(int i=0; i<n; i++) {
		DT[i]=1;
		for(int j=0; j<i; j++) {
			if(arr[j] < arr[i] && DT[i] < DT[j]+1) {
				DT[i]=DT[j]+1;
				parent[i]=j;
			}
		}
	}
	long long ans = 0;
	for(int i=n-1; i>=0; i--) {
		long long j = i, temp = 0;
		while(parent[j]!=-1) {
			temp += arr[j];
			j = parent[j];
		}
		ans = max(ans, temp+arr[j]);
	}

	return ans;
}
long long f3(int n) {
	for(int i=0; i<n; i++) {
		DT[i]=arr[i];
		for(int j=0; j<i; j++) {
			if(arr[j]<arr[i] && DT[i]<DT[j]+arr[i]) {
				DT[i] = DT[j]+arr[i];
			}
		}
	}
	long long ans = 0;
	for(int i=0; i<n; i++) {
		ans = max(ans, DT[i]);
	}
	return ans;
}

int main() {

	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	printf("%lld", f3(N));

	return 0;
}