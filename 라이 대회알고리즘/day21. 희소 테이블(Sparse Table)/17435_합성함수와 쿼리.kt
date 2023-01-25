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

private val N = 200000
private val MAX_D = 19
private lateinit var numbers: IntArray

private val cache = Array(N+1) { IntArray(MAX_D+1) { -1 } }
private fun generate(m: Int) {
    for (i in 1..m) {
        cache[i][0] = numbers[i-1]
    }

    for (j in 1..MAX_D) {
        for (i in 1..m) {
            cache[i][j] = cache[ cache[i][j-1] ][j-1]
        }
    }
}


fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    val m = br.readInt()
    numbers = br.readInts()
    generate(m)

    val q= br.readInt()
    for (i in 0 until q) {
        var (n, x) = br.readInts()

        for (j in MAX_D-1 downTo 0) {
            if (n >= (1 shl j)) {
                n -= (1 shl j)
                x = cache[x][j]
            }
        }
        bw.println(x)
    }
}}}
