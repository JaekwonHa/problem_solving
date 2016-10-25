#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

bool solve(string a, string b) {
	if (a.compare(b) == 0) return true;

	int cnt_a[26] = { 0, };
	int cnt_b[26] = { 0, };
	int n = a.length();
	bool ok = true;

	for (int i = 0; i < n; i++) cnt_a[a[i] - 'a']++, cnt_b[b[i] - 'a']++;
	for (int i = 0; i < 26; i++) if(cnt_a[i] != cnt_b[i]) ok = false;
	if (ok == false) return false;
	if (n % 2 == 1) return false;
	
	bool al_bl, al_br;
	al_bl = solve(a.substr(0, n / 2), b.substr(0, n / 2));
	al_br = solve(a.substr(0, n / 2), b.substr(n / 2));
	if (!al_bl && !al_br) return false;

	bool ar_br, ar_bl;
	ar_br = solve(a.substr(n / 2), b.substr(n / 2));
	ar_bl = solve(a.substr(n / 2), b.substr(0, n / 2));

	return (al_bl && ar_br) || (ar_bl && al_br);
}

int main() {

	string str1;
	string str2;
	cin >> str1 >> str2;

	bool ok = solve(str1, str2);

	if (ok) cout << "YES";
	else cout << "NO";

	return 0;
}