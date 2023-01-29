import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*
import kotlin.collections.ArrayDeque
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

    data class Point(
        val text: String,
        val countZero: Int,
        val countOne: Int
    )

    val N = br.readInt()

    val rule = Array(N+1) { IntArray(N+1) { 0 } }
    for (i in 1.. N) {
        val numbers = br.readInts()
        for (j in i..N) {
            rule[i][j] = numbers[j-i]
            if (i == j && numbers[j-i] == 2) {
                bw.println("0")
                return
            }
        }
    }

    val DP = Array(N+1) { IntArray(4) { 0 } }
    DP[1][0] = 0
    DP[1][1] = 1
    DP[1][2] = 1
    DP[1][3] = 0
    for (j in 2..N) {
        var temp = 0L

        // case1. 0을 붙이려고 하는 경우
        temp = 0L
        for (i in 1..j) {
            val c = rule[i][j]

            if (c == 0) {
                temp = (temp + DP[j-1][1]) % 998244353
                temp = (temp + DP[j-1][2]) % 998244353
            }
            else if (c == 1) {
                temp = (temp + DP[j-1][1]) % 998244353
            }
            else if (c == 2) {

            }
        }

        // case2. 1을 붙이려고 하는 경우
    }
//
//    val q = ArrayDeque<Point>()
//    q.add(Point("0", 1, 0))
//    q.add(Point("1", 0, 1))
//
//    var answer = 0L
//    while (0 < q.size) {
//        val (current, currentCountZero, currentCountOne) = q.removeFirst()
//        if (current.length >= N) {
//            answer = (answer + 1) % 998244353
//            continue
//        }
//        val n = current.length+1
//
//        var next = current + "0"
//
//        var countZero = currentCountZero + 1
//        var countOne = currentCountOne
////        for (ii in 0 until next.length) {
////            if (next[ii] == '0') {
////                countZero += 1
////            } else {
////                countOne += 1
////            }
////        }
//
//        var valid = true
//        for (i in 1..n) {
//            val c = rule[i][n]
//            if (c == 0) {
//            } else {
//                if (c == 1 && (countZero > 0 && countOne > 0)) {
//                    valid = false
//                }
//                else if (c == 2 && ((countZero > 0 && countOne == 0) || (countZero == 0 && countOne > 0))) {
//                    valid = false
//                }
//            }
//
//            if (next[i-1] == '0') {
//                countZero -= 1
//            } else {
//                countOne -= 1
//            }
//
////            var checkZero = false
////            var checkOne = false
////            for (ii in i-1 until next.length) {
////                if (next[ii] == '0') {
////                    checkZero = true
////                } else {
////                    checkOne = true
////                }
////            }
////            if (c == 1 && (checkZero && checkOne)) {
////                valid = false
////                continue
////            }
////            if (c == 2 && !(checkZero and checkOne)) {
////                valid = false
////                continue
////            }
//
////            if (c == 1 && next.last().digitToInt() == 3) {
////                valid = false
////                continue
////            }
////            if (c == 2 && next.last().digitToInt() != 3) {
////                valid = false
////                continue
////            }
//        }
//        if (valid) {
//            q.add(Point(next, currentCountZero+1, currentCountOne))
//        }
//
//        next = current + "1"
//        valid = true
//
//        countZero = currentCountZero
//        countOne = currentCountOne + 1
////        for (ii in 0 until next.length) {
////            if (next[ii] == '0') {
////                countZero += 1
////            } else {
////                countOne += 1
////            }
////        }
//
//        for (i in 1..n) {
//            val c = rule[i][n]
//            if (c == 0) {
//            } else {
//                if (c == 1 && (countZero > 0 && countOne > 0)) {
//                    valid = false
//                }
//                else if (c == 2 && ((countZero > 0 && countOne == 0) || (countZero == 0 && countOne > 0))) {
//                    valid = false
//                }
//            }
//
//            if (next[i-1] == '0') {
//                countZero -= 1
//            } else {
//                countOne -= 1
//            }
//
////            var checkZero = false
////            var checkOne = false
////            for (ii in i-1 until next.length) {
////                if (next[ii] == '0') {
////                    checkZero = true
////                } else {
////                    checkOne = true
////                }
////            }
////            if (c == 1 && (checkZero && checkOne)) {
////                valid = false
////                continue
////            }
////            if (c == 2 && !(checkZero and checkOne)) {
////                valid = false
////                continue
////            }
//
////            if (c == 1 && next.last().digitToInt() == 3) {
////                valid = false
////                continue
////            }
////            if (c == 2 && next.last().digitToInt() != 3) {
////                valid = false
////                continue
////            }
//        }
//        if (valid) {
//            q.add(Point(next, currentCountZero, currentCountOne+1))
//        }
//    }
//    bw.println(answer)
}}}
