#include <iostream>
#include <string.h>

using namespace std;

int node[1500][1500];
int checked[1500];
int max_flow;
int np,nk;

int sink_to_source(int a, int min_flow) {
	
	if(a==1+np+nk) return 1;

	checked[a]++;
	for(int i=0; i<1+np+nk+1; i++) {
		if(checked[i]==0 && node[a][i]>0) {
			if(sink_to_source(i,1)) {
				node[a][i]--;
				node[i][a]++;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	
	int i,j,npi,cate,solution;

	while(1) {
		cin>>nk>>np;
		if(nk==0 && np==0) break;

		memset(checked,0,sizeof(checked));
		memset(node,0,1500*1500*sizeof(int));
		solution=0, max_flow=0;

		if(nk!=0) {
			for(i=0; i<nk; i++) {
				cin>>node[1+np+i][1+np+nk];
				solution+=node[1+np+i][1+np+nk];
			}
		}
		if(np!=0) {
			for(i=0; i<np; i++) {
				cin>>npi;
				for(j=0; j<npi; j++) {
					cin>>cate;
					node[1+i][1+np+cate-1]=1;
				}
				node[0][i+1]=1;
			}
		}
		
		while(sink_to_source(0,99999)) {
			max_flow++;
			memset(checked,0,sizeof(checked));
		}

		if(max_flow == solution) {
			cout<<"1"<<endl;
			for(i=1+np; i<1+np+nk; i++) {
				for(j=1; j<=np; j++) if(node[i][j]>0) cout<<j<<" ";
				cout<<endl;
			}
		} else cout<<"0"<<endl;
	}
	return 0;
}