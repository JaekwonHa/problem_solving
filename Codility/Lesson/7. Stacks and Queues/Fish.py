def solution(A, B):
    # write your code in Python 3.6
    stack = []
    for i in range(len(A)):
        if len(stack) == 0:
            stack.append(i)
            continue

        while True:
            if len(stack) != 0 and B[stack[-1]] == 1 and B[i] == 0:
                if A[stack[-1]] < A[i]:
                    stack.pop()
                else:
                    break
            else:
                stack.append(i)
                break

    return len(stack)