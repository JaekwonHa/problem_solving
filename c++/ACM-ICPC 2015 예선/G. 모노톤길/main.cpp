#include <stdio.h>
#include <algorithm>
#include <string.h>

#define MAXN 100010

struct Point { int x,y,o; };
int T, n,m, high[MAXN], low[MAXN],dir[MAXN],maxX;
Point arr[MAXN];

int min(int a, int b) {return (a<b)?a:b;}
int max(int a, int b) {return (a>b)?a:b;}

bool compare(Point a, Point b) {
	if(a.x!=b.x) return a.x<b.x;
	else if(dir[a.x]==1) return a.y>b.y;
	else return a.y<b.y;
}

void solve() {
	maxX=0;
		for(int i=0; i<MAXN; i++) high[i]=-999999, low[i]=999999;
		memset(dir, 0, sizeof(dir));

		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d %d", &arr[i].x, &arr[i].y);
			high[arr[i].x] = max(high[arr[i].x], arr[i].y);
			low[arr[i].x] = min(low[arr[i].x], arr[i].y);
			maxX = max(maxX, arr[i].x);
		}

	if(high[0]==0) dir[0]=1;
		else if(low[0]==0) dir[0]=-1;

		for(int i=1; i<=maxX; i++) {
			if(high[i]==-999999 || high[i]==low[i]) continue;
			int j=i-1;
			while(high[j]==-999999) j--;
			
			if(high[j]==low[i] || low[j]==low[i]) dir[i]=-1;
			else if(high[j]==high[i] || low[j]==high[i]) dir[i]=1;

			/*
			if(high[i]==high[j]) dir[i]=1;
			else if(high[i]==low[j]) dir[i]=-1;
			if(low[i]==low[j]) dir[i]=-1;
			else if(low[i]==high[j]) dir[i]=1;
			*/
		}
		std::sort(arr, arr+n, [](const Point &a, const Point &b) {
			return (a.x!=b.x)? a.x < b.x : a.y < b.y;
		});

		scanf("%d", &m);
		int input;
		for(int i=0; i<m; i++) {
			scanf("%d", &input);
			printf("%d %d\n", arr[input-1].x, arr[input-1].y);
		}
		//for(int i=0; i<m; i++)
		//	printf("%d %d\n", arr[ans[i]-1].x, arr[ans[i]-1].y);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%d %d", &arr[i].x, &arr[i].y);

		std::sort(arr, arr+n, [](const Point &a, const Point &b) {
			return (a.x!=b.x)? a.x < b.x : a.y < b.y;
		});

		int prevX=0,prevY=0;
		for(int i=1; i<n; i++) {
			if(arr[i].x==prevX) {
				int k=i,order=0;;
				while(k<n && arr[k].x==prevX) k++;
				if(prevY > arr[i-1].y) {
					prevY=arr[i-1].y;
					for(int t=i-1; t<k; t++) arr[t].o=order--;
				} else {
					prevY=arr[k-1].y;
					for(int t=i-1; t<k; t++) arr[t].o=order++;
				}
				i=k-1;
			}
			prevX=arr[i].x;
		}
		std::sort(arr, arr+n, [](const Point &a, const Point &b) {
			return (a.x!=b.x)? a.x < b.x : a.o < b.o;
		});

		scanf("%d", &m);
		int input;
		for(int i=0; i<m; i++) {
			scanf("%d", &input);
			printf("%d %d\n", arr[input-1].x, arr[input-1].y);
		}
	}

	return 0;
}