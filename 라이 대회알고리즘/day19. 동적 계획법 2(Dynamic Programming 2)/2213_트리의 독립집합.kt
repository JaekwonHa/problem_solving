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

private val DP = Array(10001) { IntArray(2) { -1 } }
private val edges = Array<MutableList<Int>>(10001) { mutableListOf() }
private var N = 0
private val path = mutableListOf<Int>()
private val visit = BooleanArray(10001)

private fun dfs(numbers: IntArray, current: Int, parent: Int) {

    for (i in 0 until edges[current].size) {
        if (edges[current][i] == parent) {
            continue
        }
        dfs(numbers, edges[current][i], current)
    }

    DP[current][0] = 0
    DP[current][1] = numbers[current-1]

    for (i in 0 until edges[current].size) {
        if (edges[current][i] == parent) {
            continue
        }
        DP[current][0] += max(DP[edges[current][i]][0], DP[edges[current][i]][1])
        DP[current][1] += DP[edges[current][i]][0]
    }
}

private fun trace(current: Int, parent: Int) {
    if (DP[current][1] > DP[current][0] && !visit[parent]) {
        path.add(current)
        visit[current] = true
    }

    for (i in 0 until edges[current].size) {
        if (edges[current][i] == parent) {
            continue
        }
        trace(edges[current][i], current)
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    N = br.readInt()
    val numbers = br.readInts()

    for (i in 0 until N-1) {
        val (a, b) = br.readInts()
        edges[a].add(b)
        edges[b].add(a)
    }

    dfs(numbers, 1, 0)
    bw.println(max(DP[1][0], DP[1][1]))

    trace(1, 0)
    path.sort()

    bw.println(path.joinToString(" "))
}}}
