class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if len(stack) == 0:
                stack.append(c)
                continue
            if stack[-1] == '(' and c == ')':
                stack.pop()
                continue
            if stack[-1] == '{' and c == '}':
                stack.pop()
                continue
            if stack[-1] == '[' and c == ']':
                stack.pop()
                continue
            stack.append(c)
        
        if len(stack) > 0:
            return False
        return True

s = Solution()

print(s.isValid("()"))