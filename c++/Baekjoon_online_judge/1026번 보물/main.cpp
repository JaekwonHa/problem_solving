#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int N,i,answer=0;
	int A[51], B[51];
	cin>>N;
	for(i=0; i<N; i++)
		cin>>A[i];
	for(i=0; i<N; i++)
		cin>>B[i];
	sort(A, A+N);
	sort(B, B+N);
	for(i=0; i<N; i++) {
		answer += A[i] * B[N-1-i];
	}
	cout<<answer;

	return 0;
}