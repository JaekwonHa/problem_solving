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

private data class Line(
    val x1: Double = 0.0,
    val y1: Double = 0.0,
    val x2: Double = 0.0,
    val y2: Double = 0.0
)

private lateinit var lines: Array<Line>
private lateinit var p: IntArray

private fun find(x: Int): Int {
    if (p[x] < 0) {
        return x
    }

    p[x] = find(p[x])
    return p[x]
}

private fun union(x: Int, y: Int) {
    val parent_x = find(x)
    val parent_y = find(y)

    if (parent_x != parent_y) {
        p[parent_x] += p[parent_y]
        p[parent_y] = parent_x
    }
}

private fun ccw(x1: Double, y1: Double, x2: Double, y2: Double, x3: Double, y3: Double): Double {
    return x1*y2 + x2*y3 + x3*y1 - (y1*x2 + y2*x3 + y3*x1)
}

private fun crossProductForPoint(x1: Double, y1: Double, x2: Double, y2: Double, x3: Double, y3: Double): Double {
    val (P1P2_x, P1P2_y) = (x2-x1 to y2-y1)
    val (P1P3_x, P1P3_y) = (x3-x1 to y3-y1)
    return (P1P2_x * P1P3_y) - (P1P2_y * P1P3_x)
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    val N = br.readInt()

    lines = Array(N) { Line() }
    p = IntArray(N) { -1 }

    for (i in 0 until N) {
        val (x1, y1, x2, y2) = br.readInts()
        lines[i] = Line(x1.toDouble(), y1.toDouble(), x2.toDouble(), y2.toDouble())
    }

    for (i in 0 until N) {
        val (x1, y1, x2, y2) = lines[i]
        for (j in 0 until N) {
            if (i == j) {
                continue
            }
            val (x3, y3, x4, y4) = lines[j]

            val cross1 = ccw(x1, y1, x2, y2, x3, y3)
            val cross2 = ccw(x1, y1, x2, y2, x4, y4)
            val cross3 = ccw(x3, y3, x4, y4, x1, y1)
            val cross4 = ccw(x3, y3, x4, y4, x2, y2)

            // 이 방식은 메모리 초과 발생
//            val cross1 = crossProductForPoint(x1, y1, x2, y2, x3, y3)
//            val cross2 = crossProductForPoint(x1, y1, x2, y2, x4, y4)
//            val cross3 = crossProductForPoint(x3, y3, x4, y4, x1, y1)
//            val cross4 = crossProductForPoint(x3, y3, x4, y4, x2, y2)

            // check overlapped
            // 네 점이 일직선 상에 존재하는 케이스
            // 겹치는 부분이 있는지를 최대, 최소 점이 상대 선분 사이에 위치하는지로 확인한다
            if (cross1 * cross2 == 0.0 && cross3 * cross4 == 0.0) {
                if (max(x1, x2) < min(x3, x4) || max(y1, y2) < min(y3, y4)) {
                    continue
                }
                if (max(x3, x4) < min(x1, x2) || max(y3, y4) < min(y1, y2)) {
                    continue
                }
                union(i, j)
                continue
            }

            if (cross1 * cross2 <= 0.0 && cross3 * cross4 <= 0.0) {
                union(i, j)
                continue
            }
        }
    }
    var answerSize = 0
    var answerValue = 0
    for (i in 0 until N) {
        if (p[i] < 0) {
            answerSize += 1
            answerValue = max(answerValue, -1 * p[i])
        }
    }
    bw.println(answerSize)
    bw.println(answerValue)
}}}
