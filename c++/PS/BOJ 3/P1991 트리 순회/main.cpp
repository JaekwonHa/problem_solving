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
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;

/*
class tree {
public :
	char item;
	tree* left;
	tree *right;
	static tree *create_node(char node);
};
tree *tree::create_node(char node) {
	tree *a;
	a = new tree;
	a->item = node;
	a->left = NULL;
	a->right = NULL;
	return a;
}
void preorder(tree *root) {
	if (root->item == '.') return;
	printf("%c", root->item);
	preorder(root->left);
	preorder(root->right);
}
void inorder(tree *root) {
	if (root->item == '.') return;
	inorder(root->left);
	printf("%c", root->item);
	inorder(root->right);
}
void postorder(tree *root) {
	if (root->item == '.') return;
	postorder(root->left);
	postorder(root->right);
	printf("%c", root->item);
}
*/
typedef struct Tree {
	char left, right;
} tree;

tree t[100];

void preorder(char data) {
	if (data == '.') return;
	printf("%c", data);
	preorder(t[data].left);
	preorder(t[data].right);
}
void inorder(char data) {
	if (data == '.') return;
	inorder(t[data].left);
	printf("%c", data);
	inorder(t[data].right);
}
void postorder(char data) {
	if (data == '.') return;
	postorder(t[data].left);
	postorder(t[data].right);
	printf("%c", data);
}

int main() {

	int n;
	scanf("%d", &n);
	char node_l, node_r, node;
	for (int i = 0; i < n; i++) {
		scanf(" %c %c %c", &node, &node_l, &node_r);
		t[node].left = node_l;
		t[node].right = node_r;
	}

	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
	printf("\n");

	return 0;
}