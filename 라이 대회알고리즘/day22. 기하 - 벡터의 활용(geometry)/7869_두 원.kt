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

private fun BufferedReader.readDouble(): Double {
    return this.readLine().toDouble()
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

private val direction = arrayOf(intArrayOf(1, 0), intArrayOf(-1, 0), intArrayOf(0, 1), intArrayOf(0, -1))
private val array = IntArray(1000) { -1 }
private val array2D = Array(1000) { IntArray(1000) { -1 } }


fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    val numbers = br.readDoubles()
    val x1 = numbers[0]
    val y1 = numbers[1]
    val r1 = numbers[2]
    val x2 = numbers[3]
    val y2 = numbers[4]
    val r2 = numbers[5]

    val d: Double = sqrt((x1-x2).pow(2) + (y1-y2).pow(2))

    if (r1+r2 <= d) {
        bw.println("0.000")
    } else if (abs(r1-r2) >= d) {
        bw.println(String.format("%.3f", min(r1,r2) * min(r1,r2) * PI))
    } else {
        val theta1 = acos( (r1*r1 + d*d - r2*r2) / (2*r1*d) )
        val theta2 = acos( (r2*r2 + d*d - r1*r1) / (2*r2*d) )
        val s1 = (r1*r1*theta1) - (r1*r1* sin(2*theta1)/2)
        val s2 = (r2*r2*theta2) - (r2*r2* sin(2*theta2)/2)

        bw.println(String.format("%.3f", s1+s2))
    }
}}}
