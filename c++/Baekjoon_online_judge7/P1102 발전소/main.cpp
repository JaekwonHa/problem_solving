#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int arr[20][20];
int p;
int DP[1000000];
int answer = 987654321;

int f(int bit, int cnt) {
	if(cnt>=p) {
		//answer = min(answer,cost);
		return 0;
	}

	int& ret = DP[bit];
	if(ret != -1) return ret;

	ret=987654321;
	for(int i=1; i<=N; i++) {
		if(((1<<i) & bit) == 0) {
			for(int j=1; j<=N; j++) {
				if(((1<<j) & bit) != 0) {
					ret = min(ret, f(bit|(1<<i),cnt+1) +arr[j][i]); 
				}
			}
		}
	}
	return ret;
}

int main() {

	char input[20];
	int cnt=0;
	int bit=0,i,j;
	memset(DP,-1,sizeof(DP));

	cin>>N;
	for(i=1; i<=N; i++)
		for(j=1; j<=N; j++)
			cin>>arr[i][j];
	
	cin>>input;
	for(i=1; i<=strlen(input); i++) {
		if(input[i-1]=='Y') {
			bit = bit | (1<<i);
			cnt++;
		}
	}
	cin>>p;

	cout<<f(bit,cnt);
	//f(bit,cnt,0);
	//cout<<answer;

	return 0;
}