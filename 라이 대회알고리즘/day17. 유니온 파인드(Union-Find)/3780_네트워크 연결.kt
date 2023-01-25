package day17.` 유니온 파인드(Union-Find)`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.abs


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
private lateinit var d: IntArray

private tailrec fun find(n: Int): Int {
    if (p[n] < 0) {
        return n
    }

    val parent = find(p[n])
    d[n] += d[p[n]]
    p[n] = parent

    return p[n]
}

private fun union(a: Int, b: Int) {
//    val rootA = a
//    if (rootA == b) {
//        return
//    }
    p[a] = b
    d[a] += (abs(a - b) % 1000)
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val T = readInt()
    repeat(T) {
        val N = readInt()
        p = IntArray(N+1) { -1 }
        d = IntArray(N+1) { 0 }

        while (true) {
            val command = readLine()!!
            if (command[0] == 'E') {
                find(command.split(" ")[1].toInt())
                println(d[command.split(" ")[1].toInt()])
            } else if (command[0] == 'I'){
                union(command.split(" ")[1].toInt(), command.split(" ")[2].toInt())
            } else {
                break
            }
        }
    }
}
