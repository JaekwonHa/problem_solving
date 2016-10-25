#include <iostream>

using namespace std;

int main() {
	long n,c1,c2,n1,n2,m1,m2;
	long temp;
	int check;


	while(1) {
		cin>>n;
		if(n==0) break;
		cin>>c1>>n1;
		cin>>c2>>n2;

		check=0;
		// 용량 대 가격비가 싼것을 c1,n1으로 둔다
		if((double)c1/n1 > (double)c2/n2) {
			swap(c1,c2);
			swap(n1,n2);
			check=1;
		}
		// 구슬을 최대한으로 담을 수 있는 첫번째 상자의 개수
		m1 = n/n1;
		// loop는 구슬을 최대한으로 담을 수 있는 천번째 상자의 개수에서
		// 두번째 상자의 크기를 뺀 수 만큼만 돌면 된다.
		for(; m1>=n/n1-n2 && m1>=0; m1--) {
			// 첫번째 상자의 개수를 하나씩 줄여가면서 그 상자에 최대한
			// 담고 남는 구슬들을 두번째 상자로 채운다.
			m2 = (n-m1*n1)/n2;
			if(n == m1*n1 + m2*n2) break;	// 그렇게 해서 남는 구슬이 없으면 break
		}
		if(n==m1*n1 + m2*n2) {
			if(check==0)
				cout<<m1<<" "<<m2<<endl;
			else
				cout<<m2<<" "<<m1<<endl;
		} else
			cout<<"failed"<<endl;
	}
	return 0;
}