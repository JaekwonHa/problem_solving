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

private val direction = arrayOf(intArrayOf(1, 0), intArrayOf(-1, 0), intArrayOf(0, 1), intArrayOf(0, -1))
private val array = IntArray(1000) { -1 }
private val array2D = Array(1000) { IntArray(1000) { -1 } }


fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    repeat(br.readInt()) {
        run repeatBlock@{
            val n = br.readInt()
            val permutation = br.readInts()

            val cycleIds = IntArray(n + 1) { 0 }

            var answer = 0
            var cycleId = 1
            for (i in 1..n) {
                if (cycleIds[i] == 0) {
                    var next = i
                    while (cycleIds[next] == 0) {
                        cycleIds[next] = cycleId
                        next = permutation[next-1]
                        answer += 1
                    }
                    cycleId += 1
                    answer -= 1
                }
            }

            for (i in 1 until n) {
                if (cycleIds[i] == cycleIds[i + 1]) {
                    answer -= 1
                    bw.println(answer)
                    return@repeatBlock
                }
            }
            bw.println(answer + 1)
        }
    }
}}}
