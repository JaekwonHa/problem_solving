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

private val N = 4000000
private val primeList = mutableListOf<Int>()
private val sieveOfEratosthenes = BooleanArray(N+1) { true }
private fun makeSieve() {
    for (i in 4 .. N step 2) {
        sieveOfEratosthenes[i] = false
    }
    for (i in 3 .. N) {
        for (j in i+i .. N step i) {
            sieveOfEratosthenes[j] = false
        }
    }
    for (i in 2 .. N) {
        if (sieveOfEratosthenes[i]) {
            primeList.add(i)
        }
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    makeSieve()
    val M = br.readInt()

    var i = 0
    var m = 0
    var answer = 0
    for (j in 0 until primeList.size) {
        m += primeList[j]
        while (M < m && i < j) {
            m -= primeList[i]
            i += 1
        }
        if (m == M) {
            answer += 1
        }
    }
    bw.println(answer)
}}}
