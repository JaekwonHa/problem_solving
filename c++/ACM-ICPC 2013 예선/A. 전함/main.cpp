#include <stdio.h>
#include <string.h>
#include <vector>

struct Ship {
	int x1,y1,x2,y2,w;
};
int T, n,k,l;
Ship ship[100000];
int chk[100000];
std::vector<Ship> list;

int max(int a, int b) {return (a>b)?a:b;}
int min(int a, int b) {return (a<b)?a:b;}

int f(int a, int b) {
	int maxW=0;

	if(b==0) {
		for(int i=0; i<k; i++) {
			if(chk[i]==0) {
				int y1 = min(ship[i].y1,ship[i].y2);
				int y2 = max(ship[i].y1,ship[i].y2);
				if(y1<=a && a<=y2) {
					maxW=max(maxW,ship[i].w);
					chk[i]=1;
				}
			}
		}
	} else {
		for(int i=0; i<k; i++) {
			if(chk[i]==0) {
				int x1 = min(ship[i].x1,ship[i].x2);
				int x2 = max(ship[i].x1,ship[i].x2);
				if(x1<=a && a<=x2) {
					maxW=max(maxW,ship[i].w);
					chk[i]=1;
				}
			}
		}
	}

	return maxW;
}

int f2(int a, int b) {
	int maxW=0;

	if(b==0) {
		std::vector<Ship>::iterator it = list.begin();
		for(; it<list.end(); it++) {
			Ship temp = *it;
			int y1 = min(temp.y1,temp.y2);
			int y2 = max(temp.y1,temp.y2);
			if(y1<=a && a<=y2) {
				maxW=max(maxW,temp.w);
				list.erase(it);
				it--;
			}
		}
	} else {
		for(int i=0; i<list.size(); i++) {
			int x1 = min(ship[i].x1,ship[i].x2);
			int x2 = max(ship[i].x1,ship[i].x2);
			if(x1<=a && a<=x2) {
				maxW=max(maxW,ship[i].w);
				list.erase(i);
			}
		}
	}

	return maxW;
}

int main() {
	//std::ios::sync_with_stdio(false);
	scanf("%d", &T);
	while(T--) {
		memset(chk,0,sizeof(chk));
		scanf("%d %d %d", &n, &k, &l);
		for(int i=0; i<k; i++) {
			scanf("%d %d %d %d %d", &ship[i].x1, &ship[i].y1, &ship[i].x2, &ship[i].y2, &ship[i].w);
			list.push_back(ship[i]);
		}
		int a,b;
		for(int i=0; i<l; i++) {
			scanf("%d %d", &a, &b);
			printf("%d\n", f2(a,b));
		}
	}


	return 0;
}
