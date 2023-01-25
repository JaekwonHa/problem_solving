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

private val DP = Array(51) { LongArray(51) { -1 } }
private val path = mutableListOf<Char>()

private tailrec fun dfs(N:Int, n: Int, op: Int): Long {
    if (N == n) {
        if (op == 0) {
            return 1
        } else {
            return 0
        }
    }

    if (DP[n][op] != -1L) {
        return DP[n][op]
    }

    DP[n][op] = dfs(N, n+1, op+1)
    if (op > 0) {
        DP[n][op] += dfs(N, n+1, op-1)
    }
    return DP[n][op]
}

private tailrec fun trace(N: Int, n: Int, op: Int, k: Long) {
    if (N == n) {
        return
    }

    val remain = DP[n+1][op+1]

    if (k <= remain) {
        path.add('(')
        trace(N, n+1, op+1, k)
    } else if(op > 0) {
        path.add(')')
        trace(N, n+1, op-1, k-remain)
    }
}


fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    val (N, K) = br.readLongs()

    dfs(N.toInt(), 0, 0)

    if (DP[0][0] <= K) {
        bw.println("-1")
    } else {
        trace(N.toInt(), 0, 0, K+1)
        bw.println(path.joinToString(""))
    }
}}}
