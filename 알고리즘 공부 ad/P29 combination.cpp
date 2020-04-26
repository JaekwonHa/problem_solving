#include <stdio.h>
#include <time.h>

int n,k;
int DT[31][31];

int f(int a, int b) {
	if(b==1) return a;
	if(a==b) return 1;
	return f(a-1,b) + f(a-1, b-1);
}
int f2(int a, int b) {
	if(b==1) return a;
	if(a==b) return 1;
	if(!DT[a-1][b]) DT[a-1][b] = f2(a-1,b);
	if(!DT[a-1][b-1]) DT[a-1][b-1] = f2(a-1,b-1);
	return DT[a-1][b] + DT[a-1][b-1];
}

int f3(int a, int b) {
	if(b==1) return a;
	if(a==b) return 1;
	return f3(a-1,b-1) * a/b;
}

int main() {

	scanf("%d %d", &n, &k);

	double start = clock();
	printf("%d", f3(n,k));
	printf("\nresult=%.3lf(sec)\n",(double)(clock()-start)/CLOCKS_PER_SEC);


	return 0;
}