#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MAXN 4010

string a,b,str;
int DP[MAXN][MAXN],p[MAXN][MAXN];
int cnt;

void LCS() {
	int i,j,l1,l2;
	l1=a.length();
	l2=b.length();

	int lastX,lastY;

	for(i=1; i<=l1; i++) {
		for(j=1; j<=l2; j++) {
			// 두 문자가 같을 경우
			if(a[i-1]==b[j-1]) {
				DP[i][j]=DP[i-1][j-1]+1;
				// 우하 대각선 대신 1로 설정
				p[i][j]=1;
				lastX=i,lastY=j;
			}
			// 같지 않은 경우
			else {
				// 왼쪽에서 오는 값이 더 좋은 경우
				if(DP[i][j-1]>=DP[i-1][j]) {
					DP[i][j]=DP[i][j-1];
					// 우화살표 대신 2로 저장
					p[i][j]=2;
				}
				// 위에서 오는 값이 더 좋은 경우
				else {
					DP[i][j]=DP[i-1][j];
					// 아래화살표 대신 3으로 저장
					p[i][j]=3;
				}
			}
		}
	}
	//최장 공통 문자열 역추적
	i=l1;
	j=l2;
	while(i>0 && j>0) {
		switch(p[i][j]) {
		case 1:
			// 대각선으로 올라가는 경우
			// 해당 열의 문자열 저장
			str[cnt++]=a[i-1];
			i--,j--;
			break;
		case 2:
			// 왼쪽으로 가는 경우
			j--;
			break;
		case 3:
			i--;
			break;
		}
	}
	// 거꾸로 저장된 공통 문자열 출력
	for(i=cnt-1; i>=0; i--) {
		cout<<str[i];
	}
	cout<<endl;

	printf("%d\n", DP[lastX][lastY]);
}

int main() {
	cin>>a>>b;

	LCS();

	return 0;
}