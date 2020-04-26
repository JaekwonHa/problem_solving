#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int W,H,map[52][52];

class myQueue{
public:
	myQueue(int n) {
		qSize = n+1;
		data = new int[qSize];
		clear();
	}
	~myQueue() {
		delete[] data;
	}
	void clear() {
		dSize = front = rear = 0;
	}
	void push(int val) {
		if((rear+1)%qSize == front) return;	// full
		dSize++;
		rear = (rear+1)%qSize;
		data[rear] = val;
	}
	int pop() {
		if(front==rear) return 0;			// empty
		dSize--;
		front = (front+1)%qSize;
		return data[front];
	}
	int size() {
		return dSize;
	}
	bool empty() {
		return dSize==0;
	}
private:
	int qSize,dSize;
	int front,rear;
	int *data;
};

myQueue cq(5000);

int BFS(int x, int y) {
	cq.clear();
	cq.push(x*100+y);
	int result =0,i,j,qsize;
	int current;
	while(!cq.empty()) {
		result++;
		qsize = cq.size();
		for(int k=0; k<qsize; k++) {
			current = cq.pop();
			i = current/100;
			j = current%100;
			if(map[i][j]) continue;
			//if(i==0 || j==0) continue;
			map[i][j]=1;
			if(!map[i-1][j]) cq.push((i-1)*100+j);
			if(!map[i+1][j]) cq.push((i+1)*100+j);
			if(!map[i][j-1]) cq.push(i*100+j-1);
			if(!map[i][j+1]) cq.push(i*100+j+1);
		}
	}
	return result-1;
}

void clear() {
	for(int i=1; i<=H; i++)
		for(int j=1; j<=W; j++)
			if(map[i][j]==1) map[i][j]=0;
}

int main() {
	scanf("%d %d", &H, &W);
	for(int i=0; i<H; i++) {
		getchar();
		for(int j=0; j<W; j++) {
			if(getchar() == 'W') map[i+1][j+1]=2;
			else map[i+1][j+1]=0;
		}
	}
	for(int i=0; i<=H+1; i++)
		map[i][0] = map[i][W+1] = 2;
	for(int i=0; i<=W+1; i++)
		map[0][i] = map[H+1][i] = 2;

	int result=0;
	for(int i=1; i<=H; i++) {
		for(int j=1; j<=W; j++) {
			if(map[i][j]) continue;
			// ÀÎÁ¢ÇÑ ºó Ä­ÀÇ ¼ö¸¦ ¼¼¾îº½

			int adj = !map[i-1][j] + !map[i+1][j] + !map[i][j-1] + !map[i][j+1];
			if(adj<=1 && adj>0) {
				result = max(result,BFS(i,j));
				clear();
			}
			//if(adj > 2) continue;
			//if(adj == 0) continue;

			
		}
	}
	printf("%d\n",result);

	return 0;
}