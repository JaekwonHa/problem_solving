class Solution:
    def longestPalindrome(self, s: str) -> int:
        hash = {}
        for c in s:
            hash.setdefault(c, 0)
            hash[c] += 1
        length = 0
        is_odd = False
        for key, value in hash.items():
            if value%2 == 1:
                is_odd = True
            length += 2 * int(value/2)
        if is_odd:
            length += 1
        return length