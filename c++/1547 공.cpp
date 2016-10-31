#include <iostream>
#include <algorithm>
using namespace std;



int main() {

	int M,X,Y,pos=1;
	scanf("%d", &M);
	for(int i=0; i<M; i++) {
		scanf("%d %d", &X, &Y);
		if(X==pos) pos=Y;
		else if(Y==pos) pos=X;
	}

	printf("%d\n", pos);


	return 0;
}