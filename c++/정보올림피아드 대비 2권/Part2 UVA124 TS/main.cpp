#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAXN 21

int n,sum[MAXN];
string str;
map<char,int> alpha;
char name[MAXN], o[MAXN];
bool e[MAXN][MAXN];

void DFS_TS(int l) {
	int i,j;
	if(l==n) cout<<o<<endl;
	else {
		for(i=0; i<n; i++) {
			if(sum[i]==0) {
				o[l]=name[i];
				sum[i]--;

				for(j=0; j<n; j++) {
					if(e[i][j]) sum[j]--;
				}

				l++;
				DFS_TS(l);

				l--;
				for(j=0; j<n; j++) {
					if(e[i][j]) sum[j]++;
				}
				sum[i]++;
			}
		}
	}
}

int main() {
	bool first=true;
	char a,b;
	while(1) {
		n=0;
		memset(sum,0,sizeof(sum));
		memset(e,0,sizeof(e));
		alpha.clear();
		getline(cin,str);
		if(str=="") break;
		if(!first) cout<<endl;
		first=false;

		
		istringstream is1(str);
		while(is1>>a) name[n++]=a;
		sort(name, name+n);

		for(int i=0; i<n; i++) {
			alpha[name[i]]=i;
		}
		getline(cin, str);
		istringstream is2(str);
		while(is2>>a>>b) e[alpha[a]][alpha[b]]=true;

		o[n]=0;
		//int l=0;
		for(int i=0; i<n; i++) {
			sum[i]=0;
			for(int j=0; j<n; j++) {
				if(e[j][i]) sum[i]++;
			}
		}
		DFS_TS(0);
	}

	return 0;
}