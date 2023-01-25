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
    repeat(br.readInt()) {
        val N = br.readInt()

        val matrix = MutableList<Int>(N*N) { 0 }
        var smaall = 1
        var large = N*N
        for (i in 0 until N*N) {
            if (i%2 == 0) {
                matrix[i] = smaall
                smaall += 1
            } else {
                matrix[i] = large
                large -= 1
            }
        }

        for (i in 0 until N) {
            val start = i*N
            if (i%2 == 0) {
                bw.println(matrix.subList(start, start+N).joinToString(" "))
            } else {
                bw.println(matrix.subList(start, start+N).reversed().joinToString(" "))
            }
        }
    }
}}}
