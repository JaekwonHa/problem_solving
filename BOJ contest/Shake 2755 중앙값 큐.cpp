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
#include <set>
#include <stack>
#include <functional>
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;


int main() {

	freopen("input.txt", "r", stdin);

	int n, a;
	scanf("%d", &n);
	
	string input;

	priority_queue<int, vector<int>, greater<int>> largeQ;
	priority_queue<int> smallQ;
	int count = 0, mid;

	for (int i = 1; i <= n; i++) {
		cin >> input;
		if (input.compare("PUSH") == 0) {
			scanf("%d", &a);
			if (count == 0) smallQ.push(a), mid=a;
			else {
				if (mid <= a) largeQ.push(a);
				else smallQ.push(a);

				if (smallQ.size() - largeQ.size() == 2) {
					int temp = mid;
					largeQ.push(smallQ.top());
					smallQ.pop();
					mid = smallQ.top();
				}
				if (largeQ.size() - smallQ.size() == 1) {
					smallQ.push(largeQ.top());
					largeQ.pop();
					mid = smallQ.top();
				}
			}
			printf("%d\n", smallQ.top());
			count++;
		}
		else if (input.compare("POP") == 0) {
			if (count == 0) printf("NO ITEM\n");
			else {
				count--;
				smallQ.pop();
				if (largeQ.size() - smallQ.size() == 1) {
					smallQ.push(largeQ.top());
					largeQ.pop();
					mid = smallQ.top();
				}
				if (count == 0) {
					printf("NO ITEM\n");
				}
				else {
					mid = smallQ.top();
					printf("%d\n", smallQ.top());
				}
			}
		}
		else {
			printf("%d\n", count);
		}
	}

	return 0;
}