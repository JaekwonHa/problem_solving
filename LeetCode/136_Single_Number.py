class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hash = {}
        for num in nums:
            if hash.get(num) is not None:
                del hash[num]
                continue
            hash[num] = num
        return list(hash.keys())[0]
