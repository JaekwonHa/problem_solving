#include <stdio.h>
#include <string.h>
int main() {

	int arr[1000];
	memset(arr,0,sizeof(arr));
	int answer[1000];
	memset(answer,0,sizeof(answer));

	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&arr[i]);

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(i==j) continue;
			if(arr[i]>arr[j]) answer[i]++;
		}
	}
	printf("%d", answer[0]);
	for(int i=1; i<N; i++) {
		printf(" %d", answer[i]);
	}
	printf("\n");

	return 0;
}