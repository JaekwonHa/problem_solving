from random import random
from typing import List


class Solution:

    def __init__(self, w: List[int]):
        self.prefix_sums = []
        prefix_sum = 0
        for number in w:
            prefix_sum += number
            self.prefix_sums.append(prefix_sum)
        self.weight_sum = prefix_sum

    def pickIndex(self) -> int:
        # # step1 linear search
        # target = int(random() * self.weight_sum)
        # for i in range(len(self.prefix_sums)):
        #     if target < self.prefix_sums[i]:
        #         return i

        # step2 binary search
        target = int(random() * self.weight_sum)
        left, right = 0, len(self.prefix_sums)-1
        while left <= right:
            mid = (left + right) // 2

            start = self.prefix_sums[mid-1] if mid > 0 else 0
            end = self.prefix_sums[mid]
            if start <= target < end:
                return mid

            if target < self.prefix_sums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        return left


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()