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
    val result = (x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3)
    if (result < 0L) {
        return -1
    }
    if (result > 0L) {
        return 1
    }
    return 0
}

private fun intersect(x1: Long, y1: Long, x2: Long, y2: Long, x3: Long, y3: Long, x4: Long, y4: Long): Boolean {
    val cross1 = ccw(x1, y1, x2, y2, x3, y3)
    val cross2 = ccw(x1, y1, x2, y2, x4, y4)
    val cross3 = ccw(x3, y3, x4, y4, x1, y1)
    val cross4 = ccw(x3, y3, x4, y4, x2, y2)

    if (cross1 * cross2 < 0.0 && cross3 * cross4 < 0.0) {
        return true
    }
    return false
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    val (x1, y1, x2, y2) = br.readLongs()
    val (x3, y3, x4, y4) = br.readLongs()

    if (intersect(x1, y1, x2, y2, x3, y3, x4, y4)) {
        bw.println("1")
    } else {
        bw.println("0")
    }
}}}
