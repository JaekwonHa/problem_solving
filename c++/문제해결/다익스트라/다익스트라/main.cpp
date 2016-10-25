#include <iostream>

using namespace std;

#define N 8
#define M 9999

int a[N+1][N+1] = {{0,0,0,0,0,0,0,0,0},
	{0,0,1,2,M,7,M,M,M},
	{0,1,0,M,2,M,M,4,M},
	{0,2,M,0,M,M,5,M,M},
	{0,M,2,M,0,M,M,1,M},
	{0,7,M,M,M,0,3,2,M},
	{0,M,M,5,M,3,0,M,2},
	{0,M,4,M,1,2,M,0,6},
	{0,M,M,M,M,M,2,6,0},};

int value[N+1];
int f[N+1];
int index[N+1];

int main() {

	int min,p;

	for(int n=1; n<=N; n++)
		value[n]=M;

	value[1]=0;
	for(int i=1; i<=N; i++) {
		min=M;
		for(int i=1; i<=N; i++) {
			if((value[i]<min)&&f[i]==0) {
				min=value[i];
				p=i;
			}
		}
		f[p]=1;
		for(int j=1; j<=N; j++) {
			if(value[p]+a[p][j]<value[j]) {
				value[j]=value[p]+a[p][j];
				index[j]=p;
			}
		}
	}
	for(int i=1; i<=N; i++) {
		cout<<value[i]<<" :1->"<<i<<" ";
		p=i;
		do{
			cout<<"<-"<<index[p];
			p=index[p];
		}while(index[p]);
		puts("");
	}

	



	return 0;
}