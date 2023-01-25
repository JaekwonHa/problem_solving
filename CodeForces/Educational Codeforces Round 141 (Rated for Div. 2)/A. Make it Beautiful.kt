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

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    repeat(br.readInt()) {
        val N = br.readInt()
        val numbers = br.readInts()
        numbers.sortDescending()

        var possible = false
        for (i in 1 until N) {
            if (numbers[0] != numbers[i]) {
                possible = true
                break
            }
        }

        if (!possible) {
            bw.println("NO")
        } else {
            if (numbers[0] == numbers[1]) {
                for (i in 2 until N) {
                    if (numbers[0] != numbers[i]) {
                        val temp = numbers[0]
                        numbers[0] = numbers[i]
                        numbers[i] = temp
                        break
                    }
                }
            }
            bw.println("YES")
            bw.println(numbers.joinToString(" "))
        }
    }
}}}
