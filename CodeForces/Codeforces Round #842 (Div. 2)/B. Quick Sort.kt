import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*
import kotlin.collections.ArrayDeque


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
    repeat(br.readInt()) {
        val (n, k) = br.readInts()
        val numbers = br.readInts()

        var current = 1
        var reversedNumberCount = 0
        for (number in numbers) {
            if (number == current) {
                current += 1
            } else {
                reversedNumberCount += 1
            }
        }
        if (reversedNumberCount%k == 0) {
            bw.println(reversedNumberCount/k)
        } else {
            bw.println(reversedNumberCount/k + 1)
        }
    }
}}}
