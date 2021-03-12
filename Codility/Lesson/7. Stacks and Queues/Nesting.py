open_bracket = '('
close_bracket = ')'

def solution(S):
    # write your code in Python 3.6
    stack = []
    for s in S:
        if s == open_bracket:
            stack.append(s)
            continue
        if len(stack) == 0:
            return 0
        last_bracket = stack.pop()
        if last_bracket != open_bracket:
            return 0

    return 1 if len(stack) == 0 else 0