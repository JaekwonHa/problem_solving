#include <iostream>
using namespace std;

int main() {

	int a, b, c;
	cin >> a >> b >> c;

	double d = (a*a) / (b*b + c*c);

	int ans1 = b*((int)d);
	int ans2 = c*((int)d);

	cout << ans1 << " " << ans2 << endl;

	return 0;
}