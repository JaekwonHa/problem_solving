#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int A[2001], B[2001];
int map[2001][2001];
int type[2001];
bool ok;

int bfs(int n) {
	queue<int> q;
	q.push(n);
	type[n] = 0;
	
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (map[c][i] == 1) {
				if (type[i] != -1) {
					if (type[c] == type[i]) return 0; continue;
				}
				q.push(i);
				type[i] = (type[c] + 1) % 2;
			}
		}
	}
	return 1;
}
void solveBFS() {
	for (int i = 0; i < M; i++) {
		map[A[i]][B[i]] = 1;
		map[B[i]][A[i]] = 1;
	}
	ok = true;
	memset(type, -1, sizeof(type));
	for (int i = 1; i <= N; i++) {
		if (type[i] != -1) continue;
		if (!bfs(i)) {
			ok = false;
			break;
		}
	}
}

int number[2001];
int un[2001];

int unionFind(int x) {

}
void solveUF() {
	for (int i = 1; i <= N; i++) un[i] = i;
	for (int i = 0; i < N; i++) {
		if (number[A[i]] == 0 && number[B[i]] == 0) {
			number[A[i]] = B[i];
			number[B[i]] = A[i];
			continue;
		}
		if (number[A[i]] == 0) {
			
			number[A[i]] = un[B[i]];
			continue;
		}
		if (number[B[i]] == 0) {

			number[B[i]] = un[A[i]];
			un[B[i]] = un[number[A[i]]];
			continue;
		}
	}
}

int main() {
	int a, b;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) scanf("%d %d", A + i, B + i);

	solveUF();

	ok? printf("1\n") : printf("0\n");
	return 0;
}