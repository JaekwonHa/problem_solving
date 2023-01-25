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

private val N = 123456*2
private val isPrime = BooleanArray(N+1) { true }

private fun generatePrime() {
    for (i in 4..N step 2) {
        isPrime[i] = false
    }
    for (i in 3 .. N) {
        for (j in i+i..N step i) {
            isPrime[j] = false
        }
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    generatePrime()
    while (true) {
        val a = br.readInt()
        if (a == 0) {
            break
        }
        var answer = 0
        for (i in a+1..2 * a) {
            if (isPrime[i]) {
                answer += 1
            }
        }
        bw.println(answer)
    }
}}}
