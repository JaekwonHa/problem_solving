#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/**
	0ms ÀÇ Á¤´ä

	int T, A, B, C;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &A, &B);
        C = 1;
        while (B){
            if (B % 2) C = (C* A) % 10;
            B /= 2;
            A = (A*A) % 10;         
        }
        printf("%d\n", C ? C : 10);
    }

*/


int main() {

	int T;
	int a,b;

	cin>>T;

	while(T--) {
		int answer=1;
		cin>>a>>b;

		if(a%10 == 0) answer = 10;
		else {
			vector<int> step;
			int first= a%10;
			int second = first;
			step.push_back(second);
			int count=0;
			while(1) {
				count++;
				second *= a;
				second %= 10;
				if(second == first) break;
				step.push_back(second);
			}
			b %= count;
			if(b==0) answer = step[count-1];
			else answer = step[b-1];
		}
		cout<<answer<<endl;
	}

}