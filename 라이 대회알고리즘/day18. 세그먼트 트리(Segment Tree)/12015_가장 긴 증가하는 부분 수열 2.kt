import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*
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

private lateinit var tree: LongArray
private var treeSize = 0


private fun updateTreeNode(pos: Int, value: Long) {
    // set value at position pos
    var p = pos
    tree[treeSize + p] += value
    p += treeSize

    while (p > 1) {
        tree[p shr 1] = max(tree[p], tree[p xor 1])
        p = p shr 1
    }
}

private fun query(left: Int, right: Int): Long {
    var res = 0L

    // loop to find the sum in the range
    var (l, r) = (left + treeSize to right + treeSize)
    while (l < r) {
        if ((l and 1) > 0) {
            res = max(res, tree[l])
            l += 1
        }
        if ((r and 1) > 0) {
            r -= 1
            res = max(res, tree[r])
        }

        l = l shr 1
        r = r shr 1
    }

    return res
}


fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    val N = br.readInt()
    val numbers = br.readInts()

    treeSize = N
    tree = LongArray(2*N) { 0 }

    var numbersWithIndex = Array<Pair<Int, Int>>(N) { (0 to 0) }
    repeat(N) {
        numbersWithIndex[it] = (numbers[it] to it)
    }
    numbersWithIndex = numbersWithIndex.sortedWith(compareBy({ it.first }, { -it.second })).toTypedArray()

    repeat(N) {
        val result = query(0, numbersWithIndex[it].second)
        updateTreeNode(numbersWithIndex[it].second, result+1)
    }
//    bw.println(tree[1])
    bw.println(N - tree[1])
}}}
