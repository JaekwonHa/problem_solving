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

private val N = 100000
private val K = 100000
private val M = 1000000000
private val MAX_M = 30
private val cache = Array(MAX_M+1) { IntArray(K+1) { -1 } }

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    val (n, k, m) = br.readInts()
    val numbers = br.readInts()
    val movies = br.readInts()

    for (i in 1..k) {
        cache[0][i] = movies[i-1]
    }
    for (j in 1..MAX_M) {
        for (i in 1..k) {
            cache[j][i] = cache[j-1][ cache[j-1][i] ]
        }
    }

    val answer = IntArray(n)
    for (i in 0 until n) {
        var (x, minutes) = (numbers[i] to m-1)
        for (j in MAX_M downTo 0) {
            if (minutes >= (1 shl j)) {
                minutes -= (1 shl j)
                x = cache[j][x]
            }
        }
        answer[i] = x
    }
    bw.println(answer.joinToString(" "))
}}}
