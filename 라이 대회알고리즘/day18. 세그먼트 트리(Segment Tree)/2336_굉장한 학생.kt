import java.io.BufferedReader
import java.io.BufferedWriter
import java.util.*
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

private lateinit var tree: IntArray
private var treeSize = 0

private fun build(numbers: IntArray) {

    // insert leaf nodes in tree
    for (i in 0 until treeSize) {
        tree[treeSize+i] = numbers[i]
    }

    // build the tree by calculating
    // parents
    for (i in treeSize-1 downTo 0) {
        tree[i] = min(tree[i shl 1], tree[(i shl 1) or 1])
    }
}

private fun updateTreeNode(pos: Int, value: Int) {
    // set value at position pos
    var p = pos
    tree[treeSize + p] = value
    p += treeSize

    while (p > 1) {
        tree[p shr 1] = min(tree[p], tree[p xor 1])
        p = p shr 1
    }
}

private fun query(left: Int, right: Int): Int {
    var res = Int.MAX_VALUE

    // loop to find the sum in the range
    var (l, r) = (left + treeSize to right + treeSize)
    while (l < r) {
        if ((l and 1) > 0) {
            res = min(res, tree[l])
            l += 1
        }
        if ((r and 1) > 0) {
            r -= 1
            res = min(res, tree[r])
        }

        l = l shr 1
        r = r shr 1
    }

    return res
}

fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    val N = br.readInt()

    val test1 = br.readInts()
    val test2 = br.readInts()
    val test3 = br.readInts()

    val rankWithId1 = Array<Pair<Int, Int>>(N) { 1 to 1 }
    val rankWithId2 = IntArray(N+1)
    val rankWithId3 = IntArray(N+1)
    for (i in 0 until N) {
        rankWithId1[i] = (test1[i] to i)
        rankWithId2[test2[i]] = i
        rankWithId3[test3[i]] = i
    }
    rankWithId1.sortBy { it.second }

    treeSize = N+1
    tree = IntArray(2*treeSize) { Int.MAX_VALUE }

    var answer = 0
    for ((id, firstRank) in rankWithId1) {
        val secondRank = rankWithId2[id]
        val thirdRank = rankWithId3[id]
        val minThirdRank = query(0, secondRank)
        if (minThirdRank > thirdRank) {
            answer += 1
        }
        updateTreeNode(secondRank, thirdRank)
    }
    bw.println(answer)
}}}
