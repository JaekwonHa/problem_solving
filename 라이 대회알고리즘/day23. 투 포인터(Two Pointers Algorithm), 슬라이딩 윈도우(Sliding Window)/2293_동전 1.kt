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
    val (N, K) = br.readInts()
    val DP = Array(2) { IntArray(K+1) { 0 } }

    for (i in 0 until N) {
        val coin = br.readInt()

        if (i == 0) {
            for (j in 0 .. K step coin) {
                DP[0][j] = 1
            }
            continue
        }

        for (money in 0 .. K) {
            var count = 0
            while (coin*count <= K) {
                if (money-(coin*count) >= 0) {
                    DP[1][money] += DP[0][money-(coin*count)]
                }
                count += 1
            }
        }
        DP[0] = DP[1]
        DP[1] = IntArray(K+1) { 0 }
    }
    bw.println(DP[0][K])
}}}
