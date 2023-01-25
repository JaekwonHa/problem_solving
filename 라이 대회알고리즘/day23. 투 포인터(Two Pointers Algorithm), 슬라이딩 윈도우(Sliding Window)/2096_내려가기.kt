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

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    val N = br.readInt()

    val DP = Array(2) { IntArray(3) { 0 } }

    for (i in 0 until N) {
        val (a, b, c) = br.readInts()

        var aa = max(DP[0][0], DP[0][1]) + a
        var bb = DP[0].max() + b
        var cc = max(DP[0][1], DP[0][2]) + c

        DP[0][0] = aa
        DP[0][1] = bb
        DP[0][2] = cc

        aa = min(DP[1][0], DP[1][1]) + a
        bb = DP[1].min() + b
        cc = min(DP[1][1], DP[1][2]) + c

        DP[1][0] = aa
        DP[1][1] = bb
        DP[1][2] = cc
    }

    bw.println("${DP[0].max()} ${DP[1].min()}")
}}}
