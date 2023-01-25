import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*
import kotlin.math.abs
import kotlin.math.max


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

private fun step1(n: Int, numbers: LongArray): Long {
    val prefixSum = LongArray(n + 1) { 0 }
    for (i in 1..n) {
        prefixSum[i] = numbers[i - 1] + prefixSum[i - 1]
    }
    var i = 1
    var j = 2
    var answer = 0L
    var notIncludeIndex = 1
    while (i < n) {
        j = i + 1
        var partialAnswerIndex = j
        var partialAnswer = prefixSum[j] - prefixSum[i - 1]
        while (j <= n) {
            if (partialAnswer < abs(numbers[i - 1] - numbers[j - 1]) * (j - i + 1)) {
                partialAnswerIndex = j
                partialAnswer = abs(numbers[i - 1] - numbers[j - 1]) * (j - i + 1)
            }
            j += 1
        }
        if (prefixSum[partialAnswerIndex] - prefixSum[i - 1] < partialAnswer) {
            answer += partialAnswer
            i = partialAnswerIndex + 1
            notIncludeIndex = partialAnswerIndex + 1
        } else {
            i += 1
        }
    }
    if (notIncludeIndex < n) {
        answer += prefixSum[n] - prefixSum[notIncludeIndex - 1]
    }
    return max(answer, numbers.sum())
}

private fun step2(n: Int, numbers: LongArray): Long {
    if (n == 2) {
        return max(numbers.sum(), abs(numbers[0] - numbers[1]) * 2)
    }
    if (n > 3) {
        return numbers.max() * n
    }

    var answer = max(3 * numbers[0], 3 * numbers[2])
    answer = max(answer, 3 * abs(numbers[0] - numbers[1]))
    answer = max(answer, 3 * abs(numbers[1] - numbers[2]))
    return max(answer, numbers.sum())
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    repeat(br.readInt()) {
        run repeatBlock@{
            val n = br.readInt()
            val numbers = br.readLongs()

//            bw.println(step1(n, numbers))
            bw.println(step2(n, numbers))
        }
    }
}}}
