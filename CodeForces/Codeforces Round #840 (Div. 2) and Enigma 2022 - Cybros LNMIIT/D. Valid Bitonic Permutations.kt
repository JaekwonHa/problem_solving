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

private var n = 0
private var bi = 0
private var bj = 0
private var x = 0
private var y = 0

private tailrec fun dfs(DP: Array<Array<IntArray>>, visit: BooleanArray, pos: Int, prev: Int, direction: Int): Int {
    if (n <= pos){
        if (direction == 0) {
            return 1
        } else {
            return 0
        }
    }
    if (DP[pos][prev][direction] != -1) {
        return DP[pos][prev][direction]
    }

    var answer = 0
    if (pos == bi-1) {
        if (direction == 0) {
            if (prev < x) {
                answer = dfs(DP, visit, pos+1, x, 1)
            }
        } else {
            if (x < prev) {
                answer = dfs(DP, visit, pos+1, x, 0)
            }
        }
    } else if (pos == bj-1) {
        if (direction == 0) {
            if (prev < y) {
                answer = dfs(DP, visit, pos+1, y, 1)
            }
        } else {
            if (y < prev) {
                answer = dfs(DP, visit, pos+1, y, 0)
            }
        }
    } else {
        if (direction == 0) {
            for (i in prev + 1..n) {
                if (!visit[i]) {
                    visit[i] = true
                    answer += dfs(DP, visit, pos + 1, i, 1)
                    visit[i] = false
                }
            }
        } else {
            for (i in prev - 1 downTo 1) {
                if (!visit[i]) {
                    visit[i] = true
                    answer += dfs(DP, visit, pos + 1, i, 0)
                    visit[i] = false
                }
            }

        }
    }
    DP[pos][prev][direction] = answer
    return answer
}


fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    repeat(br.readInt()) {
        run repeatBlock@{
            val command = br.readInts()
            n = command[0]
            bi = command[1]
            bj = command[2]
            x = command[3]
            y = command[4]

            val visit = BooleanArray(n+1) { false }
            visit[x] = true
            visit[y] = true

            val DP = Array(n+1) { Array(n+1) { IntArray(2) { -1 } } }

            var answer = 0

            if (bi == 1) {
                answer += dfs(DP, visit, 1, x, 0)
            } else {
                for (i in 1..n) {
                    if (!visit[i]) {
                        visit[i] = true
                        answer += dfs(DP, visit, 1, i, 0)
                        visit[i] = false
                    }
                }
            }
            bw.println(answer)
        }
    }
}}}
