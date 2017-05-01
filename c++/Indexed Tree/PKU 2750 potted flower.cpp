#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int sum,maxsum,leftmax,rightmax;
	int minsum,leftmin,rightmin;
};

int T,N,M,base;
node tree[1<<24];

void update(int i, int b) {
	tree[i].leftmin=tree[i].leftmax=tree[i].rightmin=tree[i].rightmax=tree[i].minsum=tree[i].maxsum=tree[i].sum=b;
	
	i>>=1;
	while(i) {
		tree[i].sum=tree[2*i].sum+tree[2*i+1].sum;
		
		tree[i].maxsum=max(tree[2*i].maxsum,tree[2*i+1].maxsum);
		tree[i].maxsum=max(tree[i].maxsum,tree[2*i].rightmax+tree[2*i+1].leftmax);

		tree[i].leftmax=max(tree[2*i].leftmax,tree[2*i].sum+tree[2*i+1].leftmax);

		tree[i].rightmax=max(tree[2*i+1].rightmax, tree[2*i].rightmax+tree[2*i+1].sum);

		tree[i].minsum=min(tree[2*i].minsum,tree[2*i+1].minsum);
		tree[i].minsum=min(tree[i].minsum,tree[2*i].rightmin+tree[2*i+1].leftmin);

		tree[i].leftmin=min(tree[2*i].leftmin,tree[2*i].sum+tree[2*i+1].leftmin);

		tree[i].rightmin=min(tree[2*i+1].rightmin, tree[2*i].rightmin+tree[2*i+1].sum);
		i>>=1;
	}
}

int main() {
	cin>>N;
	for(base=1; base<N; base*=2);
		for(int i=base; i<base*2; i++) {
			tree[i].minsum=tree[i].leftmin=tree[i].rightmin=5000;
		}
		for(int i=base; i<N+base; i++) {
			cin>>tree[i].sum;
			tree[i].minsum=tree[i].leftmin=tree[i].rightmin=tree[i].maxsum=tree[i].rightmax=tree[i].leftmax=tree[i].sum;
		}
		for(int i=base-1; i>0; i--) {
			tree[i].sum=tree[2*i].sum+tree[2*i+1].sum;
		
			tree[i].maxsum=max(tree[2*i].maxsum,tree[2*i+1].maxsum);
			tree[i].maxsum=max(tree[i].maxsum,tree[2*i].rightmax+tree[2*i+1].leftmax);

			tree[i].leftmax=max(tree[2*i].leftmax,tree[2*i].sum+tree[2*i+1].leftmax);

			tree[i].rightmax=max(tree[2*i+1].rightmax, tree[2*i].rightmax+tree[2*i+1].sum);

			tree[i].minsum=min(tree[2*i].minsum,tree[2*i+1].minsum);
			tree[i].minsum=min(tree[i].minsum,tree[2*i].rightmin+tree[2*i+1].leftmin);

			tree[i].leftmin=min(tree[2*i].leftmin,tree[2*i].sum+tree[2*i+1].leftmin);

			tree[i].rightmin=min(tree[2*i+1].rightmin, tree[2*i].rightmin+tree[2*i+1].sum);
		}
		int a,b;
		cin>>M;
		while(M--) {
			cin>>a>>b;
			update(base+a-1,b);
			if(tree[1].sum==tree[1].maxsum) {
				int ans=5000;
				for(int i=base; i<base+N; i++)
					ans = min(ans,tree[i].sum);
				//cout<<tree[1].sum-ans<<endl;
				cout<<tree[1].sum-tree[1].minsum<<endl;
			} else {
				// 그냥 전체합 - 최소값 출력
				cout<<max(tree[1].maxsum,tree[1].sum-tree[1].minsum)<<endl;
			}
		}
	return 0;
}

/*
5
3 -2 1 2 -5
4
2 -2
5 -5
2 -4
5 -1

*/