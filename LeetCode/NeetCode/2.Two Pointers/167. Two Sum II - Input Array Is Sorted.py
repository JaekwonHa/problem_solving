from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        head, tail = 0, len(numbers)-1

        result = numbers[head] + numbers[tail]
        while result != target:
            if result < target:
                head += 1
            if result > target:
                tail -= 1
            result = numbers[head] + numbers[tail]

        return [head + 1, tail + 1]
