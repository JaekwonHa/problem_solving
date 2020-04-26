#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int T,N,G, P[110];
char S[110][110],sample[110][110];

int main() {

	int i,j,k;
	cin>>T;
	while(T--) {
		cin>>N>>G;
		for(i=0; i<N; i++) cin>>sample[i];
		for(i=0; i<G; i++) cin>>P[i]>>S[i];

		int cnt=0,answer=-1;
		for(i=0; i<N; i++) {
			bool check=true;

			for(j=0; j<G; j++) {
				bool check2=false;
				for(k=0; k<strlen(S[j]); k++) {
					if(strlen(sample[i]) > P[j]-1 && sample[i][P[j]-1] == S[j][k]) {
						check2 = true;
						break;
					}
				}
				if(!check2) check=false;
			}
			if(check) {
				cnt++;
				answer=i;
			}
		}
		if(cnt==1) {
			cout<<sample[answer]<<endl;
		} else if(cnt==0) {
			cout<<"DEAD DRUNK"<<endl;
		} else {
			cout<<"YOU KNOW NOTHING"<<endl;
		}
	}

	return 0;
}