#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N,M;
	cin>>N>>M;
	int map[12][12];
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for(int i=1; i<=N; i++) {
		for(int j=M; j>0; j--) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}