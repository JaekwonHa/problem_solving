from typing import List


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []
        hash_table = {}
        for i in nums1:
            hash_table.setdefault(i, 0)
            hash_table[i] += 1
        for i in nums2:
            if hash_table.get(i) is not None and hash_table.get(i) > 0:
                hash_table[i] -= 1
                result.append(i)
        return result


solution = Solution()
print(solution.intersect([4,9,5], [9,4,9,8,4]))
