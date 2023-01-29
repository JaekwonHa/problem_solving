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
        val N = br.readInt()
        val numbers = br.readInts()

        var spell_1 = 0
        for (i in 0 until N) {
            if (numbers[i] == 1) {
                numbers[i] = 0
                spell_1 += 1
            }
        }
        var spell_2 = N - spell_1
        if (spell_1 % 2 == 0) {
            spell_1 /= 2
        } else {
            spell_1 /= 2
            spell_1 += 1
        }
        bw.println(spell_1 + spell_2)
    }
}}}
