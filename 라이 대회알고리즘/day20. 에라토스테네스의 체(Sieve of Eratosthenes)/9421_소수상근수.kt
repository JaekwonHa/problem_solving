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

private val N = 1000000
private val isPrime = BooleanArray(N+1) { true }
private val DP = LongArray(N+1) { -1 }
private val isPrimeSanggenNumber = BooleanArray(N+1) { false }

private fun generatePrime() {
    isPrime[1] = false
    for (i in 4..N step 2) {
        isPrime[i] = false
    }
    for (i in 3 .. N) {
        for (j in i+i..N step i) {
            isPrime[j] = false
        }
    }
    for (i in 2..N) {
        if (isPrime[i]) {
        }
    }
}

private fun getSanggenNumber(i: Long): Long {
    var number = 0L
    for (j in 0 until i.toString().length) {
        number += (i.toString()[j].digitToInt()).toDouble().pow(2.0).toLong()
    }
    return number
}

private fun generateSanggenNumber() {
//    for (i in 1..N) {
//        DP[i] = getSanggenNumber(i.toLong())
//    }
    for (i in 1..N) {
        val visit = mutableSetOf<Long>()
        var next = i.toLong()
        visit.add(next)
        while (true) {
            next = getSanggenNumber(next)
//            if (N < next) {
//            } else {
//                next = DP[next.toInt()]
//            }
            if (next == 1L) {
                if (isPrime[i]) {
                    isPrimeSanggenNumber[i] = true
                }
                break
            }
            if (next in visit) {
                break
            }
            visit.add(next)
        }
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    generatePrime()
    generateSanggenNumber()
    val n = br.readInt()
    for (i in 7..n) {
        if (isPrimeSanggenNumber[i]) {
            bw.println(i.toString())
        }
    }
}}}
