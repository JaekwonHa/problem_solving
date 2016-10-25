#include <iostream>

using namespace std;

int ans[10];

void calc(long long n, long long ten) {
	while(n>0) {
		//ans[n%10] = ans[n%10] + 1*ten;
		ans[n%10] += ten;
		n /= 10;
	}
}

int main() {

	long long start=1;
	long long end;
	long long ten=1LL;

	cin>>end;
	while(start <= end) {
		while(start%10 != 0 && start <= end) {
			calc(start, ten);
			start++;
		}
		if(start > end) break;
		while(end%10 != 9 && start <= end) {
			calc(end, ten);
			end--;
		}
		if(start > end) break;
		for(int i=0; i<10; i++) {
			ans[i] += ((end/10) - (start/10) +1)*ten;
		}
		ten *= 10LL;
		start /= 10;
		end /= 10;
	}
	for(int i=0; i<10; i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}








/**
#include <iostream>
using namespace std;
long long ans[10];
void calc(long long n, long long ten) {
    while (n > 0) {
        ans[n%10] += ten;
        n = n/10;
    }
}
int main() {
    long long start=1;
    long long end;
    long long ten=1;
    cin >> end;
    while (start <= end) {
        while (start % 10 != 0 && start <= end) {
            calc(start,ten);
            start += 1;
        }
        if (start > end) break;
        while (end % 10 != 9 && start <= end) {
            calc(end,ten);
            end -= 1;
        }
        long long cnt = (end/10 - start/10 + 1);
        for (int i=0; i<=9; i++) {
            ans[i] += cnt*ten;
        }
        start = start / 10;
        end = end / 10;
        ten = ten*10LL;
    }
    for (int i=0; i<=9; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}



*/



/**

보통 for문 1억번에 1초
근데 이건 N의 크기가 10억이기 때문에 이런식으로 했다가는 시간초과가 난다.

#include <stdio.h>
#include <string.h>
#include <cstdlib>	// itoa 사용할 때 필요
int main() {

	int N,i,j;
	int answer[11];
	char number[11];
	memset(answer,0,sizeof(answer));
	scanf("%d", &N);
	for(i=1; i<=N; i++) {
		//itoa(i, number, 10);
		sprintf(number,"%d", i);
		for(j=0; j<strlen(number); j++) {
			char temp = number[j];
			answer[atoi(&temp)]++;
		}
	}
	for(i=0; i<10; i++) {
		if(i!=0) printf(" ");
		printf("%d", answer[i]);
	}

	return 0;
}

*/