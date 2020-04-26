#include <iostream>
#include <string.h>


/**

다음과 같이 nfs 로 바꿔서 문제를 해결할 수 있다.
중요할듯 !! nfs 가 뭔지 dfs 가 뭔지

char str[211];
bool nfs(int i)
{
    if (i >= l) return true;
    if (str[i] == '0') return str[i + 1] == '1' ? nfs(i + 2) : false;
    if (str[i + 1] != '0' || str[i + 2] != '0') return false;
    int j = i + 3,k;
    for (; j < l; j++) if (str[j] != '0') break;
    if (j == l) return false;
    for (k = j+1; k < l; k++) if (str[k] != '1') break;
    if (k - 1 != j) return nfs(k) || nfs(k - 1);
    else return nfs(k);
}

*/


using namespace std;
char buffer[200];
int length;

bool case_1(int x);
bool case_2(int x);

int main() {

	int T;
	cin>>T;
	while(T--) {
		cin>>buffer;
		length = strlen(buffer);
		bool answer;
		(buffer[0]=='1') ? answer=case_1(0) : answer=case_2(0);
		(answer) ? cout<<"YES" : cout<<"NO";
		cout<<endl;
	}
}

bool case_1(int x) {
	if(buffer[x+1]=='1') return false;
	if(x+2==length || buffer[x+2]=='1') return false;
	do {
		if(x+1==length) return false;
	} while(buffer[++x]=='0');

	if(buffer[x+1]=='0')
		return case_2(x+1);

	while(1) {
		if(x+1==length) return true;
		if(buffer[x]=='1') {
			x++;
			continue;
		}
		if(x+1==length) return false;
		if(buffer[x+1]=='1') return case_2(x);
		return case_1(x-1);
	}
}
bool case_2(int x) {
	if(x+1==length || buffer[x+1]=='0')
		return false;
	if(x+2==length && buffer[x+1]=='1')
		return true;
	if (buffer[x+2]=='1')
		return case_1(x+2);
	if (buffer[x+2]=='0')
		return case_2(x+2);
}