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

private val DP = Array(201) { LongArray(101) { -1L } }
private val path = mutableListOf<Char>()

private fun dfs(n: Int, m: Int): Long {
    if (n == 0 || m == 0) {
        DP[n][m] = 1
        return 1
    }
    if (DP[n][m] != -1L) {
        return DP[n][m]
    }

    if (m == 0) {
        DP[n][m] = dfs(n-1, m)
    } else if (n == 0) {
        DP[n][m] = dfs(n, m-1)
    } else {
        val a = dfs(n-1, m)
        val z = dfs(n, m-1)
        DP[n][m] = a + z
    }
    if (DP[n][m] > 1_000_000_000L) {
        DP[n][m] = 1_000_000_000L
    }
    return DP[n][m]
}

private fun trace(n: Int, m: Int, k: Long) {
    if (m == 0) {
        repeat(n) {
            path.add('a')
        }
        return
    }
    if (n == 0) {
        repeat(m) {
            path.add('z')
        }
        return
    }
    if (k <= DP[n-1][m]) {
        path.add('a')
        trace(n-1, m, k)
    } else {
        path.add('z')
        trace(n, m-1, k-DP[n-1][m])
    }
}

private fun binomial(n: Int, r: Int): Long {
    if (r == 0 || n == r) {
        DP[n][r] = 1
    } else if (DP[n][r] == -1L) {
        DP[n][r] = binomial(n-1, r-1) + binomial(n-1, r)
    }
    if (DP[n][r] > 1_000_000_000L) {
        DP[n][r] = 1_000_000_000L
    }
    return DP[n][r]
}

private fun binomialTrace(n: Int, r: Int, k: Long) {
    if (r == 0) {
        repeat(n) {
            path.add('z')
        }
        return
    }
    if (n == r) {
        repeat(r) {
            path.add('a')
        }
        return
    }

    val remain = binomial(n-1, r-1)

    if (k <= remain) {
        path.add('a')
        binomialTrace(n-1, r-1, k)
    } else {
        path.add('z')
        binomialTrace(n-1, r, k - remain)
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    val (N, M, K) = br.readInts()

    dfs(N, M)

//    if (DP[N][M] < K) {
//        bw.println("-1")
//    } else {
//        trace(N, M, K.toLong())
//        bw.println(path.joinToString(""))
//    }

    if (binomial(N+M, N) < K) {
        bw.println("-1")
    } else {
        binomialTrace(N+M, N, K.toLong())
        bw.println(path.joinToString(""))
    }
}}}
