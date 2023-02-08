class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        val result = StringBuilder()
        for ((i, c) in strs[0].withIndex()) {
            for (str in strs) {
                if (str.length <= i || str[i] != c) {
                    return result.toString()
                }
            }
            result.append(c)
        }
        return result.toString()
    }
}

fun main() {
    val s = Solution()

    val input = arrayOf("flower", "flow", "flight")
    print(s.longestCommonPrefix(input))
}
