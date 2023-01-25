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

private fun ccw(x1: Long, y1: Long, x2: Long, y2: Long, x3: Long, y3: Long): Long {
    return x1*y2 + x2*y3 + x3*y1 - (y1*x2 + y2*x3 + y3*x1)
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    val N = br.readInt()
    val coordi = Array<Pair<Long, Long>>(N) { 0L to 0L }
    for (i in 0 until N) {
        val (a, b) = br.readLongs()
        coordi[i] = a to b
    }
    var answer = 0L
    for (i in 1 until N-1) {
        answer += (ccw(coordi[0].first, coordi[0].second, coordi[i].first, coordi[i].second, coordi[i+1].first, coordi[i+1].second))
    }

//    val answer2 = abs(round((answer.toDouble()/2.0)*100)/100)
//    bw.println(String.format("%.2f", answer2))

    val answer2 = abs(answer.toDouble()/2.0)
//    bw.println("$answer2")

//    if (answer % 2 == 0L) {
//        bw.println("${abs(answer/2L)}.0")
//    } else {
//        bw.println("${abs(answer/2L)}.5")
//    }

//    val answer2 = abs(answer) / 2.0
    bw.println(String.format("%.1f", answer2))
}}}
