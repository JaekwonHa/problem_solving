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

    if (cross1 * cross2 == 0L && cross3 * cross4 == 0L) {
        if (max(x1, x2) < min(x3, x4) || max(y1, y2) < min(y3, y4)) {
            return false
        }
        if (max(x3, x4) < min(x1, x2) || max(y3, y4) < min(y1, y2)) {
            return false
        }
        return true
    }

    if (cross1 * cross2 <= 0L && cross3 * cross4 <= 0L) {
        return true
    }
    return false
}

private fun intersectClosed(x1: Long, y1: Long, x2: Long, y2: Long, x3: Long, y3: Long, x4: Long, y4: Long): Boolean {
    val cross1 = ccw(x1, y1, x2, y2, x3, y3)
    val cross2 = ccw(x1, y1, x2, y2, x4, y4)
    val cross3 = ccw(x3, y3, x4, y4, x1, y1)
    val cross4 = ccw(x3, y3, x4, y4, x2, y2)

    if (cross1 * cross2 < 0L && cross3 * cross4 < 0L) {
        return true
    }
    return false
}

private fun getIntersectPoint(x1: Long, y1: Long, x2: Long, y2: Long, x3: Long, y3: Long, x4: Long, y4: Long): DoubleArray {
    // http://www.gisdeveloper.co.kr/?p=89
    val under = (y4-y3) * (x2-x1) - (x4-x3) * (y2-y1)

    val _t = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)
    val _s = (x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)

    val t = _t.toDouble() / under.toDouble()
    val s = _s.toDouble() / under.toDouble()

    val x = x1 + t * (x2 - x1).toDouble()
    val y = y1 + t * (y2 - y1).toDouble()

    return doubleArrayOf(x, y)
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    val (x1, y1, x2, y2) = br.readLongs()
    val (x3, y3, x4, y4) = br.readLongs()

    if (intersect(x1, y1, x2, y2, x3, y3, x4, y4)) {
        bw.println("1")
        var check = true

        val cross1 = ccw(x1, y1, x2, y2, x3, y3)
        val cross2 = ccw(x1, y1, x2, y2, x4, y4)
        val cross3 = ccw(x3, y3, x4, y4, x1, y1)
        val cross4 = ccw(x3, y3, x4, y4, x2, y2)

        // 4개의 점이 일직선 상에 존재할때
        if (cross1 == 0L && cross2 == 0L && cross3 == 0L && cross4 == 0L) {
            if ((x1 to y1) == (x3 to y3)) {
                if (x2 in min(x3, x4)..max(x3, x4) && y2 in min(y3, y4)..max(y3, y4)) {

                } else if (x4 in min(x1, x2)..max(x1, x2) && y4 in min(y1, y2)..max(y1, y2)) {

                } else {
                    bw.println("$x1 $y1")
                }
            }
            else if ((x1 to y1) == (x4 to y4)) {
                if (x2 in min(x3, x4)..max(x3, x4) && y2 in min(y3, y4)..max(y3, y4)) {

                } else if (x3 in min(x1, x2)..max(x1, x2) && y3 in min(y1, y2)..max(y1, y2)) {

                } else {
                    bw.println("$x1 $y1")
                }
            }
            else if ((x2 to y2) == (x3 to y3)) {
                if (x1 in min(x3, x4)..max(x3, x4) && y1 in min(y3, y4)..max(y3, y4)) {

                } else if (x4 in min(x1, x2)..max(x1, x2) && y4 in min(y1, y2)..max(y1, y2)) {

                } else {
                    bw.println("$x2 $y2")
                }
            }
            else if ((x2 to y2) == (x4 to y4)) {
                if (x1 in min(x3, x4)..max(x3, x4) && y1 in min(y3, y4)..max(y3, y4)) {

                } else if (x3 in min(x1, x2)..max(x1, x2) && y3 in min(y1, y2)..max(y1, y2)) {

                } else {
                    bw.println("$x2 $y2")
                }
            }
        } else {
            val intersectPoint = getIntersectPoint(x1, y1, x2, y2, x3, y3, x4, y4)
            bw.println(String.format("%.14f %.14f", intersectPoint[0], intersectPoint[1]))
        }
    } else {
        bw.println("0")
    }
}}}
