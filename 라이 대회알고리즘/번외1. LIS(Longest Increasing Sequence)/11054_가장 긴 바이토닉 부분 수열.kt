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

private fun step1(N: Int, numbers: IntArray): Int {
    val DP = Array(N) { IntArray(2) { 0 } }
    var answer = 0
    DP[0][0] = 1
    DP[0][1] = 1
    for (i in 1 until N) {
        for (j in i-1 downTo 0) {
            if (numbers[j] < numbers[i]) {
                DP[i][0] = max(DP[i][0], DP[j][0] + 1)
            }
            if (numbers[j] > numbers[i]) {
                DP[i][1] = max(DP[i][1], DP[j][0] + 1)
                DP[i][1] = max(DP[i][1], DP[j][1] + 1)
            }
        }
        answer = max(answer, DP[i][0])
        answer = max(answer, DP[i][1])
    }
    return answer
}

private fun step2(N: Int, numbers: IntArray): Int {
    val DP1 = IntArray(N) { 1 }
    val DP2 = IntArray(N) { 1 }
    var answer = 0

    for (i in 0 until N) {
        for (j in i-1 downTo 0) {
            if (numbers[j] < numbers[i]) {
                DP1[i] = max(DP1[i], DP1[j]+1)
            }
        }
    }
    for (i in N-1 downTo 0) {
        for (j in i+1 until N) {
            if (numbers[i] > numbers[j]) {
                DP2[i] = max(DP2[i], DP2[j]+1)
            }
        }
    }
    for (i in 0 until N) {
        answer = max(answer, DP1[i] + DP2[i] - 1)
    }
    return answer
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    val N = br.readInt()
    val numbers = br.readInts()

    bw.println(step2(N, numbers))
}}}
