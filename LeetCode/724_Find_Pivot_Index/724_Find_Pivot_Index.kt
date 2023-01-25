class Solution {
    fun pivotIndex(nums: IntArray): Int {
        val partial_sum = mutableListOf(0)
        for (i in 0 until nums.size) {
            partial_sum.add(nums[i] + partial_sum[i])
        }
        partial_sum.add(0)
        
        for (i in 0 until nums.size) {
            if (partial_sum[i] == partial_sum[nums.size] - partial_sum[i+1]) {
                return i
            }
        }
        return -1
    }
}

fun main() {
    val s = Solution()
    val nums = intArrayOf(1,7,3,6,5,6)
    print(s.pivotIndex(nums))
}