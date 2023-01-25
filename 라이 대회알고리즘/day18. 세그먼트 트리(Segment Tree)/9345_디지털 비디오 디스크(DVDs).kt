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

private fun build(tree: IntArray, treeSize: Int, numbers: IntArray, f: (Int, Int) -> Int) {
    for (i in 0 until treeSize) {
        tree[treeSize+i] = numbers[i]
    }

    for (i in treeSize-1 downTo 0) {
        tree[i] = f(tree[i shl 1], tree[i shl 1 or 1])
    }
}

private fun update(tree: IntArray, treeSize: Int, pos: Int, value: Int, f: (Int, Int) -> Int) {
    var p = treeSize + pos
    tree[p] = value

    while (p > 1) {
        tree[p shr 1] = f(tree[p], tree[p xor 1])
        p = p shr 1
    }
}

private fun query(tree: IntArray, treeSize: Int, left: Int, right: Int, init: Int, f: (Int, Int) -> Int): Int {
    var (l, r) = (left+treeSize to right+treeSize)

    var res = init
    while (l < r) {
        if ((l and 1) > 0) {
            res = f(res, tree[l])
            l += 1
        }
        if ((r and 1) > 0) {
            r -= 1
            res = f(res, tree[r])
        }
        l = l shr 1
        r = r shr 1
    }
    return res
}


fun main() { System.`in`.bufferedReader().use { br -> System.out.bufferedWriter().use { bw ->
    val minFunction = { a: Int, b: Int -> min(a, b) }
    val maxFunction = { a: Int, b: Int -> max(a, b) }

    repeat(br.readInt()) {
        val (N, K) = br.readInts()
        val treeSize = N
        val minTree = IntArray(2*treeSize)
        val maxTree = IntArray(2*treeSize)
        val numbers = IntArray(N) { it }

        build(minTree, treeSize, numbers, minFunction)
        build(maxTree, treeSize, numbers, maxFunction)

        repeat(K) {
            val (a, b, c) = br.readInts()
            if (a == 0) {
                val (one, two) = (maxTree[treeSize + b] to maxTree[treeSize + c])
                update(minTree, treeSize, b, two, minFunction)
                update(minTree, treeSize, c, one, minFunction)
                update(maxTree, treeSize, b, two, maxFunction)
                update(maxTree, treeSize, c, one, maxFunction)
            } else {
                if (b ==c) {
                    if (maxTree[treeSize + b] == b) {
                        bw.println("YES")
                    } else {
                        bw.println("NO")
                    }
                } else {
                    val minValue = query(minTree, treeSize, b, c+1, 100001, minFunction)
                    val maxValue = query(maxTree, treeSize, b, c+1, -1, maxFunction)
                    if (minValue == b && maxValue == c) {
                        bw.println("YES")
                    } else {
                        bw.println("NO")
                    }
                }
            }
        }
    }
}}}
