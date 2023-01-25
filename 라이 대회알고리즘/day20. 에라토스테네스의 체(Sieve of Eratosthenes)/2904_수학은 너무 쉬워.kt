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
private val primeArray = mutableListOf<Int>()
private val primeFactorization = Array<MutableMap<Int, Int>>(101) { mutableMapOf() }

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
            primeArray.add(i)
        }
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    generatePrime()
    val n = br.readInt()
    var i = 0

    var answerGCD = 1
    var answerCount = 0
    val answerPrime = mutableMapOf<Int, Int>()
    for (number in br.readInts()) {
        var remain = number
        for (prime in primeArray) {
            if (number < prime) {
                break
            }
            if (remain%prime == 0) {
                var count = 0
                while (remain%prime == 0) {
                    count += 1
                    remain = remain / prime
                }
                primeFactorization[i][prime] = count
                if (answerPrime[prime] == null) {
                    answerPrime[prime] = count
                } else {
                    answerPrime[prime] = answerPrime[prime]!! + count
                }
            }
        }
        i += 1
    }
    for ((key, value) in answerPrime) {
        val count = value/n
        if (count != 0) {
            answerGCD *= key.toDouble().pow(count.toDouble()).toInt()
        }
        for (i in 0 until n) {
            val delta = max(count - (primeFactorization[i][key] ?: 0), 0)
            answerCount += delta
        }
    }

    bw.println("$answerGCD $answerCount")
}}}
