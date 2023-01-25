import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*


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

private val cache = BooleanArray(1000001) { true }

private fun generate(a: Long, b: Long) {
    var i = 2L
    var j = i*i
    while (true) {
        var step = j

        j = step*(a/step)
        while (j < a) {
            j += step
        }
        while (j <= b) {
            cache[(j-a).toInt()] = false
            j += step
        }
        i += 1L
        j = i*i

        if (b < j) {
            break
        }
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    val (a, b) = br.readLongs()

    generate(a, b)

    var answer = 0
    for (i in a..b) {
        if (cache[(i-a).toInt()]) {
            answer += 1
        }
    }
    bw.println(answer)
}}}
