#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
using namespace std;

#define INF 987654321
#define p 1000000007
typedef long long ll;

map<string, int> m1{
	{ "black",0 },
	{ "brown",1 },
	{ "red",2 },
	{ "orange",3 },
	{ "yellow",4 },
	{ "green",5 },
	{ "blue",6 },
	{ "violet",7 },
	{ "grey",8 },
	{ "white",9 }
};

map<string, int> m2{
	{ "black",1 },
	{ "brown",10 },
	{ "red",100 },
	{ "orange",1000 },
	{ "yellow",10000 },
	{ "green",100000 },
	{ "blue",1000000 },
	{ "violet",10000000 },
	{ "grey",100000000 },
	{ "white",1000000000 }
};

int main() {

	long long ans;
	string str1;
	cin >> str1;
	ans = 10*m1[str1];

	cin >> str1;
	ans += m1[str1];

	cin >> str1;
	ans *= m2[str1];

	cout << ans << endl;

	return 0;
}