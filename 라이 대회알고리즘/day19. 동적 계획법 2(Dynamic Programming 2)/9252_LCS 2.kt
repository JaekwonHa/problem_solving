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

private val DP = Array(1001) { IntArray(1001) { 0 } }
private var sequenceX = ""
private var sequenceY = ""


fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    sequenceX = br.readLine()!!
    sequenceY = br.readLine()!!

    for (i in 0 until sequenceX.length) {
        for (j in 0 until sequenceY.length) {
            if (sequenceX[i] == sequenceY[j]) {
                DP[i+1][j+1] = DP[i][j]+1
            } else {
                DP[i+1][j+1] = max(DP[i+1][j], DP[i][j+1])
            }
        }
    }
    bw.println(DP[sequenceX.length][sequenceY.length])
    if (DP[sequenceX.length][sequenceY.length] == 0) {
        return
    }

    var index = DP[sequenceX.length][sequenceY.length]
    val answer = CharArray(index)
    index -= 1
    var (i, j) = (sequenceX.length to sequenceY.length)
    while (index >= 0) {
        if (DP[i][j] != DP[i-1][j] && DP[i][j] != DP[i][j-1] && DP[i][j] != DP[i-1][j-1]) {
            answer[index] = sequenceX[i-1]
            index -= 1
            i -= 1
            j -= 1
            continue
        }
        if (DP[i][j] == DP[i-1][j]) {
            i -= 1
            continue
        }
        if (DP[i][j] == DP[i][j-1]) {
            j -= 1
            continue
        }
    }
    bw.println(String(answer))
}}}
