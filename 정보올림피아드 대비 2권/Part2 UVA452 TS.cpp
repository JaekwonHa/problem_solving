#include <iostream>
#include <map>
#include <algorithm>
#include <string.h>
#include <sstream>
using namespace std;

#define MAXN 30

int n,w[MAXN],b[MAXN],sum[MAXN],mx;
bool e[MAXN][MAXN];
map<char,int> alpha;

int getVertex(char v) {
	if(alpha.find(v)==alpha.end()) alpha[v]=n++;
	return alpha[v];
}

void TS() {
	int i,j,k=n;
	while(k--) {
		for(i=0; i<n; i++) if(b[i]==0) break;
		b[i]--;
		sum[i]=max(w[i],sum[i]);
		mx = max(mx,sum[i]);

		for(j=0; j<n; j++) {
			if(e[i][j]) {
				b[j]--;
				// 이전에 구해진 시간 합 sum[j]
				// 이전 작업 최대시간 sum[i] + 현재 작업시간 w[j] 를 더한 시간 중 더 큰 값을 저장한다.
				sum[j] = max(sum[j],sum[i]+w[j]);
			}
		}
	}
}


int main() {
	int T;
	char tp1,tp2,time;
	string str;
	cin>>T;
	cin.get();
	getline(cin,str);
	while(T--) {
		
		n=0,mx=0;
		memset(b,0,sizeof(b));
		memset(sum,0,sizeof(sum));
		memset(e,0,sizeof(e));
		alpha.clear();
		
		while(1) {
			int x,y;
			getline(cin,str);
			if(str=="") break;
			istringstream is(str);
			is>>tp1;
			x = getVertex(tp1);
			is>>w[x];
			while(is>>tp2) {
				y = getVertex(tp2);
				e[y][x]=true,b[x]++;
			}
		}
		TS();
		cout<<mx<<endl;
		if(T) cout<<endl;
	}

	return 0;
}