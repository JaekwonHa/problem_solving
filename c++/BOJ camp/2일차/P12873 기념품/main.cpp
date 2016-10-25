#include <iostream>
#include <algorithm>
using namespace std;

int N, T;
int arr[5010];

void out(int n) {
	for (int i = n; i < N-1; i++) {
		arr[i] = arr[i + 1];
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		arr[i] = i+1;
	}
	int pos = 0;
	T = 1;
	while (N!=1) {
		long long t = (((long long)T*T*T)-1) % N;
		pos = (pos + t) % N;
		out(pos);
		N--;
		T++;
	}
	cout << arr[0];

	return 0;
}