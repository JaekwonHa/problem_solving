#include <stdio.h>
#include <math.h>

int n, end=0;
int number[81];

bool same(int a, int b) {
	for(int i=b; i<b+a; i++) {
		if(number[i] != number[i+a])
			return false;
	}
	return true;
}

bool same2(int a, int b) {
	for(int i=b; i>b-a; i--) {
		if(number[i] != number[i-a])
			return false;
	}
	return true;
}

bool good(int k) {
	for(int i=1; i<=k/2; i++) {
		if(same2(i,k)) return false;
		/*
		for(int j=k; j>=1; j--) {
			if(same(i,j)) return false;
		}
		*/
	}
	return true;
}

void solve(int k) {

	if(end) return;
	if(k==n+1) {
		end=1;
		for(int i=1; i<k; i++)
			printf("%d", number[i]);
		return;
	}
	for(int i=1; i<=3; i++) {
		number[k]=i;
		if(good(k)) solve(k+1);
	}
}

int main() {

	scanf("%d", &n);

	solve(1);

	return 0;
}