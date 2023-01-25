package day17.` 유니온 파인드(Union-Find)`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*


private fun BufferedReader.readInt(): Int {
    return this.readLine().toInt()
}

private fun BufferedReader.readInts(): IntArray {
    val st = StringTokenizer(this.readLine())
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

private val direction = arrayOf(intArrayOf(1, 0), intArrayOf(-1, 0), intArrayOf(0, 1), intArrayOf(0, -1))
private val p = IntArray(100001) { -1 }
private val capacity = IntArray(100001) { 1 }

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
    p[rootA] = rootB
    capacity[rootB] += capacity[rootA]
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {

    val G = readInt()
    val P = readInt()

    var answer = 0

    var finish = false
    for (it in 0 until P) {
        val lastGate = readInt()
        if (!finish) {
            var check = false
            if (find(lastGate) == 0) {
                finish = true
                continue
            }
            answer += 1
            union(find(lastGate), find(lastGate) -1)
//            if (capacity[find(lastGate)] > 0) {
//                capacity[find(lastGate)] -= 1
//                answer += 1
//                check = true
//                if (lastGate != 1) {
//                    union(lastGate, lastGate-1)
//                }
//            } else {
//                for (i in find(lastGate)-1 downTo 1) {
//                    if (capacity[find(i)] > 0) {
//                        capacity[find(i)] -= 1
//                        answer += 1
//                        check = true
//                        if (i != 1) {
//                            union(i, i - 1)
//                        }
//                        break
//                    }
//                }
//            }
//            if (!check) {
//                finish = true
//            }
        }
    }
    println(answer)
}
