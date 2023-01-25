import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*


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

private val K_MAX = 2147483647L
private val DP = Array(11) { Array(221) { LongArray(221) { -1L } } }
private val path = mutableListOf<Int>()

private fun dfs(N: Int, M: Int, pos: Int, prev: Int, m: Int): Long {
    if (pos == N) {
        if (m == 0) {
            DP[pos][prev][m] = 1L
        } else {
            DP[pos][prev][m] = 0L
        }
        return DP[pos][prev][m]
    }

    if (DP[pos][prev][m] != -1L) {
        return DP[pos][prev][m]
    }

    DP[pos][prev][m] = 0
    for (j in prev..M) {
        if (m - j < 0) {
            break
        }
        DP[pos][prev][m] += dfs(N, M, pos+1, j, m-j)
        if (K_MAX < DP[pos][prev][m]) {
            DP[pos][prev][m] = K_MAX
        }
    }
    return DP[pos][prev][m]
}

private fun trace(N: Int, M: Int, pos: Int, prev: Int, m: Int, k: Long) {
    if (pos == N) {
        return
    }

    var remain = 0L
    var remainK = k
    for (j in prev..M) {
        if (m - j < 0) {
            break
        }
        remain = DP[pos+1][j][m-j]
        if (remainK <= remain) {
            path.add(j)
            trace(N, M, pos+1, j, m-j, remainK)
            break
        }
        remainK -= remain
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    val (N, M, K) = br.readLongs()

    if (dfs(N.toInt(), M.toInt(), 0, 1, M.toInt()) < K) {
        bw.println("-1")
    } else {
        trace(N.toInt(), M.toInt(), 0, 1, M.toInt(), K)
        bw.println(path.joinToString(" "))
    }
}}}
