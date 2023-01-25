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

private val N = 10000000
private val isPrime = BooleanArray(N+1) { true }
private val primeArray = mutableListOf<Long>()

private fun generatePrime() {
    isPrime[1] = false
    for (i in 4..N step 2) {
        isPrime[i] = false
    }
    for (i in 3..N) {
        for (j in i + i..N step i) {
            isPrime[j] = false
        }
    }
    for (i in 2..N) {
        if (isPrime[i]) {
            primeArray.add(i.toLong())
        }
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    generatePrime()
    val (a, b) = br.readLongs()

    var answer = 0L

    for (prime in primeArray) {
        var next = prime
        while (true) {
            next = next*prime
            if (b < next || next % prime != 0L) {
                break
            }
            if (a <= next && next <= b) {
                answer += 1L
            }
        }
    }
    bw.println(answer.toString())
}}}
