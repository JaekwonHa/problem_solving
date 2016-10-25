#include <iostream>
using namespace std;

int main() {


	int r, c, k;
	cin >> r >> c >> k;

	if (k == 1) {
		cout << "1" << endl;
	}
	else {
		if (r % 2 == 1 && c % 2 == 1) {
			cout << "0" << endl;
		}
		else {
			cout << "1" << endl;
		}
	}
	return 0;
}