#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
using namespace std;

// 윗 그룹을 어플리케이션, 아랫그룹을 컴퓨터로 잡았을때
// 애플리케이션에서 컴으로 연결되는 정보는 rnu(up)
// 컴에서 어플리케이션으로 연결되는 정보는 rnb(bottom)
bool rnu[27][10], rnb[10][27], checku[27], checkb[10];
int total, ap[10], no[27];
vector<int> path;

bool DFS(int x, bool from_up) {
	int i;

	// 도착점에 도착하면
	if(x==0 && from_up==true) {
		// 1~26은 어플리케이션 번호이고, 0번은 도착점의 번호
		// RN과 FN을 갱신
		for(int i=0; i<path.size()-1; i++) {
			// 어플리케이션에서 컴퓨터로 연결되는 간선 정보
			if(i%2==0) {
				// 연결되는 컴에 어플리케이션을 세팅한다.
				ap[path[i+1]] = path[i];
				rnu[path[i]][path[i+1]] = false;
				rnb[path[i+1]][path[i]] = true;

				// 할당한 어플리케이션 개수를 줄여준다.
				total--;
				no[path[i]]--;
			} else {
				// 컴퓨터에서 어플리케이션으로 연결되는 간선 정보
				rnb[path[i]][path[i+1]] = false;
				rnu[path[i+1]][path[i]] = true;

				// 할당해야할 어플리케이션의 개수를 늘려준다.
				// 도착점으로 가는지를 검사해야한다.
				if(path[i+1]>0) {
					total++;
					no[path[i+1]]++;
				}
			}
		}
		// 경로를 초기화 한다.
		path.clear();
		fill(checku,checku+27,false);
		fill(checkb,checkb+10,false);
		return true;
	}

	// 출발점인 경우, 무한대로 나가는 정보이기 때문에 모든 정점과 검사한다.
	if(x==-1) {
		for(int i=1; i<27; i++) {
			// 할당할 어플리케이션이 있는 경우
			if(no[i]>0) {
				path.push_back(i);
				if(DFS(i,true)==true) return true;
				path.pop_back();
			}
		}
		return false;
	}
	// 출발점이 아닌 경우
	// 어플리케이션에서 컴퓨터로 가는 경우
	if(from_up==true) {
		// 컴퓨터의 대수만큼 처리
		for(i=0; i<10; i++) {
			if(rnu[x][i]==true && checkb[i]==false) {
				// 다음정점으로 선택된 것 방문되지 않도록 체크
				checkb[i]=true;
				// 경로에 정점 추가
				path.push_back(i);
				// 하나의 경로가 처리되면 다음은 방문하지 않고 true 리턴하며 종료
				if(DFS(i,false)==true) return true;

				// 체크와 경로에 대해서 복원
				path.pop_back();
				checkb[i]=false;
			}
		}
	} else {
		// 컴퓨터에서 어플리케이션으로 가는 경우
		for(i=1; i<=27; i++) {
			// 도착점을 제일 마지막에 방문하도록 처리
			if(i==27) i=0;
			if(rnb[x][i]==true && rnu[i]==false) {
				checku[i]=true;
				// 경로에 정점 추가
				path.push_back(i);
				// 하나의 경로가 처리되면 true리턴하며 종료
				if(DFS(i,true)==true) return true;
				// 체크와 경로에 대해서 복원
				path.push_back(i);
				checku[i]=false;
			}
			// 도착점 정보 복원
			if(i==0) i==27;
		}
	}
	return false;
}

void BipariteMatching() {
	// 경로가 존재하는 동안 계속 DFS 수행
	while(DFS(-1,false));
}

int main() {

	int i,n,a;
	string str,tmp;

	while(!cin.eof()) {
		total=0;
		fill(checku, checku+27, false);
		fill(checkb, checkb+10, false);
		fill(ap,ap+10,-1);
		fill(no,no+27,0);
		for(i=0; i<27; i++) fill(rnu[i], rnu[i]+10,false);
		for(i=0; i<10; i++) fill(rnb[i], rnb[i]+10,false);

		while(1) {
			getline(cin, str);
			if(str.length()<3) break;
			istringstream is(str);

			is>>tmp;
			a = tmp[0]-'A'+1;
			if(tmp.length()==3) n = 10;
			else n=tmp[1]-'0';
			no[a]=n;

			total += n;

			// 뒷부분 처리
			is>>tmp;
			for(i=0; i<tmp.length(); i++) {
				rnu[a][tmp[i]-'0']=true;

				// 컴퓨터에서 마지막 도착점으로 가는 것을 표시
				// 애플리케이션은 1~26번을 사용하므로 도착점을 0번으로 사용한다.
				rnb[tmp[i]-'0'][0] = true;
			}
		}

		BipariteMatching();

		if(total>0) cout<<"!"<<endl;
		else {
			for(i=0; i<10; i++) {
				//연결되지 않은 경우 '_'
				if(ap[i]==-1) cout<<"_";
				else cout<<char(ap[i]+'A'-1);
			}
			cout<<endl;
		}
	}

	return 0;
}