from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        length = len(nums)
        length2 = len(set(nums))
        if length == length2:
            return False
        return True
