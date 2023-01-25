import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*
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

private val K_MAX = 1_000_000_000_000_000_000L
private val DP = Array(101) { LongArray(2) { -1 } }
private val path = mutableListOf<Char>()
private var K = 0L
private var N = 0

private fun dfs(n: Int, prev: Int): Long {
    if (n == 0) {
        DP[n][prev] = 1L
        return DP[n][prev]
    }

    if (DP[n][prev] != -1L) {
        return DP[n][prev]
    }

    DP[n][prev] = dfs(n-1, 0)
    if (prev == 0) {
        DP[n][prev] += dfs(n-1, 1)
    }
//    DP[n][prev] = min(DP[n][prev], K_MAX)
    return DP[n][prev]
}

private fun trace(n: Int, prev: Int, k: Long) {
    if (n == 0) {
        return
    }

    val remain = DP[n-1][0]

    if (k <= remain) {
        if (path.size > 0) {
            path.add('0')
        }
        trace(n-1, 0, k)
    } else if (prev == 0) {
        path.add('1')
        trace(n-1, 1, k-remain)
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    K = br.readLong()

    dfs(100, 0)

    for (n in 1..100) {
        if (K < DP[n][0] + DP[n][1]) {
            N = n
            break
        }
    }

    trace(N+1, 0, K+1)
//    val answer = path.subList(path.indexOfFirst { it == '1' }, path.size)
    bw.println(path.joinToString(""))
}}}
