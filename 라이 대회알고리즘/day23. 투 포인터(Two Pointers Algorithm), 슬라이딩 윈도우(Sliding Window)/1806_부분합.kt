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

    val (N, M) = br.readInts()
    val numbers = br.readLongs()

    var i = 0
    var m = 0L
    var answer = Int.MAX_VALUE
    for (j in 0 until N) {
        m += numbers[j]

        if (M <= m) {
            while (M <= (m-numbers[i]) && i < j) {
                m -= numbers[i]
                i += 1
            }
            answer = min(answer, j-i+1)
        }
    }
    if (answer == Int.MAX_VALUE) {
        bw.println("0")
    } else {
        bw.println(answer)
    }
}}}
