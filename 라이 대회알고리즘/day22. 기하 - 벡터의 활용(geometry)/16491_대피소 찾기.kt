import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*
import kotlin.math.max
import kotlin.math.min
import kotlin.system.exitProcess


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
    return (x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3)
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

    if (cross1 * cross2 <= 0.0 && cross3 * cross4 <= 0.0) {
        return true
    }
    return false
}

private val answer = IntArray(10) { - 1 }

private fun dfs(N: Int, robot: Array<LongArray>, home: Array<LongArray>, current: Int) {
    if (N <= current) {
        repeat(N) {
            println(answer[it]+1)
        }
        exitProcess(0)
    }

    // current 가 들어갈 home 을 정한다
    for (j in 0 until N) {
        if (j in answer) {
            continue
        }
        // 이미 home에 들어간 robot과 겹치는 선분이 되는지를 확인한다
        var check = true
        for (i in 0 until current) {
            if (intersect(robot[current][0], robot[current][1], home[j][0], home[j][1], robot[i][0], robot[i][1], home[answer[i]][0], home[answer[i]][1])) {
                check = false
                break
            }
        }
        if (check) {
            answer[current] = j
            dfs(N, robot, home, current+1)
            answer[current] = -1
        }
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    val N = br.readInt()
    val robot = Array(N) { LongArray(2) { -1L } }
    val home = Array(N) { LongArray(2) { -1L } }

    repeat(N) {
        robot[it] = br.readLongs()
    }
    repeat(N) {
        home[it] = br.readLongs()
    }

    dfs(N, robot, home, 0)
}}}
