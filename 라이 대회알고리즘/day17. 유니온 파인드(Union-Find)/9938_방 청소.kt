package day17.` 유니온 파인드(Union-Find)`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*


private fun BufferedReader.readInt(): Int {
    return read()
}

private fun BufferedReader.readInts(): IntArray {
    val st = StringTokenizer(readLine())
    val result = IntArray(st.countTokens())
    for (i in 0 until st.countTokens()) {
        result[i] = st.nextToken().toInt()
    }
    return result
}


private val p = IntArray(300001) { -1 }
private val sb = StringBuilder()

private tailrec fun find(n: Int): Int {
    if (p[n] <= 0) {
        return n
    }
    p[n] = find(p[n])
    return p[n]
}

private fun union(a: Int, b: Int) {
    val rootA = find(a)
    val rootB = find(b)

    if (rootA == rootB) {
        if (p[rootA.coerceAtMost(rootB)] <= -1) {
            p[rootA.coerceAtMost(rootB)] += 1
            sb.append("LADICA\n")
        } else {
            sb.append("SMECE\n")
        }
    } else {
        if (rootA < rootB) {
            p[rootA] += p[rootB]
            p[rootB] = rootA
        } else {
            p[rootB] += p[rootA]
            p[rootA] = rootB
        }
        if (p[rootA.coerceAtMost(rootB)] <= -1) {
            p[rootA.coerceAtMost(rootB)] += 1
            sb.append("LADICA\n")
        } else {
            sb.append("SMECE\n")
        }
    }
}


fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (N, L) = readInts()
    repeat(N) {
        val (a, b) = readInts()
        union(a, b)
    }
    print(sb)
}
