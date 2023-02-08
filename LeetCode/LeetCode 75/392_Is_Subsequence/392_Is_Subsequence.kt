class Solution {
    fun isSubsequence(s: String, t: String): Boolean {
        if (s.length == 0) return true
        if (s.length > t.length) return false

        var i = 0
        for ((j, _) in t.withIndex()) {
            if (i != s.length && s[i] == t[j]) i += 1
        }
        return if (i == s.length) true else false
    }
}

fun main() {
    val s = Solution()

    println(s.isSubsequence("abc", "ahdgbc"))
    println(s.isSubsequence("axc", "ahdgbc"))
    println(s.isSubsequence("", "abdcef"))
}