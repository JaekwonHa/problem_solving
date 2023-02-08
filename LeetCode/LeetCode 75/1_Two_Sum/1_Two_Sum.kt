class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val cache: MutableMap<Int, Int> = mutableMapOf()
        for ((i, one) in nums.withIndex()) {
            cache.put(one, i)
        }

        for ((i, one) in nums.withIndex()) {
            val two = target - one
            val j: Int? = cache.get(two)
            if (j != null && i != j) {
                return intArrayOf(i, j)
            }
        }
        return intArrayOf(0, 1)
    }
}

fun main() {
    val nums = intArrayOf(3,2,4)
    val target = 6

    val s = Solution()
    val result = s.twoSum(nums, target)
    println("[${result[0]}, ${result[1]}]")
}
