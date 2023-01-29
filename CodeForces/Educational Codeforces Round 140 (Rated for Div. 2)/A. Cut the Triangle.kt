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


fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    repeat(br.readInt()) {
        val temp = br.readLine()
        val (x1, y1) = br.readLongs()
        val (x2, y2) = br.readLongs()
        val (x3, y3) = br.readLongs()

        var checkX = false
        var checkY = false

        if (y1 == y2 || y2 == y3 || y3 == y1) {
            checkX = true
        }
        if (x1 == x2 || x2 == x3 || x3 == x1) {
            checkY = true
        }

        if (checkX && checkY) {
            bw.println("NO")
        } else {
            bw.println("YES")
        }
    }
}}}
