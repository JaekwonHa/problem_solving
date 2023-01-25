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
        tree[i] = tree[i shl 1] + tree[(i shl 1) or 1]
    }
}

private fun updateTreeNode(pos: Int, value: Long) {
    // set value at position pos
    var p = pos
    tree[treeSize + p] += value
    p += treeSize

    while (p > 1) {
        tree[p shr 1] = tree[p] + tree[p xor 1]
        p = p shr 1
    }
}

private fun query(left: Int, right: Int): Long {
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

private fun binarySearch(value: Long, left: Int, right: Int): Int {
    var (lb, rb) = (left to right)
    var remain = value

    while (lb <= rb) {
        val mid = (lb+rb)/2

        val leftCount = query(lb, mid+1)
//        val rightCount = query(mid+1, rb+1)

        if (leftCount < remain) {
            remain -= leftCount
            lb = mid + 1
        } else {
            rb = mid - 1
        }
    }
    return lb
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    val N = br.readInt()
    treeSize = 1000001
    tree = LongArray(2*treeSize)
    repeat(N) {
        val st = StringTokenizer(br.readLine())
        val arr = LongArray(st.countTokens())
        for (i in 0 until st.countTokens()) {
            arr[i] = st.nextToken().toLong()
        }
        if (arr[0] == 2L) {
            updateTreeNode(arr[1].toInt(), arr[2])
        } else {
            val index = binarySearch(arr[1], 1, 1000000)
            bw.println(index)
            updateTreeNode(index, -1)
        }
    }
}}}
