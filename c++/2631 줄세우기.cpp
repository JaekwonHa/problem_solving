#include <stdio.h>
#include <vector>
#include <algorithm>

int N,arr[1000];
std::vector<int> list;
std::vector<int> parent(1000, -1);

void solve() {
	list.push_back(arr[0]);

	for(int i=1; i<N; i++) {
		int last = list.back();
		if(last < arr[i]) {
			list.push_back(arr[i]);
			parent[arr[i]]=last;
		} else {
			std::vector<int>::iterator it = std::lower_bound(list.begin(), list.end(), arr[i]);
			*it = arr[i];
			if(it!=list.begin()) {
				// list의 lower bound 보다 한칸 앞의 것을 가르키게 한다 !!
				parent[arr[i]]=*(--it);
			}
		}
	}
}

int main() {

	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	solve();

	printf("%d", N-list.size());

	return 0;
}