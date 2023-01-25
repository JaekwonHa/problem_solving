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

private var lambda = {a:Int,b:Int-> when{
    a<b -> 1
    a>b -> -1
    else -> 0
}}


fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    repeat(br.readInt()) {
        run repeatBlock@{
            val (n, k) = br.readInts()
            val monsterHealth = br.readInts()
            val monsterPower = br.readInts()

            val pq = PriorityQueue(Comparator<Pair<Int, Int>> { a, b ->
                when {
                    a.first != b.first -> lambda(b.first, a.first)
                    else -> lambda(b.second, a.second)
                }
            })

            for (i in 0 until n) {
                pq.add((monsterPower[i] to monsterHealth[i]))
            }

            var accumulateDamage = 0
            var currentPower = k
            while (pq.size > 0) {
                accumulateDamage += currentPower
                while (pq.size > 0 && pq.peek().second <= accumulateDamage) {
                    pq.remove()
                }
                if (pq.size > 0) {
                    currentPower -= pq.peek().first
                    if (currentPower <= 0) {
                        bw.println("NO")
                        return@repeatBlock
                    }
                }
            }
            bw.println("YES")
        }
    }
}}}
