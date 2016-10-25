#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, arr[40010];
vector<int> LIS;

void solve() {
	for(int i=0; i<N; i++) {
		if(LIS.empty()) {
			LIS.push_back(arr[i]);
		} else {
			if(arr[i] > LIS.back()) {
				LIS.push_back(arr[i]);
			} else {
				vector<int>::iterator it = lower_bound(LIS.begin(), LIS.end(), arr[i]);
				*it = arr[i];
			}
		}
	}
}

int main() {

	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	solve();

	printf("%d\n", LIS.size());

	return 0;
}