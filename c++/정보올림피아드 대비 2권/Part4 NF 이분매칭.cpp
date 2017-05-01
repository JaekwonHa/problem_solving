#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int rn[100][100], total;
bool check[100];
vector<int> man, woman, path;
map<int,int> place,fn;

bool DFS(int x) {
	int i;
	// 도착점에 도착하면
	if(x==total) {
		// RN과 FN을 갱신한다.
		for(i=0; i<path.size()-1; i++) {
			// 남자그룹의 원소에서 출발하는 간선만 저장한다.
			if(find(man.begin(), man.end(), path[i]) != man.end()) {
				fn[path[i]] = path[i+1];
			}
			rn[path[i]][path[i+1]] -= 1;
			rn[path[i+1]][path[i]] += 1;
		}
		path.clear();
		path.push_back(0);

		return true;
	}
	// 현재 정점에서 갈수있는 다음 정점의 정보를 저장
	// 물론 이미 방문했던 정점은 제외한다.
	for(i=1; i<=total; i++) {
		if(rn[x][i]==1 && check[i]==false) {
			check[i]=true;
			//경로에 추가
			path.push_back(i);

			// 하나의 경로가 처리되면 다음은 방문하지 않고 true
			// 리턴하며 종료
			if(DFS(i)==true) return true;

			// 체크와 경로에 대해서 복원
			path.pop_back();
			check[i]=false;
		}
	}
	return false;
}

void BipariteMatching() {
	path.push_back(0);
	while(DFS(0)) {
		fill(check, check+total+1, false);
		check[0]=true;
	}
}

int main() {

	int n,a,b,i;
	cin>>n;
	man.reserve(n);
	while(n--) {
		cin>>a;
		// 남자그룹에 속하는 번호는 0으로 저장한다.
		place[a]=0;
		// 남자 그룹 번호로 저장
		man.push_back(a);
	}
	cin>>n;
	woman.reserve(n);
	while(n--) {
		cin>>a;
		// 여자그룹에 속하는 번호는 1로 저장한다.
		place[a]=1;
		// 여자 그룹 본호로 저장
		woman.push_back(a);
	}
	cin>>n;
	while(n--) {
		cin>>a>>b;
		// a가 남자 그룹인 경우
		if(place[a]==0) rn[a][b]=1;
		// b가 남자 그룹인 경우
		else rn[b][a]=1;
	}

	// 시작 번호 0에서 모든 남자 그룹 번호로 연결 시킨다.
	for(i=0; i<man.size(); i++) rn[0][man[i]] = 1;

	// 여자 그룹의 모든 번호에서 도착점으로 모두 연결 시킨다.
	// 도착점은 두 그룹의 총합 +1 이다.
	total = man.size() + woman.size() + 1;
	for(i=0; i<woman.size(); i++) rn[woman[i]][total]=1;

	BipariteMatching();

	sort(man.begin(), man.end());

	for(i=0; i<man.size(); i++) {
		// fn은 남자그룹에서 유일하게 하나의 값과 연결되므로
		// 연결된 선이 있는 경우 출력
		if(fn.find(man[i]) != fn.end()) {
			cout<<man[i]<<" : "<<fn[man[i]]<<endl;
		}
	}

	return 0;
}