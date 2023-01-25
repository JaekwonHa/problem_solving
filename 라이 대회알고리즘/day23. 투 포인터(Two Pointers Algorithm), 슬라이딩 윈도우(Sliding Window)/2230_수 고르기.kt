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


fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    val (N, M) = br.readLongs()
    var numbers = LongArray(N.toInt()) { 0L }
    for (i in 0 until N) {
        numbers[i.toInt()] = br.readLong()
    }

    numbers.sort()

    var i = 0
    var m = Long.MAX_VALUE

    if (M == 0L) {
        bw.println(M)
    } else {
        for (j in 0 until N.toInt()) {
            if (M <= numbers[j] - numbers[i]) {
                while (M <= numbers[j] - numbers[i+1] && i < j) {
                    i += 1
                }
                m = min(m, numbers[j] - numbers[i])
            }
        }
        bw.println(m)
    }
}}}
