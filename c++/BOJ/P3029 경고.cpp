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
#include <iomanip>
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


int main() {

	int h1, m1, s1, h2, m2, s2;

	scanf("%d:%d:%d", &h1, &m1, &s1);
	scanf("%d:%d:%d", &h2, &m2, &s2);

	if (s1 > s2) {
		s2 += 60;
		m1++;
	}
	if (m1 > m2) {
		m2 += 60;
		h1++;
	}
	if (h1 > h2) {
		h2 += 24;
	}

	int h3 = h2 - h1;
	int m3 = m2 - m1;
	int s3 = s2 - s1;

	char *ch = new char[3];
	if (h3 == 0) ch[0] = ch[1] = '0';
	else {
		ch[0] = '0' + h3 / 10;
		ch[1] = '0' + h3 % 10;
	}
	ch[2] = '\0';
	char *cm = new char[3];
	if (m3 == 0) cm[0] = cm[1] = '0';
	else {
		cm[0] = '0' + m3 / 10;
		cm[1] = '0' + m3 % 10;
	}
	cm[2] = '\0';
	char *cs = new char[3];
	if (s3 == 0) cs[0] = cs[1] = '0';
	else {
		cs[0] = '0' + s3 / 10;
		cs[1] = '0' + s3 % 10;
	}
	cs[2] = '\0';

	if (h1 == h2 && m1 == m2 && s1 == s2) {
		printf("24:00:00\n");
	}
	else {
		printf("%s:%s:%s\n", ch, cm, cs);
	}
	

	/*
	cout << setw(2) << setfill('0') << h3;
	cout << ":";
	cout << setw(2) << setfill('0') << m3;
	cout << ":";
	cout << setw(2) << setfill('0') << s3;
	cout << endl;
	*/
	return 0;
}