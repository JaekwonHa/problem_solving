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
using namespace std;

typedef long long ll;

template<class E>
class Stack {
	E *p;
	int top;
	int maxSize;
public:
	Stack();
	Stack(St	ack& stack);
	void push(E data);
	E pop();
	int size();
};
template<class E>
Stack<E>::Stack() {
	p = new E[1000000];
	top = 0;
	maxSize = 1000000;
}
template<class E>
Stack<E>::Stack(Stack& stack) {	// ¾èÀº º¹»ç
	this->p = stack.p;
	this->top = stack.top;
}
template<class E>
void Stack<E>::push(E data) {
	if (top < maxSize) {
		p[top] = data;
		top++;
		return;
	}
	else {
		// stack is full
		return;
	}
}

template<class E>
E Stack<E>::pop() {
	if (top > 0) {
		return p[--top];
	}
	else {
		// stack is empty
		return 0;
	}
}
template<class E>
int Stack<E>::size() {
	return top;
}


int main() {


	int T, n;
	cin >> T;
	while (T--) {
		string pass;
		cin >> pass;

		Stack<char> resultStack;
		Stack<char> tempStack;

		int len = pass.length();
		for (int i = 0; i < len; i++) {
			if (pass[i] == '<') {
				if (resultStack.size() != 0) {
					tempStack.push(resultStack.pop());
				}
			}
			else if (pass[i] == '>') {
				if (tempStack.size() != 0) {
					resultStack.push(tempStack.pop());
				}
			}
			else if (pass[i] == '-') {
				resultStack.pop();
			}
			else {
				resultStack.push(pass[i]);
			}
		}
		while (tempStack.size() != 0) {
			resultStack.push(tempStack.pop());
		}
		string ans;
		while (resultStack.size() != 0) {
			ans += resultStack.pop();
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}


	return 0;
}