#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 310

// upper bound에 어느정도 여유를 줘야한다.
// max값이 입력됬을때 작동하지 않을 수 있기 때문이다.
// 그리고 조건에 따라서 return false, return true를 잘 생각해야 한다.
// 이거에 따라서 다음 값이 증가할지 감소할지 결정되기 때문이다.


int N,M,lb,ub,m,arr[MAXN],cnt[MAXN],temp[MAXN];

bool promise(int x) {
	int groupCnt=1,sum=0;
	fill(temp,temp+M,0);
	for(int i=0; i<N; i++) {
		if(groupCnt>M) return false;
		if(sum+arr[i]<=x) {
			sum+=arr[i],temp[groupCnt-1]++;
		} else {
			sum = arr[i],groupCnt++,temp[groupCnt-1]++;
		}
	}
	return (groupCnt<=M)?true:false;
}

int main() {
	cin>>N>>M;
	for(int i=0; i<N; i++) cin>>arr[i];

	int ans=0x7fffffff;
	ub=300*100;
	while(lb<ub) {
		m = (lb+ub-1)/2;
		if(promise(m)) {
			ub=m;
			copy(temp,temp+M,cnt);
			ans = min(ans,m);
		} else {
			lb=m+1;
		}
	}

	cout<<ans<<endl;
	for(int i=0; i<M; i++) {
		cout<<cnt[i]<<" ";
	}
	cout<<endl;

	return 0;
}

/*
8 3
5 4 2 6 9 3 8 7

*/