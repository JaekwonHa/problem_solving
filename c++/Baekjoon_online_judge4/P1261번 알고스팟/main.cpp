#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Robot {
	int x;
	int y;
	int cost;
};

int M,N;
int map[110][110];
int cost[110][110];
bool visited[110][110];
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
queue<Robot> q;

int main() {
	scanf("%d %d", &M, &N);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%1d", &map[i][j]);

	if(N==1 & M==1) cost[N][M]=0;
	else cost[N][M] = 999;
	Robot robot;
	robot.x=1, robot.y=1, robot.cost=0;
	q.push(robot);
	while(!q.empty()) {
		robot=q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			int next_x = robot.x+dx[i];
			int next_y = robot.y+dy[i];
			if(next_x>0 && next_x<=N && next_y>0 && next_y<=M) {
				if(next_x==N && next_y==M) {
					cost[next_x][next_y] = min(cost[next_x][next_y], robot.cost);
					continue;
				}
				if(visited[next_x][next_y]==true && cost[next_x][next_y] <= robot.cost+map[next_x][next_y]) continue;
				visited[next_x][next_y]=true;
				cost[next_x][next_y] = robot.cost+map[next_x][next_y];
				Robot temp;
				temp.x = next_x, temp.y = next_y, temp.cost = cost[next_x][next_y];
				q.push(temp);
			}
		}
	}

	printf("%d\n", cost[N][M]);

	return 0;
}