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
#include <deque>
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;




int main() {

	deque<int> dq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str.compare("push_back") == 0) {
			int a;
			cin >> a;
			dq.push_back(a);
		} else if (str.compare("push_front") == 0) {
			int a;
			cin >> a;
			dq.push_front(a);
		}
		else if (str.compare("pop_front") == 0) {
			if (dq.empty()) cout << "-1" << endl;
			else cout << dq.front() << endl, dq.pop_front();
		}
		else if (str.compare("pop_back") == 0) {
			if (dq.empty()) cout << "-1" << endl;
			else cout << dq.back() << endl, dq.pop_back();
		}
		else if (str.compare("front") == 0) {
			if (dq.empty()) cout << "-1" << endl;
			else cout << dq.front() << endl;
		}
		else if (str.compare("back") == 0) {
			if (dq.empty()) cout << "-1" << endl;
			else cout << dq.back() << endl;
		} else if (str.compare("size") == 0) {
			cout << dq.size() << endl;
		} else if (str.compare("empty") == 0) {
			if (dq.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
	}

	return 0;
}