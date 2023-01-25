import sys
from collections import deque
sys.setrecursionlimit(10**6)
readline=sys.stdin.readline


postorder_result = deque([])


def dfs_postorder(preorder_numbers, inorder_numbers):
    if len(inorder_numbers) == 0:
        return
    if len(inorder_numbers) == 1:
        postorder_result.append(inorder_numbers[0])
        return

    root_index = inorder_numbers.index(preorder_numbers[0])
    if root_index == 0:
        dfs_postorder(preorder_numbers[1:], inorder_numbers[root_index+1:])
        postorder_result.append(preorder_numbers[0])
    elif root_index == len(inorder_numbers) - 1:
        dfs_postorder(preorder_numbers[1:], inorder_numbers[:root_index])
        postorder_result.append(preorder_numbers[0])
    else:
        left_inorder = inorder_numbers[:root_index]
        right_inorder = inorder_numbers[root_index + 1:]
        left_preorder = preorder_numbers[1:len(left_inorder) + 1]
        right_preorder = preorder_numbers[len(left_inorder) + 1:]

        dfs_postorder(left_preorder, left_inorder)
        dfs_postorder(right_preorder, right_inorder)
        postorder_result.append(preorder_numbers[0])


if __name__ == '__main__':
    T = int(readline())
    for _ in range(T):
        N = int(readline())
        preorder_numbers = list(map(int, readline().split()))
        inorder_numbers = list(map(int, readline().split()))

        dfs_postorder(preorder_numbers, inorder_numbers)

        while len(postorder_result) != 0:
            print(postorder_result.popleft(), end=' ')
        print('')
