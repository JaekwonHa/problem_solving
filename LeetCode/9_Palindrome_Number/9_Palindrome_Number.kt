class Solution {
    fun isPalindrome(x: Int): Boolean {
        if (x < 0) {
            return false
        }
        val nums: MutableList<Int> = mutableListOf()
        
        var remain: Int = x

        while(remain > 0) {
            val last_digit = remain % 10
            remain = remain / 10
            nums.add(last_digit)
        }

        for ((i, num) in nums.withIndex()) {
            if (num != nums[nums.size-1-i]) {
                return false
            }
        }
        return true
    }
}

fun main() {
    val s = Solution()
    val x = -121
    println(s.isPalindrome(x))
}
