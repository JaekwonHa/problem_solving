#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string S;
string T;

string reverse(string str) {
	/*
	if (str.length() <= 1) return str;
	return reverse(str.substr(str.length() / 2)) + str.substr(0, str.length() / 2 - 1);
	*/
	int len = str.length();
	char* front = NULL;
	char* rear = NULL;
	str.c_str();
	front = &str[0];
	rear = &str[len - 1];

	for (int i = 0; i < len / 2; i++) {
		char temp = *front;
		*front = *rear;
		*rear = temp;

		*front++;
		*rear--;
	}
	return str;
}

bool f(string str) {
	if (str.length() == S.length()) {
		if (str.compare(S) == 0) return true;
		return false;
	}
	bool ok;
	if (str[str.length() - 1] == 'A') {
		return f(str.substr(0, str.length() - 1));
	}
	else {
		return f(reverse(str.substr(0, str.length() - 1)));
	}
}

int main() {
	cin >> S >> T;

	bool ok = f(T);

	ok ? cout << "1" : cout << "0";
	return 0;
}