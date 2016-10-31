#include <stdio.h>

int M,N,map[701][701],arr[1400];

int main() {
	scanf("%d %d", &M, &N);
	for(int i=0; i<M; i++)
		for(int j=0; j<M; j++)
			map[i][j]=1;
	for(int i=0; i<N; i++) {
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);
		int j=0;
		for(int k=0; k<a; k++) arr[j++]+=0;
		for(int k=0; k<b; k++) arr[j++]+=1;
		for(int k=0; k<c; k++) arr[j++]+=2;
		/*
		if(a!=0) for(;j<a; j++) arr[j]+=0;
		if(b!=0) for(;j<b; j++) arr[j]+=1;
		if(c!=0) for(;j<c; j++) arr[j]+=2;
		*/
	}
	int i=0;
	for(int j=M-1; j>0; j--) map[j][0]+=arr[i++];
	for(int j=0; j<M; j++) map[0][j]+=arr[i++];
	for(int i=1; i<M; i++) {
		for(int j=1; j<M; j++) {
			map[j][i]=map[j-1][i];
		}
	}
	for(int i=0; i<M; i++) {
		for(int j=0; j<M; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}