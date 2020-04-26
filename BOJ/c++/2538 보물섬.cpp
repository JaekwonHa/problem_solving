#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

typedef struct {
	int x,y,cost;
}Robot;

int L,W,ans;
char map[55][55];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void solve(int x, int y) {
	int dis[55][55],m=0;
	memset(dis,-1,sizeof(dis));
	dis[x][y]=0;

	queue<Robot> q;
	Robot r;
	r.x=x, r.y=y, r.cost=0;
	q.push(r);

	while(!q.empty()) {
		r = q.front();
		q.pop();

		int nextX, nextY, nextC;
		for(int i=0; i<4; i++) {
			Robot t;
			nextX = r.x+dx[i];
			nextY = r.y+dy[i];
			nextC = r.cost+1;
			if(dis[nextX][nextY]==-1 && map[nextX][nextY]=='L') {
				m=max(m,nextC);
				dis[nextX][nextY]=nextC;
				t.x=nextX, t.y=nextY, t.cost=nextC;
				q.push(t);
			}
		}
	}
	ans = max(ans,m);
}

bool check(int x, int y) {
    int cnt = 0;
    if (map[x - 1][y] == 'W')
        cnt++;
    if (map[x + 1][y] == 'W')
        cnt++;
    if (map[x][y + 1] == 'W')
        cnt++;
    if (map[x][y - 1] == 'W')
        cnt++;
 
    if (cnt == 3)
        return true;
    else return false;
}

int main() {

	scanf("%d %d", &L, &W);
	for (int i = 0; i <= L + 1; i++){
        for (int j = 0; j <= W + 1; j++){
            map[i][j] = 'W';
        }
    }
	/*
	for(int i=0; i<L; i++)
		scanf("%s", &map[i]);
		*/
	for (int i = 0; i < L; i++){
        char a;
        for (int j = 0; j < W; j++){
            cin >> a;
            map[i][j]=a;
        }
    }
	for(int i=0; i<L; i++) {
		for(int j=0; j<W; j++) {
			if(map[i][j]=='L' && check(i,j)) {
				solve(i,j);
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}