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

private val DP = Array(32) { LongArray(32) { -1L } }
private val path = mutableListOf<Char>()

private fun binomial(n: Int, r: Int): Long {
    if (r == 0) {
        DP[n][r] = 1
    } else if (n == 0) {
        DP[n][r] = 1
    } else if (DP[n][r] == -1L){
        DP[n][r] = binomial(n-1, r-1) + binomial(n-1, r)
    }
    return DP[n][r]
}

private fun trace(n: Int, r: Int, k: Long) {
    if (r == 0) {
        repeat(n) {
            path.add('0')
        }
        return
    }
    if (n == 0) {
        return
    }
    val remain = binomial(n-1, r)

    if (k <= remain) {
        path.add('0')
        trace(n-1, r, k)
    } else {
        path.add('1')
        trace(n-1, r-1, k - remain)
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    val (N, L, I) = br.readLongs()

    trace(N.toInt(), L.toInt(), I)

    bw.println(path.joinToString(""))
}}}
