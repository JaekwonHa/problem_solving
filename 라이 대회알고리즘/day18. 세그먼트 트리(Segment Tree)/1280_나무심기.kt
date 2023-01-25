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
    var p = pos
    tree[treeSize + p] += value
    p += treeSize

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

    val mod = 1_000_000_007
    val N = br.readInt()
    val treeSize = 200000
    val sumTree = LongArray(2*treeSize) { 0 }
    val countTree = LongArray(2*treeSize) { 0 }
    build(treeSize, sumTree, LongArray(treeSize) { 0 })
    build(treeSize, countTree, LongArray(treeSize) { 0 })

    val a = br.readLong()
    updateTreeNode(treeSize, sumTree, a.toInt(), a)
    updateTreeNode(treeSize, countTree, a.toInt(), 1)

    var answer = 1L
    repeat(N-1) {
        val a = br.readLong()
        val leftCount = query(treeSize, countTree, 0, a.toInt())
        val rightCount = query(treeSize, countTree, a.toInt()+1, treeSize)
        val leftSum = query(treeSize, sumTree, 0, a.toInt())
        val rightSum = query(treeSize, sumTree, a.toInt()+1, treeSize)
        val leftCost: Long = ((a*leftCount) - leftSum) % mod
        val rightCost: Long = (rightSum - (a*rightCount)) % mod

        answer = (answer * ((rightCost + leftCost) % mod)) % mod
        updateTreeNode(treeSize, sumTree, a.toInt(), a)
        updateTreeNode(treeSize, countTree, a.toInt(), 1)
    }
    bw.println(answer.toString())
}}}
