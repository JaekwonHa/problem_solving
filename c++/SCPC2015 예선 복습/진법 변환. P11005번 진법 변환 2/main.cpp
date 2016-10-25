#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int N,B;
vector<char> ans_list;

char trans(int a) {
	if(a<10) return a+'0';
	return a-10+'A';
}

int main() {

	scanf("%d %d", &N, &B);

	while(0<N) {
		int b = N%B;
		N /= B;
		char c = trans(b);
		ans_list.push_back(c);
	}

	for(int i=ans_list.size()-1; i>=0; i--)
		printf("%c", ans_list[i]);

	return 0;
}