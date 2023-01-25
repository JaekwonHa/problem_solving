import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*
import kotlin.collections.ArrayDeque


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
            var numbers = Array(n) { intArrayOf() }
            val input = br.readInts()
            for (i in 1..n) {
                numbers[i - 1] = intArrayOf(input[i - 1], i)
            }

            numbers = numbers.sortedWith(compareBy { it[0] }).toTypedArray()
            val p = IntArray(n)
            val q = IntArray(n)
            val pVisit = BooleanArray(n + 1) { false }
            val qVisit = BooleanArray(n + 1) { false }
            var pLast = 1
            var qLast = 1

            for (i in 0 until n) {
                val number = numbers[i][0]
                if (!pVisit[number]) {
                    p[numbers[i][1]-1] = number
                    pVisit[number] = true

                    var check = false
                    for (j in qLast ..number) {
                        if (!qVisit[j]) {
                            check = true
                            q[numbers[i][1]-1] = j
                            qVisit[j] = true
                            qLast = j+1
                            break
                        }
                    }

                    if (!check) {
                        bw.println("NO")
                        return@repeatBlock
                    }
                } else if (!qVisit[number]) {
                    q[numbers[i][1]-1] = number
                    qVisit[number] = true

                    var check = false
                    for (j in pLast ..number) {
                        if (!pVisit[j]) {
                            check = true
                            p[numbers[i][1]-1] = j
                            pVisit[j] = true
                            pLast = j+1
                            break
                        }
                    }

                    if (!check) {
                        bw.println("NO")
                        return@repeatBlock
                    }
                } else {
                    bw.println("NO")
                    return@repeatBlock
                }
            }
            bw.println("YES")
            p.forEach { bw.append("$it ")}
            bw.appendLine()
            q.forEach { bw.append("$it ")}
            bw.appendLine()
        }
    }
}}}
