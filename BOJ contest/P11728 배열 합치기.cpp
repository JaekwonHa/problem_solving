#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;


int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	int *A = new int[n];
	int *B = new int[m];
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	for (int i = 0; i < m; i++) scanf("%d", &B[i]);

	sort(A, A + n);
	sort(B, B + m);
	int *C = new int[n + m];

	int cntA=0, cntB = 0;
	for (int i = 0; i < n + m; i++) {
		
		if (cntA == n) {
			C[i] = B[cntB++];
			continue;
		}
		if (cntB == m) {
			C[i] = A[cntA++];
			continue;
		}

		if (A[cntA] < B[cntB]) C[i] = A[cntA++];
		else C[i] = B[cntB++];
		
	}
	for (int i = 0; i < n + m; i++)
		printf("%d ", C[i]);

	return 0;
}