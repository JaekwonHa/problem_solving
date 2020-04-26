#include <stdio.h>
#include <math.h>

int T,ans,arr[32];
int temp,len;

int check() {
	for(int i=len-1; i>=0; i--) {
		if(arr[i]==1)
			return i;
	}
	return -1;
}

void solve() {

	len = check();
	if(len==-1) return;
	if(len==0) {
		ans=1;
		return;
	} else if(len==1) {
		ans=3+arr[0];
		return;
	}
	int i=0;
	while(i!=len-1) {
		if(arr[i]==1) {
			ans+=pow((double)2,i+1)-1;
			arr[i]=0;
		}
		i++;
	}
	if(arr[i]==0) {
		ans+=pow((double)2,i+1)-1;
	}
	ans+=pow((double)2,len)-1;
}

int main() {

	scanf("%d", &T);
	while(T--) {
		temp,len=0,ans=0;
		scanf("%d", &temp);
		while(temp!=0) {
			arr[len++]=temp%10;
			temp /=10;
		}
		solve();
		printf("%d\n", ans);
	}

	return 0;
}