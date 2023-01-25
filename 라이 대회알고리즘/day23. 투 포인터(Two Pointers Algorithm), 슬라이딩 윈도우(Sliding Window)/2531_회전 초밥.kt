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

    val (N, d, k, c) = br.readInts()
    val dish = IntArray(N+k) { 0 }
    for (i in 0 until N) {
        dish[i] = br.readInt()
    }
    for (i in 0 until k) {
        dish[N+i] = dish[i]
    }

    val prefixSum = mutableMapOf<Int, Int>()
    prefixSum[c] = 99999

    for (i in 0 until k) {
        val id = dish[i]
        prefixSum[id] = prefixSum.getOrDefault(id, 0) + 1
    }

    var answer = prefixSum.keys.size
    var i = 0
    for (j in k until N+k) {
        val firstId = dish[i]
        prefixSum[firstId] = prefixSum[firstId]!! - 1
        if (prefixSum[firstId]!! == 0) {
            prefixSum.remove(firstId)
        }
        i += 1

        val id = dish[j]
        prefixSum[id] = prefixSum.getOrDefault(id, 0) + 1

        answer = max(answer, prefixSum.keys.size)
    }
    bw.println(answer)
}}}
