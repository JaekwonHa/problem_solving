#include <iostream>
#include <string.h>
#include <algorithm>
#include <iomanip>
using namespace std;

#define INF 987654321

int T,H,C;
int arr[210];
double DP[210][210];

double f(int h, int c) {
	double &ret = DP[h][c];
	if(ret != -1) return ret;

	if(c==C-1) {
		ret=0;
		for(int i=h+1; i<H-1; i++) {
			ret += abs(( arr[h]+(arr[H-1]-arr[h])*(i-h)/(H-1-h) )-arr[i]);
		}
	} else {
		ret=INF;
		double error;
		for(int i=h+1; i<=H-C+c; i++) {
			error=0;
			for(int j=h+1; j<i; j++) {
				error += abs(( arr[h]+(arr[i]-arr[h])*(j-h)/(i-h) )-arr[j]);
			}
			ret = min(ret,f(i,c+1)+error);
		}
	}
	return ret;
}

int main() {

	cin>>T;
	while(T--) {
		memset(DP,-1,sizeof(DP));
		cin>>H>>C;
		for(int i=0; i<H; i++) cin>>arr[i];

		printf("%.4f\n",f(0,1)/H);
		//cout<<((double)f(0,H-1,C-2)/H)<<endl;
	}


	return 0;
}