def solution(H):
    # write your code in Python 3.6
    answer = 0
    stack = []
    for h in H:
        # print(*stack, sep = ", ")
        if len(stack) == 0:
            answer += 1
            stack.append(h)
            continue
        if stack[-1] == h:
            continue
        if stack[-1] < h:
            answer += 1
            stack.append(h)
            continue
        while len(stack) > 0 and stack[-1] > h:
            stack.pop()
            if len(stack) == 0:
                answer += 1
                stack.append(h)
                continue
            if stack[-1] == h:
                continue
            if stack[-1] < h:
                answer += 1
                stack.append(h)
                continue

    return answer