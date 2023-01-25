import sys
readline=sys.stdin.readline




def preorder(tree, root):
    if root == '.':
        return

    print(root, end='')
    preorder(tree, tree[root][0])
    preorder(tree, tree[root][1])


def inorder(tree, root):
    if root == '.':
        return

    inorder(tree, tree[root][0])
    print(root, end='')
    inorder(tree, tree[root][1])


def postorder(tree, root):
    if root == '.':
        return

    postorder(tree, tree[root][0])
    postorder(tree, tree[root][1])
    print(root, end='')


if __name__ == '__main__':
    N = int(readline())

    tree = {}
    for _ in range(N):
        a, b, c = readline().split()
        tree[a] = (b, c)

    preorder(tree, 'A')
    print('')
    inorder(tree, 'A')
    print('')
    postorder(tree, 'A')
    print('')
