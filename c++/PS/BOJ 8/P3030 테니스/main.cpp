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
#include <set>
#include <deque>
#include <functional>
#include <sstream>
using namespace std;

// 정답이 ll 이상일 경우 INF를 98765432100000 정도까지 크게 해야함
// 입력받는 값이 10^9 이고 답이 뭔가 그것들을 더하는 연산이라면 답은 ll 일수 있다
// priority_queue 는 기본적으로 내림차순 정렬이다. 오름차순으로 하고 싶다면 priority_queue<int, vector<int>, greater<int>>
// queue에서 pop하기 전에는 반드시 empty인 경우를 체크하고 예외처리 해줘라


#define INF 9876543210
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

pair<int, int> getScore(string str) {
	stringstream ss(str);

	int *s1 = new int[2];

	int i = 0;
	while (1) {
		string token;
		if (getline(ss, token, ':')) {
			s1[i] = stoi(token);
		}
		else {
			break;
		}
		i++;
	}
	return mp(s1[0], s1[1]);
}

int main() {

	string str1, str2;
	cin >> str1 >> str2;
	int N;
	scanf("%d\n", &N);
	string match;
	//getline(cin, match);

	char ch[100];

	bool ok;
	for (int i = 0; i < N; i++) {
		ok = true;

		//getline(cin, match);
		fgets(ch, sizeof(ch), stdin);
		
		//stringstream ss(match);

		int set1 = 0, set2 = 0;

		bool isTwoWin = false;

		char *p = ch;
		int score1, score2, ucitano;
		for (int i = 1; sscanf(p, "%d:%d%n", &score1, &score2, &ucitano) == 2; i++) {
			p += ucitano;

			bool isMatchEnd = false;

			if (set1 > 2 || set2 > 2) {
				printf("ne\n");
				ok = false;
				break;
			}

			if (i <= 2) {
				if (score1 == 7 && score2 == 6) {
					set1++;
					isMatchEnd = true;
				}
				if (score2 == 7 && score1 == 6) {
					set2++;
					isMatchEnd = true;
				}		
			}

			if (score1 >= 6 && score1 - score2 >= 2) {
				set1++;
				isMatchEnd = true;
			}
			if (score2 >= 6 && score2 - score1 >= 2) {
				set2++;
				isMatchEnd = true;
			}

			if (max(set1, set2) == 2) isTwoWin = true;
			
			if (isMatchEnd) {
				
			}

			// 로저 페더러가 졌을때
			if (str1.compare("federer") == 0 && score1<score2) {
				printf("ne\n");
				ok = false;
				break;
			}
			// 로저 페더러가 졌을때
			if (str2.compare("federer") == 0 && score1>score2) {
				printf("ne\n");
				ok = false;
				break;
			}
		}
		
		if (!ok) continue;

		if (!(set1==2 || set2==2)) {
			printf("ne\n");
			continue;
		}

		printf("da\n");
	}

	return 0;
}