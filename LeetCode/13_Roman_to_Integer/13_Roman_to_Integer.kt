class Solution {
    fun romanToInt(s: String): Int {
        val symbolMap = mapOf(
            'I' to 1,
            'V' to 5,
            'X' to 10,
            'L' to 50,
            'C' to 100,
            'D' to 500,
            'M' to 1000
        )
        // var prev = 0.toChar()
        var prev = '\u0000'
        var result = 0
        for (c in s) {
            result += symbolMap[c]!!
            if ((c == 'V' || c == 'X') && prev == 'I') {
                result -= 2 * symbolMap[prev]!!
            } else if ((c == 'L' || c == 'C') && prev == 'X') {
                result -= 2 * symbolMap[prev]!!
            } else if ((c == 'D' || c == 'M') && prev == 'C') {
                result -= 2 * symbolMap[prev]!!
            }
            prev = c
        }
        return result
    }
}

fun main() {
    val solution = Solution()
    val s = "MCMXCIV"
    print(solution.romanToInt(s))
}