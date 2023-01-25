import java.io.BufferedReader
import java.io.BufferedWriter
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

private lateinit var tree: LongArray
private var treeSize = 0

private fun build(numbers: LongArray) {

    // insert leaf nodes in tree
    for (i in 0 until treeSize) {
        tree[treeSize+i] = numbers[i]
    }

    // build the tree by calculating
    // parents
    for (i in treeSize-1 downTo 0) {
        tree[i] = (tree[i shl 1] * tree[(i shl 1) or 1]) % 1000000007
    }
}

private fun updateTreeNode(pos: Int, value: Long) {
    // set value at position pos
    var p = pos
    tree[treeSize + p] = value
    p += treeSize

    while (p > 1) {
        tree[p shr 1] = (tree[p] * tree[p xor 1]) % 1000000007
        p = p shr 1
    }
}

private fun query(left: Int, right: Int): Long {
    var res = 1L

    // loop to find the sum in the range
    var (l, r) = (left + treeSize to right + treeSize)
    while (l < r) {
        if ((l and 1) > 0) {
            res = (res * tree[l]) % 1000000007
            l += 1
        }
        if ((r and 1) > 0) {
            r -= 1
            res = (res *  tree[r]) % 1000000007
        }

        l = l shr 1
        r = r shr 1
    }

    return res
}


fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->

    val (N, M, K) = br.readLongs()
    treeSize = N.toInt()

    val arr = LongArray(4*N.toInt())
    tree = LongArray(4*N.toInt()) { 1 }
    repeat(N.toInt()) {
        arr[it] = br.readLong()
    }
    build(arr)

    repeat(M.toInt()+K.toInt()) {
        val (a, b, c) = br.readLongs()
        if (a == 1L) {
            updateTreeNode(b.toInt()-1, c)
        } else {
            bw.println(query(b.toInt()-1, c.toInt()))
        }
    }

    bw.flush()
}}}
