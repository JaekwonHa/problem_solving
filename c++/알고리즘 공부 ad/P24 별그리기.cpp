#include <cstdio>
#include <time.h>
#define MAXN 10000
char star[MAXN+1];

void f(int n)
{
	if(n>0)
	{
		f(n-1);
		star[n]='*';
		puts(star+1);
	}
}
int main()
{
	int n;
	scanf("%d", &n);

	double start = clock();
	f(n);
	printf("result=%.3lf(sec)\n",(double)(clock()-start)/CLOCKS_PER_SEC);

	return 0;
}



/*
#include <stdio.h>
#include <time.h>

int n;
char star[10001];

void f(int cnt) {
	if(cnt==n)
		return;
	star[cnt]='*';
	//printf("%s\n", star);
	puts(star);
	f(cnt+1);
}

int main() {

	scanf("%d", &n);

	double start = clock();
	f(0);

	printf("result=%.3lf(sec)\n",(double)(clock()-start)/CLOCKS_PER_SEC);

	return 0;
}

*/