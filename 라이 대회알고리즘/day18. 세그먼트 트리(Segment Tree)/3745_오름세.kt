import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*


private fun BufferedReader.readInt(): Int {
    return this.readLine().toInt()
}

private fun BufferedReader.readInts(): IntArray {
    val st = StringTokenizer(this.readLine().trim())
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

private fun lowerBound(lis: IntArray, value: Int, left: Int, right: Int): Int {
    var (lb, rb) = (left to right)

    while (lb <= rb) {
        val mid = (lb+rb)/2

        if (lis[mid] < value) {
            lb = mid + 1
        } else {
            rb = mid - 1
        }
    }
    return lb
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    while (true) {
        val command: String = br.readLine() ?: break
        var N = command.trim().toInt()
        val numbers = br.readInts()

        val lis = IntArray(N) { 0 }
        lis[0] = numbers[0]
        var index = 0

        for (i in 1 until N) {
            if (lis[index] < numbers[i]) {
                index += 1
                lis[index] = numbers[i]
                continue
            }

            if (numbers[i] < lis[index]) {
                val replaceIndex = lowerBound(lis, numbers[i], 0, index)
                lis[replaceIndex] = numbers[i]
            }
        }
//        println(index+1)
//        bw.println(index+1)
        bw.println((index+1).toString())
    }
}}}
