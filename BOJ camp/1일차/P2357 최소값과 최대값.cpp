#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAXN 100010

struct Query {
	int idx, a, b, value;
} q[MAXN];

int N, M,zz;
int arr[MAXN],ansMIN[MAXN],ansMAX[MAXN];

int s[MAXN], e[MAXN];
pair<int,int> list[MAXN];

int main() {

	int a, b;
	scanf("%d %d", &N, &M);
	zz = sqrt(N + 0.0);
	memset(s, -1, sizeof(s));
	for (int i = 0; i <= N; i++) {
		int g = i / zz;
		if (s[g] == -1) s[g] = i;
		e[g] = i;
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", arr + i);
		int g = i / zz;
		if (ansMIN[g] == 0) ansMIN[g] = arr[i];
		else ansMIN[g] = min(ansMIN[g], arr[i]);
		ansMAX[g] = max(ansMAX[g], arr[i]);
	}
	
	
	
	
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);

		int t1 = 2000000000, t2 = 0;
		for (int i = a; i <= b; i++) {
			int g = i / zz;
			if (s[g] == i && e[g] <= b) {
				// 구간에 대한 작업
				t1 = min(t1, ansMIN[g]);
				t2 = max(t2, ansMAX[g]);
				i = e[g];
			}
			else {
				// 개개에 대한 작업
				for (int j = i; j <= b && j <= e[g]; j++) {
					t1 = min(t1, arr[j]);
					t2 = max(t2, arr[j]);
				}
				i = e[g];
			}
		}
		list[i].first = t1;
		list[i].second = t2;
	}
	for (int i = 1; i <= M; i++) {
		printf("%d %d\n", list[i].first, list[i].second);
	}



	/*
	scanf("%d %d", &N, &M);
	zz = sqrt(N + 0.0);
	for (int i = 1; i <= N; i++) scanf("%d", arr + i);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &q[i].a, &q[i].b);
		q[i].idx = i;
		q[i].value = (q[i].a / zz)*zz + q[i].b / zz;
	}
	std::sort(q, q + M, [](Query a, Query b) {
		return a.value < b.value;
	});
	int MIN = 987654321, MAX=0;
	for (int i = q[0].a; i <= q[0].b; i++) {
		MIN = min(MIN, arr[i]);
		MAX = max(MAX, arr[i]);
	}
	ansMIN[q[0].idx] = MIN;
	ansMAX[q[0].idx] = MAX;
	for (int i = 1; i < M; i++) {
		ansMIN[q[i].idx] = MIN;
		ansMAX[q[i].idx] = MAX;
	}
	*/


	return 0;
}