#include <stdio.h>

int n,m;
int map[200][200];
int coloring[200];

void solve(int node, int color) {
	coloring[node]=color;
	int can = 1;
	
	for(int i=0; i<n; i++)
		if(map[node][i] && coloring[i]==color) can=0;

	if(!can) {
		coloring[node]=0;
		return;
	}
	for(int i=0; i<n; i++) {
		if(!coloring[i] && map[node][i]) {
			solve(i, 1);
			solve(i, 2);
		}
	}
}

bool promising(int i) {
	int j;
	bool check;

	check=true;
	j=1;
	while(j<i && check) {
		if(map[i][j] && coloring[i]==coloring[j])
			check=false;
		j++;
	}
	return check;
}
void m_coloring(int i) {
	int color;
	if(promising(i)) {
		if(i==n)
			return;
		else
			for(color=1; color<=2; color++) {
				coloring[i+1] = color;
				m_coloring(i+1);
			}
	}
}

int main() {
	int a,b;
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
		map[b][a] = 1;
	}

	solve(0, 1);
	//m_coloring(0);

	int ans=1;
	for(int i=0; i<n; i++)
		if(coloring[i]==0) ans=0;
	(ans==0) ? puts("IMPOSSIBLE") : printf("OK");

	return 0;
}