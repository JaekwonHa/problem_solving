package day17.` 유니온 파인드(Union-Find)`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*


private fun BufferedReader.readInt(): Int {
    return readLine()!!.toInt()
}

private fun BufferedReader.readInts(): IntArray {
    val st = StringTokenizer(readLine())
    val result = IntArray(st.countTokens())
    for (i in 0 until st.countTokens()) {
        result[i] = st.nextToken().toInt()
    }
    return result
}

private val sb = StringBuilder()
private fun StringBuilder.println(text: String) {
    append(text + "\n")
}

private fun StringBuilder.println() {
    print(this)
}

private lateinit var p: IntArray
private lateinit var edges: Array<IntArray>
private lateinit var cutIndex: Array<IntArray>
private lateinit var cutCheck: BooleanArray


private tailrec fun find(n: Int): Int {
    if (p[n] < 0) {
        return n
    }
    p[n] = find(p[n])
    return p[n]
}

private fun union(a: Int, b: Int) {
    val rootA = find(a)
    val rootB = find(b)

    if (rootA == rootB) {
        return
    }
    p[rootB] += p[rootA]
    p[rootA] = rootB
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {

    val (N, M, Q) = readInts()
    p = IntArray(N+1) { -1 }
    edges = Array(M+1) { intArrayOf() }
    cutIndex = Array(Q+1) { intArrayOf() }
    cutCheck = BooleanArray(M+1) { false }

    repeat(M) {
        val (x, y) = readInts()
        edges[it+1] = intArrayOf(x, y)
    }
    repeat(Q) {
        val a = readInt()
        cutIndex[it] = edges[a]
        cutCheck[a] = true
    }

    for (i in 1 ..M) {
        if (cutCheck[i]) {
            continue
        }
        union(edges[i][0], edges[i][1])
    }

    var answer = 0L
    for (i in Q-1 downTo 0) {
        var (x, y) = cutIndex[i]
        if (find(x) != find(y)) {
            answer += (p[find(x)]) * (p[find(y)])
            union(x, y)
        }
    }
    println(answer)
}
