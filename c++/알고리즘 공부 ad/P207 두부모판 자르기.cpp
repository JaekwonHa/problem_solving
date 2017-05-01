#include <stdio.h>
/*
#define cu (1<<n)
#define rt (1<<(n-1))
#define dn (1)
#define M (1<<(n+1))
*/
#define cu (1)
#define rt (1<<1)
#define dn (1<<n)
#define M (1<<(n+1))

int chk[20][20],P[26][26]={{100,70,40},{70,50,30},{40,30,20}}, n;
char A[20][20];

int p[4][4]={100,70,40,0,70,50,30,0,40,30,20,0,0,0,0,0};
int tb[12][12], m[12][12][1<<13];

int max(int a, int b) { return a>b?a:b;}

int f(int a, int b) {
	int ans =0;
	if(a==n) return 0;
	if(b==n) return f(a+1,0);
	if(chk[a][b]==0) {
		chk[a][b]=1;
		if(b+1<n && chk[a][b+1]==0) {
			chk[a][b+1]=1;
			ans=max(ans, f(a,b+2)+P[A[a][b]-'A'][A[a][b+1]-'A']);
			chk[a][b+1]=0;
		}
		if(a+1<n && chk[a+1][b]==0) {
			chk[a+1][b]=1;
			ans=max(ans, f(a,b+1)+P[A[a][b]-'A'][A[a+1][b]-'A']);
			chk[a+1][b]=0;
		}
		ans = max(ans, f(a,b+1));
		chk[a][b]=0;
	} else {
		ans = max(ans, f(a,b+1));
	}
	return ans;
}

int f2(int x, int y, int s) {
	if(x==n) return 0;
	if(y==n) return f2(x+1,0,s);
	if(!m[x][y][s]) {
		if(!(s&cu)) {
			if(y+1<n && !(s&rt)) {
				//m[x][y][s]=max(m[x][y][s], f2(x,y+2, (s<<2)%M)+p[tb[x][y]][tb[x][y+1]]);
				m[x][y][s]=max(m[x][y][s], f2(x,y+2, (s>>2)%M)+p[tb[x][y]][tb[x][y+1]]);
			}
			if(x+1<n && !(s&dn)) {
				//m[x][y][s]=max(m[x][y][s], f2(x,y+1, ((s|dn)<<1)%M)+p[tb[x][y]][tb[x+1][y]]);
				m[x][y][s]=max(m[x][y][s], f2(x,y+1, ((s|dn)>>1)%M)+p[tb[x][y]][tb[x+1][y]]);
			}
			//m[x][y][s]=max(m[x][y][s], f2(x,y+1, (s<<1)%M));
			m[x][y][s]=max(m[x][y][s], f2(x,y+1, (s>>1)%M));
		} else {
			//m[x][y][s]=max(m[x][y][s], f2(x,y+1, (s<<1)%M));
			m[x][y][s]=max(m[x][y][s], f2(x,y+1, (s>>1)%M));
		}
	}
	return m[x][y][s];
}

int main() {
	/*
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%s", &A[i]);
	printf("%d\n", f(0,0));
	*/
	
	int i,j; char t;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) {
			scanf(" %1c", &t);
			tb[i][j]=(t=='F' ? 3:t-'A');
		}
	printf("%d\n", f2(0,0,0));
	
	return 0;
}