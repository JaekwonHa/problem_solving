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

private lateinit var maxTree: LongArray
private lateinit var minTree: LongArray
private var treeSize = 0

private fun buildMaxTree(numbers: LongArray) {

    // insert leaf nodes in tree
    for (i in 0 until treeSize) {
        maxTree[treeSize+i] = numbers[i]
    }

    // build the tree by calculating
    // parents
    for (i in treeSize-1 downTo 0) {
        maxTree[i] = max(maxTree[i shl 1], maxTree[(i shl 1) or 1])
    }
}

private fun queryMax(left: Int, right: Int): Long {
    var res = 1L

    // loop to find the sum in the range
    var (l, r) = (left + treeSize to right + treeSize)
    while (l < r) {
        if ((l and 1) > 0) {
            res = max(res, maxTree[l])
            l += 1
        }
        if ((r and 1) > 0) {
            r -= 1
            res = max(res, maxTree[r])
        }

        l = l shr 1
        r = r shr 1
    }

    return res
}

private fun buildMinTree(numbers: LongArray) {

    // insert leaf nodes in tree
    for (i in 0 until treeSize) {
        minTree[treeSize+i] = numbers[i]
    }

    // build the tree by calculating
    // parents
    for (i in treeSize-1 downTo 0) {
        minTree[i] = min(minTree[i shl 1], minTree[(i shl 1) or 1])
    }
}

private fun queryMin(left: Int, right: Int): Long {
    var res = 1000000000L

    // loop to find the sum in the range
    var (l, r) = (left + treeSize to right + treeSize)
    while (l < r) {
        if ((l and 1) > 0) {
            res = min(res, minTree[l])
            l += 1
        }
        if ((r and 1) > 0) {
            r -= 1
            res = min(res, minTree[r])
        }

        l = l shr 1
        r = r shr 1
    }

    return res
}



fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    val (N, M) = br.readInts()
    treeSize = N

    val numbers = LongArray(2*N)
    maxTree = LongArray(2*N) { 1 }
    minTree = LongArray(2*N) { 1 }

    repeat(N) {
        numbers[it] = br.readLong()
    }
    buildMaxTree(numbers)
    buildMinTree(numbers)

    repeat(M) {
        val (a, b) = br.readInts()
        bw.println("${queryMin(a-1, b)} ${queryMax(a-1, b)}")
    }
}}}
