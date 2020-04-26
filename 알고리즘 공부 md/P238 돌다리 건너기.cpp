#include <stdio.h>
#include <string.h>

char paper[30];
char bridge[2][120];
int paper_len, bridge_len,ans;

void solve(int paper_x, int bridge_x, int type) {
	
	if(paper_x == paper_len) {
		ans++;
		return;
	}
	for(int i=bridge_x; i<bridge_len; i++) {
		if(bridge[type][i] == paper[paper_x]) {
			solve(paper_x+1, i+1, (type+1)%2 );
		}
	}
}

int DT[2][120][30];
int DT2[2][30];
int f(int dolnum, int dolpos, int rolpos) {
	
	if(DT[dolnum][dolpos][rolpos]==0) {
		if(paper[rolpos]=='\0')
			DT[dolnum][dolpos][rolpos]++;
		for(int i=dolpos; bridge[1-dolnum][i]!='\0'; i++) {
			if(bridge[1-dolnum][i]==paper[rolpos]) {
				DT[dolnum][dolpos][rolpos] += f(1-dolnum,i+1,rolpos+1);
			}
		}
	}
	return DT[dolnum][dolpos][rolpos];
}

int f2(int k) {
	DT2[0][0]=1;
	DT2[1][0]=1;
	for(int i=0; bridge[0][i]!='\0'; i++) {
		for(int t=k-1; t>=0; t--) {
			if(bridge[0][i]==paper[t]) DT2[1][t+1]+=DT2[0][t];
			if(bridge[1][i]==paper[t]) DT2[0][t+1]+=DT2[1][t];
		}
	}
	return DT2[0][k]+DT2[1][k];
}

int main() {

	scanf("%s", paper);
	scanf("%s", bridge[0]);
	scanf("%s", bridge[1]);

	paper_len = strlen(paper);
	bridge_len = strlen(bridge[0]);

	/*
	solve(0,0,0);
	solve(0,0,1);

	printf("%d", ans);
	*/
	//printf("%d", f(0,0,0)+f(1,0,0));
	printf("%d", f2(paper_len));

	return 0;
}
