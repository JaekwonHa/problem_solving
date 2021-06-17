def validBraces(string):

    braces = {
        '(': ')',
        '{': '}',
        '[': ']'
    }

    stack = []
    for s in string:
        if s in braces.keys():
            stack.append(s)
        elif len(stack) == 0 or s != braces[stack.pop()]:
            return False
    return len(stack) == 0


print(validBraces("()"))
print(validBraces("({})"))
print(validBraces("(){}[]"))
print(validBraces("[({})](]"))
