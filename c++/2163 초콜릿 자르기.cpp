#include <iostream>
#include <algorithm>
using namespace std;

int N,M;

int main() {

	scanf("%d %d", &N, &M);
	
	int ans = (N-1) + (N)*(M-1);
	printf("%d\n", ans);


	return 0;
}