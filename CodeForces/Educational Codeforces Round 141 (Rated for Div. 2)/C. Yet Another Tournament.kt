import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*
import kotlin.math.min


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
            val (N, M) = br.readLongs()
            val numbers = br.readInts()

            if (numbers.sum() <= M) {
                bw.println("1")
                return@repeatBlock
            }

            var temp = mutableListOf<Pair<Int, Int>>()
            for (i in 0 until N.toInt()) {
                temp.add((numbers[i] to i))
            }

            temp = temp.sortedWith(compareBy({ it.first }, { -it.second })).toMutableList()
            var remain = M
            var answer = 0
            for (i in 0 until N.toInt()) {
                if (remain - temp[i].first >= 0) {
                    answer += 1
                    remain -= temp[i].first
                } else {
                    break
                }
            }
            if (answer == 0) {
                bw.println(N+1)
            } else {
                if (remain + temp[answer-1].first - numbers[answer] >= 0) {
                    answer += 1
                }
                bw.println(N+1 - answer)
            }
        }
    }
}}}
