#include <iostream>
#include <vector>
#include <list>
#include <string.h>

using namespace std;

#define MAX 900001



int main() {
	int i,j,min;
	int matrix[101][101],N,M;
	int value[101];
	bool checked[101];
	int index[101];

	memset(checked, 0, 101*sizeof(int));
	memset(matrix, 0, 101*101*sizeof(int));
	memset(index, 0, 101*sizeof(int));
	memset(value, 0, 101*sizeof(int));

	

	cin>>N>>M;

	for(i=1; i<=N; i++) 
		for(j=1; j<=N; j++) 
			cin>>matrix[i][j];

	for(i=1; i<=N; i++) value[i]=MAX;
	index[1]=0;
	value[1]=0;
	for(int k=1; k<=N; k++) {
		min=MAX;
		for(i=1; i<=N; i++) {
			if(value[i]<min && !checked[i]) {
				j=i;
				min=value[i];
			}
		}
		checked[j]=true;
		for(i=1; i<=N; i++) {
			if(value[j]+matrix[j][i] < value[i]) {
				index[i] = j;
				value[i]=value[j]+matrix[j][i];
			}
		}
	}
	list<int> result;
	int r=M;
	while(r!=0) {
		result.push_front(r);
		r=index[r];
	}
	cout<<value[M]<<endl;
	list<int>::iterator it;
	for(it=result.begin(); it!=result.end(); it++) {
		cout<<*it;
		if(it!=result.end()) cout<<" ";
	}
	cout<<endl;
	

	return 0;
}