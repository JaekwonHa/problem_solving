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

private val sb = StringBuilder()
private fun StringBuilder.println(text: String) {
    append(text + "\n")
}

private fun StringBuilder.println() {
    print(this)
}

private lateinit var numbers: Array<IntArray>

private lateinit var p: IntArray
private lateinit var flavor: LongArray
private lateinit var spiciness: LongArray


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
    flavor[rootB] += flavor[rootA]
    spiciness[rootB] = Math.max(spiciness[rootA], spiciness[rootB])
}


fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {

    val st = StringTokenizer(readLine())
    val N = st.nextToken().toInt()
    val M = st.nextToken().toLong()

    numbers = Array(N) { intArrayOf() }
    p = IntArray(N) { -1 }
    flavor = LongArray(N) { -1L }
    spiciness = LongArray(N) { -1L }

    repeat(N) {
        val (a, b) = readInts()
        numbers[it] = intArrayOf(b, a, it)
        flavor[it] = a.toLong()
        spiciness[it] = b.toLong()
    }

    numbers.sortBy { it[0] }

    for ((s, f, i) in numbers) {
        val left = i - 1
        var flavorSum = flavor[find(i)]
        var spicinessMax = spiciness[find(i)]
        if (left >= 0 && spiciness[left] <= spiciness[i]) {
            union(left, i)
            flavorSum = flavor[find(i)]
            spicinessMax = spiciness[find(i)]
        }
        if (flavorSum >= M) {
            println(spicinessMax)
            return
        }

        val right = i + 1
        if (right < N && spiciness[right] <= spiciness[i]) {
            union(right, i)
            flavorSum = flavor[find(i)]
            spicinessMax = spiciness[find(i)]
        }
        if (flavorSum >= M) {
            println(spicinessMax)
            return
        }
    }
}
