class Solution:
    def transform(self, number, base) -> int:
        remain = number
        temp = []
        while remain >= base:
            temp.append(str(remain % base))
            remain //= base
        temp.append(str(remain))
        return int(''.join(temp[::-1]))

    def checkPalindromic(self, number) -> bool:
        number = str(number)
        left, right = 0, len(number)-1

        while left <= right:
            if number[left] != number[right]:
                return False
            left += 1
            right -= 1
        return True

    def isStrictlyPalindromic(self, n: int) -> bool:
        for base in range(2, n-1):
            target = self.transform(n, base)
            if not self.checkPalindromic(target):
                return False
        return True

s = Solution()

input = 9
print(s.isStrictlyPalindromic(input))
