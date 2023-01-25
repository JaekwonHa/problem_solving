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

private val minDP = mutableMapOf<Int, String>()
private val maxDP = mutableMapOf<Int, String>()

private val count = listOf<Int>(6, 2, 5, 5, 4, 5, 6, 3, 7, 6)
private val MAX = "999999999999999999999999999999999999999999999999999"

private fun compare(left: String, right: String): Int {
    var left2 = left
//    while (left2.length > 1 && left2.startsWith('0')) {
//        left2 = left2.substring(1)
//    }
    var right2 = right
//    while (right2.length > 1 && right2.startsWith('0')) {
//        right2 = right2.substring(1)
//    }

    if (left2.length > right2.length) {
        return 1
    }
    if (left2.length < right2.length) {
        return -1
    }

    return left2.compareTo(right2)
}

private fun minDfs_step1(remain: Int, prev: Int): String {
    if (remain == 0) {
        return Long.MAX_VALUE.toString()
    }

    if (minDP[remain] != null) {
        return minDP[remain]!!
    }

    minDP[remain] = Long.MAX_VALUE.toString()

    for (i in 0 until 10) {
        if (prev == -1 && i == 0) {
            continue
        }
        if (remain - count[i] < 0) {
            continue
        }
        if (remain - count[i] == 0) {
            val next = i.toString()
            minDP[remain] = min(minDP[remain]!!.toLong(), next.toLong()).toString()
//            if (compare(minDP[remain]!!, next) > 0) {
//                minDP[remain] = next
//            }
        } else {
            val nextNumber = minDfs_step1(remain - count[i], i)
            if (nextNumber != Long.MAX_VALUE.toString()) {
                val next = i.toString() + nextNumber
                minDP[remain] = min(minDP[remain]!!.toLong(), next.toLong()).toString()
//                if (compare(minDP[remain]!!, next) > 0) {
//                    minDP[remain] = next
//                }
            }
        }
    }
    return minDP[remain]!!
}
private fun minDfs_step2(remain: Int): String {
    minDP[2] = "1"
    minDP[3] = "7"
    minDP[4] = "4"
    minDP[5] = "2"
    minDP[6] = "6"
    minDP[7] = "8"
    minDP[8] = "10"

    for (i in 9..100) {
        minDP[i] = Long.MAX_VALUE.toString()
        for (j in 0 until 10) {
            val next = minDP[i-count[j]] + j.toString()
            minDP[i] = min(minDP[i]!!.toLong(), next.toLong()).toString()
        }
    }
    return minDP[remain]!!
}

private fun maxDfs(remain: Int, prev: Int): String {
    if (remain == 0) {
        return "0"
    }

    if (maxDP[remain] != null) {
        return maxDP[remain]!!
    }

    maxDP[remain] = "0"

    for (i in 0 until 10) {
        if (prev == -1 && i == 0) {
            continue
        }
        if (remain - count[i] < 0) {
            continue
        }
        if (remain - count[i] == 0) {
            val next = i.toString()
            if (compare(maxDP[remain]!!, next) < 0) {
                maxDP[remain] = next
            }
//            if (maxDP[remain]!!.length < next.length && maxDP[remain]!! < next) {
//                maxDP[remain] = next
//            }
        } else {
            val nextNumber = maxDfs(remain - count[i], i)
            if (nextNumber != "0") {
                val next = i.toString() + nextNumber
                if (compare(maxDP[remain]!!, next) < 0) {
                    maxDP[remain] = next
                }
//                if (maxDP[remain]!!.length < next.length && maxDP[remain]!! < next) {
//                    maxDP[remain] = next
//                }
            }
        }
    }
    return maxDP[remain]!!
}


fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    repeat(br.readInt()) {
        val N = br.readInt()
//        bw.println("${minDfs_step1(N, -1)} ${maxDfs(N, -1)}")
        bw.println("${minDfs_step2(N)} ${maxDfs(N, -1)}")
    }
}}}
