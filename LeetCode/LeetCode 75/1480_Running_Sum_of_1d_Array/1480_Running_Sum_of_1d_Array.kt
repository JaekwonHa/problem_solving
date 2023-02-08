class Solution {
    fun runningSum(nums: IntArray): IntArray {
        for (i in 1 until nums.size) {
            nums[i] += nums[i-1]
        }
        return nums
    }
}

fun main() {
    val s = Solution()
    val input = intArrayOf(1,2,3,4)
    print(s.runningSum(input))
}
