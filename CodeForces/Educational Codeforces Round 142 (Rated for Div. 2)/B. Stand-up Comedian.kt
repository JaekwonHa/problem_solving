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

private fun step1(br: BufferedReader, bw: BufferedWriter) {
    var (a, b, c, d) = br.readLongs()

    // case type1
    var (alice, bob) = a to a
    var answer = a

    while (0 < (b+c)) {
        // case type2
        if (b > 0 && bob > 0) {
            val step = min(b, bob)
            b -= step
            alice += step
            bob -= step
            answer += step
        }
        // case type3
        else if (c > 0 && alice > 0) {
            val step = min(c, alice)
            c -= step
            alice -= step
            bob += step
            answer += step
        } else {
            bw.println(answer+1)
            return
        }
    }
    // case type4
    answer += min(min(alice + 1, bob + 1), d)
    bw.println(answer)
}

private fun step2(br: BufferedReader, bw: BufferedWriter) {
    var (a, b, c, d) = br.readLongs()
    if (a == 0L) {
        bw.println("1")
        return
    }

    // case type1
    var (alice, bob) = a to a
    var answer = a

    var temp = 0L
    if (c < b) {
        temp = b
        b = c
        c = temp
    }

    // case type2, 3
    temp = min(b, c)
    answer += temp*2
    b -= temp
    c -= temp

    // case remain
    temp = min(bob, c)
    answer += temp
    bob -= temp
    c -= temp

    if (c > 0L) {
        bw.println(answer+1)
    } else {
        // case type4
        answer += min(bob + 1, d)
        bw.println(answer)
    }
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    repeat(br.readInt()) {
        step2(br, bw)
    }
}}}
