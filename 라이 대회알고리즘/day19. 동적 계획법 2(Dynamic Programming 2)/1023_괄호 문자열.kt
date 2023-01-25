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

private val DP = Array(51) { Array(102) { LongArray(2) { -1L } } }
private val path = mutableListOf<Char>()

private fun dfs(N:Int, n: Int, op: Int, wrong: Int): Long {
    if (N == n) {
        if (wrong == 1 || op != 0) {
            DP[n][N+1+op][wrong] = 1
        } else {
            DP[n][N+1+op][wrong] = 0
        }
        return DP[n][N+1+op][wrong]
    }

    if (DP[n][N+1+op][wrong] != -1L) {
        return DP[n][N+1+op][wrong]
    }

    DP[n][N+1+op][wrong] = dfs(N, n+1, op+1, wrong)

    if (op > 0) {
        DP[n][N+1+op][wrong] += dfs(N, n+1, op-1, wrong)
    } else {
        DP[n][N+1+op][wrong] += dfs(N, n+1, op-1, 1)
    }
    return DP[n][N+1+op][wrong]
}

private fun trace(N: Int, n: Int, op: Int, wrong: Int, k: Long) {
    if (N == n) {
        return
    }

    val remain = DP[n+1][N+1+op+1][wrong]

    if (k <= remain) {
        path.add('(')
        trace(N, n+1, op+1, wrong, k)
    } else {
        if (wrong == 0 && op == 0) {
            path.add(')')
            trace(N, n+1, op-1, 1, k-remain)
        } else {
            path.add(')')
            trace(N, n+1, op-1, wrong, k-remain)
        }
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    val (N, K) = br.readLongs()

    if (dfs(N.toInt(), 0, 0, 0) <= K) {
        bw.println("-1")
    } else {
        trace(N.toInt(), 0, 0, 0, K+1)
        bw.println(path.joinToString(""))
    }
}}}
