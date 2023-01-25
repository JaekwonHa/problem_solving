import java.io.BufferedReader
import java.io.BufferedWriter
import java.lang.StringBuilder
import java.util.*


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

private fun build(treeSize: Int, tree: LongArray, numbers: LongArray) {

    // insert leaf nodes in tree
    for (i in 0 until treeSize) {
        tree[treeSize+i] = numbers[i]
    }

    // build the tree by calculating
    // parents
    for (i in treeSize-1 downTo 0) {
        tree[i] = tree[i shl 1] + tree[(i shl 1) or 1]
    }
}

private fun updateTreeNode(treeSize: Int, tree: LongArray, pos: Int, value: Long) {
    // set value at position pos
    var p = pos + treeSize
    tree[p] = value

    while (p > 1) {
        tree[p shr 1] = tree[p] + tree[p xor 1]
        p = p shr 1
    }
}

private fun query(treeSize: Int, tree: LongArray, left: Int, right: Int): Long {
    var res = 0L

    // loop to find the sum in the range
    var (l, r) = (left + treeSize to right + treeSize)
    while (l < r) {
        if ((l and 1) > 0) {
            res += tree[l]
            l += 1
        }
        if ((r and 1) > 0) {
            r -= 1
            res += tree[r]
        }

        l = l shr 1
        r = r shr 1
    }

    return res
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    repeat(br.readInt()) {
        val sb = StringBuilder()
        val (N, M) = br.readInts()

        val treeSize = M + N
        val tree = LongArray(2*treeSize) { 0 }
        val initPosition = LongArray(treeSize)
        for (i in 0 until N) {
            initPosition[M+i] = 1
        }
        build(treeSize, tree, initPosition)

        val moviePosition = IntArray(N) { M + it }
        var lastIndex = M
        for (number in  br.readInts()) {
            val pickIndex = moviePosition[number-1]
            sb.append(query(treeSize, tree, 0, pickIndex))
            sb.append(" ")

            updateTreeNode(treeSize, tree, pickIndex, 0L)
            lastIndex -= 1
            moviePosition[number-1] = lastIndex
            updateTreeNode(treeSize, tree, lastIndex, 1L)
        }

        bw.println(sb)
    }
}}}
