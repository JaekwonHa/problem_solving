# The isBadVersion API is already defined for you.
def isBadVersion(version: int) -> bool:
    return True

class Solution:
    def firstBadVersion(self, n: int) -> int:
        lower, high = 1, n
        while lower <= high:
            mid = (lower + high) // 2
            if isBadVersion(mid) == False:
                lower = mid + 1
            else:
                if (mid-1)<0 or isBadVersion(mid-1) == False:
                    return mid
                high = mid