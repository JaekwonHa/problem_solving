#include <stdio.h>
#include <algorithm>
#include <map>

bool a[26][26],ap[26];
int check[26],n,cnt,order,child;
std::map<char,int> v;
std::map<int, char> c;

int getVertex(char ch) {
	if(v.find(ch)==v.end()) {
		v[ch]=cnt;
		c[cnt]=ch;
		cnt++;
	}
	return v[ch];
}

int Ap(int s) {

	int mn, i, x;
	check[s] = ++order;
	mn = order;

	for(i=0; i<n; i++) {
		if(a[s][i]) {
			if(check[i]==0) {
				if(s==0) ++child;

				x = Ap(i);

				if(x<mn) mn = x;
				if(check[s]<=x && s!=0 && !ap[s]) ap[s]=true;
			} else if(check[i]<mn) mn = check[i];
		}
	}
	return mn;
}

int main() {

	int m,i,ix,iy;
	char x,y;

	scanf("%d %d", &n, &m);
	std::fill(ap,ap+n,false);
	std::fill(check, check+n,0);
	for(i=0; i<n; i++) std::fill(a[i],a[i]+n,false);

	for(i=0; i<m; i++) {
		scanf("%s %s", &x, &y);
		ix = getVertex(x);
		iy = getVertex(y);
		a[ix][iy]=a[iy][ix]=true;
	}

	Ap(0);
	if(child>1) ap[0]=true;

	for(i=0; i<n; i++) {
		if(ap[i]) {
			printf("%c\n", c[i]);
		}
	}
	


	return 0;
}