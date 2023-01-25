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

private fun BufferedReader.readDoubles(): DoubleArray {
    val st = StringTokenizer(this.readLine())
    val arr = DoubleArray(st.countTokens())
    for (i in 0 until st.countTokens()) {
        arr[i] = st.nextToken().toDouble()
    }
    return arr
}

private fun BufferedWriter.println(text: Any) {
    this.appendLine(text.toString())
}

private fun ccw(x1: Double, y1: Double, x2: Double, y2: Double, x3: Double, y3: Double): Double {
    return x1*y2 + x2*y3 + x3*y1 - (y1*x2 + y2*x3 + y3*x1)
}

private fun distance(x1: Double, y1: Double, x2: Double ,y2: Double): Double {
    return sqrt((x2-x1).pow(2) + (y2-y1).pow(2))
}

private fun dotProductForPoint(x1: Double, y1: Double, x2: Double, y2: Double, x3: Double, y3: Double): Double {
    val (P1P2_x, P1P2_y) = (x2-x1 to y2-y1)
    val (P1P3_x, P1P3_y) = (x3-x1 to y3-y1)
    return (P1P2_x * P1P3_x) + (P1P2_y * P1P3_y)
}

private fun crossProductForPoint(x1: Double, y1: Double, x2: Double, y2: Double, x3: Double, y3: Double): Double {
    val (P1P2_x, P1P2_y) = (x2-x1 to y2-y1)
    val (P1P3_x, P1P3_y) = (x3-x1 to y3-y1)
    return (P1P2_x * P1P3_y) - (P1P2_y * P1P3_x)
}

private fun perpendicular(x1: Double, y1: Double, x2: Double, y2: Double, x3: Double, y3: Double): Double {
    val dot1 = dotProductForPoint(x1, y1, x2, y2, x3, y3)
    val dot2 = dotProductForPoint(x2, y2, x1, y1, x3, y3)
    if (dot1 * dot2 > 0) {
//        return abs(crossProductForPoint(x3, y3, x1, y1, x2, y2) / distance(x1, y1, x2, y2))
        return abs(ccw(x3, y3, x1, y1, x2, y2) / distance(x1, y1, x2, y2))
    } else {
        return Double.MAX_VALUE
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    val (n, m) = br.readInts()
    val coordination = Array(n) { DoubleArray(4) }

    for (i in 0 until n) {
        val(a, b, c, d) = br.readDoubles()
        coordination[i][0] = a
        coordination[i][1] = b
        coordination[i][2] = c
        coordination[i][3] = d
    }

    var answer = Double.MAX_VALUE
    for (i in 0 until m) {
        val (x3, y3, x4, y4) = br.readDoubles()

        for ((x1, y1, x2, y2) in coordination) {
            answer = min(answer, distance(x1, y1, x3, y3))
            answer = min(answer, distance(x1, y1, x4, y4))
            answer = min(answer, distance(x2, y2, x3, y3))
            answer = min(answer, distance(x2, y2, x4, y4))

            answer = min(answer, perpendicular(x1, y1, x2, y2, x3, y3))
            answer = min(answer, perpendicular(x1, y1, x2, y2, x4, y4))
            answer = min(answer, perpendicular(x3, y3, x4, y4, x1, y1))
            answer = min(answer, perpendicular(x3, y3, x4, y4, x2, y2))
        }
    }

    bw.println(String.format("%.15f", answer))
}}}
