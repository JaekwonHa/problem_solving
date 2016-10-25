#include <iostream>
#include <algorithm>
using namespace std;

int N,K;
int arr[21];

int main() {

	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++) {
		char t;
		if(i!=0) scanf("%c", &t);
		scanf("%d", &arr[i]);
	}

	while(K--) {
		for(int i=0; i<N-1; i++) {
			arr[i]=arr[i+1]-arr[i];
		}
		N--;
	}
	for(int i=0; i<N; i++) {
		if(i!=0) printf(",");
		printf("%d", arr[i]);
	}
	

	return 0;
}