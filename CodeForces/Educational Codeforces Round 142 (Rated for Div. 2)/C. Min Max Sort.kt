import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*
import kotlin.math.max
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

private fun step1(br: BufferedReader, bw: BufferedWriter) {
    run repeatBlock@{

        val N = br.readInt()
        val numbers = br.readInts()
        val answer = IntArray(N) { it + 1 }
        var valid = true
        for (i in 0 until N) {
            if (numbers[i] != answer[i]) {
                valid = false
            }
        }
        if (valid) {
            bw.println("0")
            return@repeatBlock
        }

        var position = IntArray(N + 1)
        for (i in 0 until N) {
            position[numbers[i]] = i
        }

        var mid = (N / 2) + 1
        var i = 0

        var leftPrev = mid
        var left = leftPrev - 1
        var rightPrev = mid
        var right = rightPrev + 1

        var leftDirection = 1
        var rightDirection = 1
        while (i < N) {
            if (left <= 0 && right > N) {
                break
            }

            if (left > 0 && (position[left] - position[leftPrev]) * leftDirection < 0) {
                leftPrev = left
                left -= 1
                leftDirection *= -1
            }
            if (left > 0) {
                leftPrev = left
                left -= 1
                leftDirection *= -1
            }

            if (right <= N && (position[right] - position[rightPrev]) * rightDirection > 0) {
                rightPrev = right
                right += 1
                rightDirection *= -1
            }
            if (right <= N) {
                rightPrev = right
                right += 1
                rightDirection *= -1
            }
            i += 1
        }
        bw.println(i)
    }
}

private fun step2(br: BufferedReader, bw: BufferedWriter) {
    run repeatBlock@{

        val N = br.readInt()
        val numbers = br.readInts()
        val answer = IntArray(N) { it + 1 }
        var valid = true
        for (i in 0 until N) {
            if (numbers[i] != answer[i]) {
                valid = false
            }
        }
        if (valid) {
            bw.println("0")
            return@repeatBlock
        }

        var position = IntArray(N + 1)
        for (i in 0 until N) {
            position[numbers[i]] = i
        }

        var mid = (N / 2) + 1
        var i = 0

        var temp = false
        var left = mid-1
        var right = mid+1
        while (0 < left || right < N+1) {

            temp = true
            while (left != 0 && position[left] < position[left+1]) {
                temp = false
                left -= 1
            }
            if (temp) {
                left = max(0, left-1)
            }

            temp = true
            while (right != N+1 && position[right-1] < position[right]) {
                temp = false
                right += 1
            }
            if (temp) {
                right = min(N+1, right+1)
            }

            if (left <= 0 && right >= N+1) {
                break
            }
            i += 1
        }

        bw.println(i)
    }
}

private fun step3(br: BufferedReader, bw: BufferedWriter) {
    val N = br.readInt()
    val numbers = br.readInts()
    val answer = IntArray(N) { it + 1 }
    var valid = true
    for (i in 0 until N) {
        if (numbers[i] != answer[i]) {
            valid = false
        }
    }
    if (valid) {
        bw.println("0")
        return
    }

    var position = IntArray(N + 1)
    for (i in 0 until N) {
        position[numbers[i]] = i
    }

    var (l, r) = ((N+1)/2 to (N+2)/2)
    while (0 < l && ((l==r) || (position[l] < position[l+1] && position[r-1] < position[r]))) {
        l -= 1
        r += 1
    }
    bw.println("${(N-r+1 + l)/2}")
}


fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    repeat(br.readInt()) {
        step3(br, bw)
    }
}}}
