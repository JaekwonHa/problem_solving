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

    for (i in 0 until treeSize) {
        tree[treeSize+i] = numbers[i]
    }

    for (i in treeSize-1 downTo 0) {
        tree[i] = tree[i shl 1] + tree[(i shl 1) or 1]
    }
}

private fun update(pos: Int, value: Long) {
    var p = pos
    tree[treeSize + p] = value
    p += treeSize

    while (p>1) {
        tree[p shr 1] = tree[p] + tree[p xor 1]
        p = p shr 1
    }
}

private fun query(left: Int, right: Int): Long {
    var res = 0L

    var (l, r) = (left + treeSize to right+ treeSize)
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

    val N = br.readInt()
    treeSize = N
    tree = LongArray(2*N) { 0 }
    build(LongArray(N) { 1 })

    val numbers = mutableMapOf<Int, Int>()
    repeat(N) {
        numbers[br.readInt()] = it
    }

    repeat(N) {
        if ((it+1) and 1 > 0) {
            val pos = numbers[(it+1)/2+1]!!
            bw.println(query(0, pos))
            update(pos, 0)
        } else {
            val pos = numbers[N-(it/2)]!!
            bw.println(query(pos+1, N))
            update(pos, 0)
        }
    }
}}}
