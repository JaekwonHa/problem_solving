#include <stdio.h>
#include <vector>
#include <algorithm>

struct node {
	int a,b;
};
bool compare(node x, node y) {
	return x.a < y.a;
}

int n;
node list[100000];
std::vector<int> LIS;
std::vector<int> parent(500001, -1);
std::vector<int> ans;

0int main() {

	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d %d", &list[i].a, &list[i].b);

	std::sort(list, list+n, compare);

	LIS.push_back(list[0].b);
	for(int i=1; i<n; i++) {
		if(LIS.back() < list[i].b) {
			parent[list[i].b] = LIS.back();
			LIS.push_back(list[i].b);
		} else {
			std::vector<int>::iterator it = std::lower_bound(LIS.begin(), LIS.end(), list[i].b);
			*it = list[i].b;
			if(it != LIS.begin()) {
				parent[list[i].b] = *(--it);
			}
		}
	}
	printf("%d\n", n-LIS.size());
	int child=LIS.back();
	/*
	while(child!=-1) {
		ans.push_back(child);
		child = parent[child];
	}
	*/
	
	for(int i=n-1; i>=0; i--) {
		if(list[i].b == child) {
			child = parent[child];
			continue;
		}
		ans.push_back(list[i].a);
	}
	std::vector<int>::iterator it = ans.end();
	for(int i=ans.size()-1; i>=0; i--) {
		it--;
		printf("%d\n", *it);
	}

	return 0;
}