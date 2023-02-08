class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low, high = 0, len(nums)
        while low < high:
            mid = (low + high) // 2
            if nums[mid] == target:
                return mid
            if target < nums[mid]:
                high = mid 
            else:
                low = mid+1
        return -1