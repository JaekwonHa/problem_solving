open_brakets = ['(', '[', '{']
close_brakets = [')', ']', '}']

def solution(S):
    # write your code in Python 3.6

    stack = []
    for s in S:
        if s in open_brakets:
            stack.append(s)
        elif s in close_brakets:
            if len(stack) == 0:
                return 0
            last_braket = stack.pop()
            if last_braket == '(' and s != ')':
                return 0
            if last_braket == '[' and s != ']':
                return 0
            if last_braket == '{' and s != '}':
                return 0
    return 1 if len(stack) == 0 else 0