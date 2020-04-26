#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct vertex {
	int weight,idx;
};

int rn[500][500];
int maxFlow,n;
bool check[500];
vector<int> path;

int N,K,a[210],f[210],p[210],s[110],e[110];

int vertex_sort(const vertex& a, const vertex& b) {
	return a.weight>b.weight;
}

bool PFS(int x, int localFlow) {
	int i;
	vector<vertex> v;
	vertex vx;

	if(x==1) {
		// DFS로 끝에 도착하면 왔던 경로들에서 flow를 업데이트 해줘야 한다.
		// MaxFlow에 현재 경로의 최소 flow를 더해준다.
		maxFlow += localFlow;
		// RN을 갱신한다.
		for(i=0; i<path.size()-1; i++) {
			rn[path[i]][path[i+1]] -= localFlow;
			rn[path[i+1]][path[i]] += localFlow;
		}
		path.clear();
		path.push_back(0);
		return true;
	}
	// 현재 정점에서 갈수있는 다음 정점의 정보를 저장
	for(i=0; i<n; i++) {
		if(rn[x][i] > 0 && check[i]==false) {
			vx.idx = i;
			vx.weight = rn[x][i];
			v.push_back(vx);
		}
	}
	// priority를 위해 weight에 따라 정렬
	sort(v.begin(), v.end(), vertex_sort);

	for(i=0; i<v.size(); i++) {
		// 다음 정점으로 선택된 것은 방문하지 않도록 체크
		check[v[i].idx] = true;
		// 경로에 그 정점을 추가
		path.push_back(v[i].idx);
		// 용량이 큰 것부터 차례대로 방문된다.
		// 하나의 경로가 처리되면 다음은 방문하지 않고 true 리턴하며 종료
		// 이전까지의 간선 용량중 최소로 갱신해간다.
		if(PFS(v[i].idx, min(localFlow, v[i].weight)) == true)
			return true;
		   
		// 체크와 경로에 대해서 복원
		path.pop_back();
		check[v[i].idx] = false;
	}
	return false;
}

void MaxFlow() {
	path.push_back(0);
	while(PFS(0,987654321)) {
		// 하나의 경로가 처리되면 check를 모두 초기화하고 다시 탐색. 경로가 없을때까지 반복
		fill(check,check+n,false);
		check[0]=true;
	}
}

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	   C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	   따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
    
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for(test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        
		int timeTable[200],maxTime=0;
		memset(timeTable,0,sizeof(timeTable));
		bool check=true;

		scanf("%d %d", &N, &K);
		for(int i=0; i<N; i++) {
			scanf("%d %d %d",&a[i],&f[i],&p[i]);
			for(int j=a[i]; j<f[i]; j++) {
				timeTable[j]--;
			}
			if(f[i]-a[i] != p[i]) {
				check=false;
			}
		}
		for(int i=0; i<K; i++) {
			scanf("%d %d",&s[i],&e[i]);
			for(int j=s[i]; j<e[i]; j++) {
				timeTable[j]++;
			}
			maxTime = max(maxTime,e[i]);
		}
		bool answerCHK=true;
		for(int i=0; i<maxTime; i++) {
			if(timeTable[i] <0) answerCHK=false;
		}
		printf("Case #%d\n", test_case);
		if(check==true) {
			if(answerCHK==true) {
				printf("1\n");
			} else {
				printf("0\n");
			}
		} else {
			memset(rn,0,sizeof(rn));
			n=0,maxFlow=0;
			int answer=0;

			for(int i=0; i<N; i++) {
				rn[0][i+2]=p[i];
				for(int j=a[i]; j<f[i]; j++) {
					rn[i+2][N+j+2]=1;
				}
				answer+=p[i];
			}
			for(int i=0; i<K; i++) {
				for(int j=s[i]; j<e[i]; j++) {
					rn[N+j+2][1]++;
				}
				n=max(n,e[i]);
			}
			n = 2+N+n+1;
			MaxFlow();
			bool chk=true;
			for(int i=0; i<N; i++) {
				if(rn[0][i+2]!=0) chk=false;
			}
			// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
			if(chk==true) {
				printf("1\n");
			} else {
				printf("0\n");
			}
		}
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}