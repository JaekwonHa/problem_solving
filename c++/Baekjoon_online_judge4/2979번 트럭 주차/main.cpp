#include <iostream>
#include <algorithm>
using namespace std;

int A,B,C;
int arr[101];

int main() {
	scanf("%d %d %d", &A, &B, &C);
	for(int i=0; i<3; i++) {
		int a,b;
		scanf("%d %d", &a, &b);
		for(int j=a; j<b; j++) {
			arr[j]++;
		}
	}
	int sum=0;
	for(int i=0; i<=100; i++) {
		if(arr[i]==1) {
			sum += arr[i]*A;
		} else if(arr[i]==2) {
			sum += arr[i]*B;
		} else if(arr[i]==3) {
			sum += arr[i]*C;
		}
	}
	printf("%d\n", sum);

	return 0;
}