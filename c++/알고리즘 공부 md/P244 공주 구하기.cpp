#include <stdio.h>

int n, pos[20], pow[20], type[20], use[20], ans;

void back(int x, int dis) {
	if(x==0) {
		ans++;
		return;
	} else if(x<0)
		return;

	for(int i=x; i>=x-dis; i--) {
		for(int j=n-1; j>=0; j--) {
			if(i == pos[j] && use[j]==0 && type[j]==1) {
				use[j]=1;
				back(pos[j], pow[j]);
				use[j]=0;
			}
		}
	}
}

void go(int x, int dis) {

	if(x==pos[n-1]) {
		back(x, pos[n-1]);
		return;
	} else if(x>pos[n-1])
		return;

	for(int i=x+1; i<=x+dis; i++) {
		for(int j=1; j<n; j++) {
			if(i == pos[j] && use[j]==0) {
				use[j]=1;
				go(pos[j], pow[j]);
				use[j]=0;
			}
		}
	}
}

int main() {

	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d %d %d", &pos[i], &pow[i], &type[i]);
	}

	go(0, pow[0]);

	printf("%d", ans%1000);

	return 0;
}