class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        transformed = ''
        for c in s:
            if c.isalnum():
                transformed += c
        head, tail = 0, len(transformed)-1
        while head < len(transformed):
            if transformed[head] != transformed[tail]:
                return False
            head += 1
            tail -= 1
        return True
