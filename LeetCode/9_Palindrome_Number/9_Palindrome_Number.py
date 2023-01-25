class Solution:
    def isPalindrome(self, x: int) -> bool:
        nums = []

        if x < 0:
            nums.append(999)
            x = abs(x)

        remain = x
        while(remain > 0):
            last_number = remain % 10
            remain = int(remain / 10)
            nums.append(last_number)
        
        length = len(nums)
        for i, num in enumerate(nums):
            if num != nums[length-1-i]:
                return False
        return True

x = 10

s = Solution()
print(s.isPalindrome(x))
