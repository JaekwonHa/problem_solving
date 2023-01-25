import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*
import kotlin.collections.ArrayDeque
import kotlin.math.*


private fun BufferedReader.readInt(): Int {
    return this.readLine().toInt()
}

private fun BufferedReader.readInts(): IntArray {
    val st = StringTokenizer(this.readLine())
    val arr = IntArray(st.countTokens())
    for (i in 0 until st.countTokens()) {
        arr[i] = st.nextToken().toInt()
    }
    return arr
}

private fun BufferedReader.readLong(): Long {
    return this.readLine().toLong()
}

private fun BufferedReader.readLongs(): LongArray {
    val st = StringTokenizer(this.readLine())
    val arr = LongArray(st.countTokens())
    for (i in 0 until st.countTokens()) {
        arr[i] = st.nextToken().toLong()
    }
    return arr
}

private fun BufferedWriter.println(text: Any) {
    this.appendLine(text.toString())
}

private val DP = Array(10001) { IntArray(10) { -1 } }

private var N = 0
private var start = ""
private var end = ""
private lateinit var visit: MutableSet<String>
private val path = mutableListOf<Int>()

private fun dfs(digit: Int, offset: Int): Int {
    if (digit == N) {
        DP[digit][offset] = 0
        return 0
    }

    if (DP[digit][offset] != -1) {
        return DP[digit][offset]
    }

    val currentDigit = (start[digit].digitToInt() + offset)%10
    val diff = ((end[digit].digitToInt() - currentDigit) + 10)%10

    // 왼쪽으로 회전
    val left = dfs(digit+1, (offset+diff)%10) + (diff)

    // 오른쪽으로 회전
    val right = dfs(digit+1, offset) + (10-diff)

    DP[digit][offset] = min(left, right)
    return DP[digit][offset]
}

private fun trace(digit: Int, offset: Int) {
    if (digit == N) {
        return
    }
    val currentDigit = (start[digit].digitToInt() + offset)%10
    val diff = ((end[digit].digitToInt() - currentDigit) + 10)%10

    val left = DP[digit+1][(offset+diff)%10] + (diff)
    val right = DP[digit+1][offset] + (10-diff)

    if (left < right) {
        path.add(diff)
        trace(digit+1, (offset+diff)%10)
    } else {
        path.add(diff-10)
        trace(digit+1, offset)
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    N = br.readInt()
    start = br.readLine()!!
    end = br.readLine()!!

    dfs(0, 0)

    bw.println(DP[0][0])

    trace(0, 0)

    for (i in 0 until N) {
        bw.println("${i+1} ${path[i]}")
    }
}}}
