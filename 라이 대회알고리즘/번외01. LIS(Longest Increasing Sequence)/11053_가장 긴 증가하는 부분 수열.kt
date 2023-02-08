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

private val direction = arrayOf(intArrayOf(1, 0), intArrayOf(-1, 0), intArrayOf(0, 1), intArrayOf(0, -1))
private val array = IntArray(1000) { -1 }
private val array2D = Array(1000) { IntArray(1000) { -1 } }

private fun step1(N: Int, numbers: IntArray): Int {
    val DP = IntArray(N) { 1 }

    var answer = 1
    for (i in 0 until N) {
        for (j in i-1 downTo 0) {
            if (numbers[j] < numbers[i]) {
                DP[i] = max(DP[i], DP[j] + 1)
            }
        }
        answer = max(answer, DP[i])
    }
    return answer
}


fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    val N = br.readInt()
    val numbers = br.readInts()

    bw.println(step1(N, numbers))
}}}
