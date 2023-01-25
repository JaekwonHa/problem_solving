import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*
import kotlin.math.max
import kotlin.math.min


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

    data class Line(var x1: Long = 0L, var y1: Long = 0L, var x2: Long = 0L, var y2: Long = 0L)

    fun ccw(x1: Long, y1: Long, x2: Long, y2: Long, x3: Long, y3: Long): Long {
        return (x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3)
    }

    fun intersect(line1: Line, line2: Line): Boolean {
        val cross1 = ccw(line1.x1, line1.y1, line1.x2, line1.y2, line2.x1, line2.y1)
        val cross2 = ccw(line1.x1, line1.y1, line1.x2, line1.y2, line2.x2, line2.y2)
        val cross3 = ccw(line2.x1, line2.y1, line2.x2, line2.y2, line1.x1, line1.y1)
        val cross4 = ccw(line2.x1, line2.y1, line2.x2, line2.y2, line1.x2, line1.y2)

        if (cross1 * cross2 == 0L && cross3 * cross4 == 0L) {
            if (max(line1.x1, line1.x2) < min(line2.x1, line2.x2) || max(line1.y1, line1.y2) < min(line2.y1, line2.y2)) {
                return false
            }
            if (max(line2.x1, line2.x2) < min(line1.x1, line1.x2) || max(line2.y1, line2.y2) < min(line1.y1, line1.y2)) {
                return false
            }
            return true
        }

        if (cross1 * cross2 <= 0.0 && cross3 * cross4 <= 0.0) {
            return true
        }
        return false
    }

    fun intersectCornerOfRectangle(line1: Line, line2: Line): Boolean {
        val cross1 = ccw(line1.x1, line1.y1, line1.x2, line1.y2, line2.x1, line2.y1)
        val cross2 = ccw(line1.x1, line1.y1, line1.x2, line1.y2, line2.x2, line2.y2)
        val cross3 = ccw(line2.x1, line2.y1, line2.x2, line2.y2, line1.x1, line1.y1)
        val cross4 = ccw(line2.x1, line2.y1, line2.x2, line2.y2, line1.x2, line1.y2)

        if (cross1 * cross2 == 0L && cross3 * cross4 <= 0L) {
            return true
        }
        return false
    }

    fun intersectLineOfRectangle(line1: Line, line2: Line): Boolean {
        val cross1 = ccw(line1.x1, line1.y1, line1.x2, line1.y2, line2.x1, line2.y1)
        val cross2 = ccw(line1.x1, line1.y1, line1.x2, line1.y2, line2.x2, line2.y2)
        val cross3 = ccw(line2.x1, line2.y1, line2.x2, line2.y2, line1.x1, line1.y1)
        val cross4 = ccw(line2.x1, line2.y1, line2.x2, line2.y2, line1.x2, line1.y2)

        if (cross1 * cross2 < 0L && cross3 * cross4 <= 0L) {
            return true
        }
        return false
    }

    val T = br.readInt()
    for (i in 0 until T) {
        val (xmin, ymin, xmax, ymax) = br.readLongs()
        val (x1, y1, x2, y2) = br.readLongs()

        val line1 = Line(xmin, ymin, xmin, ymax)
        val line2 = Line(xmin, ymax, xmax, ymax)
        val line3 = Line(xmax, ymin, xmax, ymax)
        val line4 = Line(xmin, ymin, xmax, ymin)

        val line0 = Line(x1, y1, x2, y2)

        // case1. 선분0과 직사각형 선분1,2,3,4가 서로 교차하는 포인트가 하나도 없는지를 확인
        if (!intersect(line0, line1) && !intersect(line0, line2) && !intersect(line0, line3) && !intersect(line0, line4)) {
            bw.println("0")
            continue
        }
        // case2. 선분0이 가로선/세로선이냐에 따라서 무수히 겹치는 구간이 있는지 확인
        // 세로선
        if (line0.x1 == line0.x2 && (line0.x1 == xmin || line0.x1 == xmax)) {
            if (max(line0.y1, line0.y2) <= ymin || ymax <= min(line0.y1, line0.y2)) {
            } else {
                bw.println("4")
                continue
            }
        }
        // 가로선
        if (line0.y1 == line0.y2 && (line0.y1 == ymin || line0.y2 == ymax)) {
            if (max(line0.x1, line0.x2) <= xmin || xmax <= min(line0.x1, line0.x2)) {
            } else {
                bw.println("4")
                continue
            }
        }
        var answer = 0
        // case3. 모서리가 교차하는 구간 확인
        answer += if(intersectCornerOfRectangle(line0, line1)) 1 else 0
        answer += if(intersectCornerOfRectangle(line0, line2)) 1 else 0
        answer += if(intersectCornerOfRectangle(line0, line3)) 1 else 0
        answer += if(intersectCornerOfRectangle(line0, line4)) 1 else 0
        answer /= 2

        // case4. 선분끼리 교차하는 구간 확인
        answer += if(intersectLineOfRectangle(line0, line1)) 1 else 0
        answer += if(intersectLineOfRectangle(line0, line2)) 1 else 0
        answer += if(intersectLineOfRectangle(line0, line3)) 1 else 0
        answer += if(intersectLineOfRectangle(line0, line4)) 1 else 0

        bw.println(answer)
    }
}}}
