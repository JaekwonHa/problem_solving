#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {

	string str;
	cin >> str;

	int ans = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'Y') {
			ans++;
			for (int j = i; j < str.length(); j += (i + 1)) {
				if (str[j] == 'Y') str[j] = 'N';
				else str[j] = 'Y';
			}
		}
	}

	cout << ans << endl;

	return 0;
}