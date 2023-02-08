class Solution {
    fun isIsomorphic(s: String, t: String): Boolean {
        if (s.toCharArray().toSet().size != t.toCharArray().toSet().size) return false

        val hash: MutableMap<Char, Char> = mutableMapOf()
        for (i in 0 until s.length) {
            if (hash.contains(s[i]) && hash[s[i]] != t[i]) return false
            hash[s[i]] = t[i]
        }
        return true
    }
}

fun main() {
    val s = Solution()

    println(s.isIsomorphic("foo", "bar"))
    println(s.isIsomorphic("bacd", "baba"))
    println(s.isIsomorphic("paper", "title"))
}

