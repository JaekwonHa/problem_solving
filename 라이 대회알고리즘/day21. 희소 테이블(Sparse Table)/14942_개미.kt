import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*
import kotlin.collections.ArrayDeque
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

private val N = 100000
private val MAX_M = 30
private val initEdges = Array(N+1) { mutableListOf<Pair<Int, Long>>() }
private val edges = Array(N+1) { mutableListOf<Pair<Int, Long>>() }
private val sparseTable = Array(N+1) { Array<Pair<Int, Long>>(MAX_M+1) { 0 to 0L } }

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    var n = br.readInt()
    val numbers = IntArray(n)
    for (i in 0 until n) {
        numbers[i] = br.readInt()
    }
    for (i in 0 until n-1) {
        val (a, b, c) = br.readInts()
        initEdges[a].add(b to c.toLong())
        initEdges[b].add(a to c.toLong())
    }

    //step1. BFS로 경로를 만든다
    val q = ArrayDeque<Pair<Int, Long>>()
    val visit = BooleanArray(n+1) { false }
    q.add(1 to 0)
    visit[1] = true

    while(q.isNotEmpty()) {
        repeat(q.size) {
            val (current, cost1) = q.removeFirst()
            for ((next, cost2) in initEdges[current]) {
                if (!visit[next]) {
                    visit[next] = true
                    q.add(next to cost2)
                    edges[next].add(current to cost2)
                }
            }
        }
    }

    //step2. sparse table 구성
    for (i in 2..n) {
        sparseTable[i][0] = (edges[i][0].first to edges[i][0].second)
    }
    for (j in 1..MAX_M) {
        for (i in 2..n) {
            val midNode = sparseTable[i][j-1].first
            val midCost = sparseTable[i][j-1].second

            val startNode = sparseTable[midNode][j-1].first
            val startCost = sparseTable[midNode][j-1].second

            sparseTable[i][j] = startNode to (startCost + midCost)
        }
    }

    //step3. 특정 노드까지의 거리를 sparse table로 조회한다
    bw.println("1")
    for (i in 2..n) {
        var x = i
        var cost = numbers[i-1].toLong()
        for (j in MAX_M downTo 0) {
            if (sparseTable[x][j].first != 0 && cost >= sparseTable[x][j].second) {
                val temp = x
                x = sparseTable[temp][j].first
                cost -= sparseTable[temp][j].second
            }
            if (cost <= 0 || x == 1) {
                break
            }
        }
        bw.println(x)
    }
}}}
