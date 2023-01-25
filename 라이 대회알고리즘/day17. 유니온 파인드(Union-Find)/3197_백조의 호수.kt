package day17.` 유니온 파인드(Union-Find)`

private fun readln() = readLine()!!
private fun readlnByte() = readln().toByte()
private fun readlnShort() = readln().toShort()
private fun readlnInt() = readln().toInt()
private fun readlnLong() = readln().toLong()
private fun readlnFloat() = readln().toFloat()
private fun readlnDouble() = readln().toDouble()
private fun readlnBigInt(radix: Int = 10) = readln().toBigInteger(radix)
private fun readlnBigDecimal() = readln().toBigDecimal()

private fun lineSequence(limit: Int = Int.MAX_VALUE) = generateSequence { readLine() }.constrainOnce().take(limit)
private fun readlnStrings() = readln().split(' ')
private fun readlnBytes() = readlnStrings().map { it.toByte() }
private fun readlnShorts() = readlnStrings().map { it.toShort() }
private fun readlnInts() = readlnStrings().map { it.toInt() }
private fun readlnLongs() = readlnStrings().map { it.toLong() }
private fun readlnFloats() = readlnStrings().map { it.toFloat() }
private fun readlnDoubles() = readlnStrings().map { it.toDouble() }

private fun readByteArray() = readlnStrings().run { ByteArray(size) { get(it).toByte() } }
private fun readShortArray() = readlnStrings().run { ShortArray(size) { get(it).toShort() } }
private fun readIntArray() = readlnStrings().run { IntArray(size) { get(it).toInt() } }
private fun readLongArray() = readlnStrings().run { LongArray(size) { get(it).toLong() } }
private fun readFloatArray() = readlnStrings().run { FloatArray(size) { get(it).toFloat() } }
private fun readDoubleArray() = readlnStrings().run { DoubleArray(size) { get(it).toDouble() } }

private fun readlnByteArray(n: Int) = ByteArray(n) { readlnByte() }
private fun readlnShortArray(n: Int) = ShortArray(n) { readlnShort() }
private fun readlnIntArray(n: Int) = IntArray(n) { readlnInt() }
private fun readlnLongArray(n: Int) = LongArray(n) { readlnLong() }
private fun readlnFloatArray(n: Int) = FloatArray(n) { readlnFloat() }
private fun readlnDoubleArray(n: Int) = DoubleArray(n) { readlnDouble() }

private fun readByteArray2d(rows: Int, cols: Int) = Array(rows) { readByteArray().also { require(it.size == cols) } }
private fun readShortArray2d(rows: Int, cols: Int) = Array(rows) { readShortArray().also { require(it.size == cols) } }
private fun readLongArray2d(rows: Int, cols: Int) = Array(rows) { readLongArray().also { require(it.size == cols) } }
private fun readIntArray2d(rows: Int, cols: Int) = Array(rows) { readIntArray().also { require(it.size == cols) } }
private fun readFloatArray2d(rows: Int, cols: Int) = Array(rows) { readFloatArray().also { require(it.size == cols) } }
private fun readDoubleArray2d(rows: Int, cols: Int) = Array(rows) { readDoubleArray().also { require(it.size == cols) } }

private fun isWhiteSpace(c: Char) = c in " \r\n\t"

// JVM-only targeting code follows next

// day17.` 유니온 파인드(Union-Find)`.readString() via sequence is still slightly faster than Scanner
private fun readString() = generateSequence { System.`in`.read().toChar() }
    .dropWhile { isWhiteSpace(it) }.takeWhile { !isWhiteSpace(it) }.joinToString("")

private fun readByte() = readString().toByte()
private fun readShort() = readString().toShort()
private fun readInt() = readString().toInt()
private fun readLong() = readString().toLong()
private fun readFloat() = readString().toFloat()
private fun readDouble() = readString().toDouble()
private fun readBigInt(radix: Int = 10) = readString().toBigInteger(radix)
private fun readBigDecimal() = readString().toBigDecimal()

private fun readBytes(n: Int) = generateSequence { readByte() }.take(n)
private fun readShorts(n: Int) = generateSequence { readShort() }.take(n)
private fun readInts(n: Int) = generateSequence { readInt() }.take(n)
private fun readLongs(n: Int) = generateSequence { readLong() }.take(n)
private fun readFloats(n: Int) = generateSequence { readFloat() }.take(n)
private fun readDoubles(n: Int) = generateSequence { readDouble() }.take(n)


private val direction = arrayOf(intArrayOf(1, 0), intArrayOf(-1, 0), intArrayOf(0, 1), intArrayOf(0, -1))


private tailrec fun find(p: IntArray, n: Int): Int {
    if (p[n] < 0) {
        return n
    }
    p[n] = find(p, p[n])
    return p[n]
}

private fun union(p: IntArray, a: Int, b: Int) {
    val rootA = find(p, a)
    val rootB = find(p, b)
    if (rootA == rootB) {
        return
    }
    if (rootA < rootB) {
        p[rootB] = rootA
    } else {
        p[rootA] = rootB
    }
}

fun main() {
    val (R, C) = readlnInts()
    val board = Array<CharArray>(R) { charArrayOf() }
    for (x in 0 until R) {
        board[x] = readln().toCharArray()
    }

    val q = ArrayDeque<IntArray>()
    val visit = Array(R) { IntArray(C) { -1 } }
    val swanArea = IntArray(2) { -1 }

    var areaId = 0
    var swanId = 0
    for (x in 0 until R) {
        for (y in 0 until C) {
            if (board[x][y] != 'X' && visit[x][y] == -1) {
                visit[x][y] = areaId
                q.add(intArrayOf(x, y))
                while (q.size != 0) {
                    val (x2, y2) = q.removeFirst()
                    if (board[x2][y2] == 'L') {
                        swanArea[swanId] = areaId
                        swanId += 1
                    }
                    for ((dx, dy) in direction) {
                        val (nx, ny) = (x2 + dx to y2 + dy)
                        if (0 <= nx && nx < R && 0 <= ny && ny < C) {
                            if (visit[nx][ny] == -1 && board[nx][ny] != 'X') {
                                visit[nx][ny] = areaId
                                q.add(intArrayOf(nx, ny))
                            }
                        }
                    }
                }
                areaId += 1
            }
        }
    }

    var level = 0
    val p = IntArray(areaId + 1) { -1 }

    if (swanArea[0] == swanArea[1]) {
        println(level)
        return
    }

    q.clear()
    for (x in 0 until R) {
        for (y in 0 until C) {
            if (board[x][y] != 'X') {
                q.add(intArrayOf(x, y))
            }
        }
    }

    while (q.size != 0) {
        level += 1
        repeat(q.size) {
            val (x, y) = q.removeFirst()
            for ((dx, dy) in direction) {
                val (nx, ny) = (x + dx to y + dy)
                if (0 <= nx && nx < R && 0 <= ny && ny < C) {
                    if (visit[nx][ny] == -1) {
                        visit[nx][ny] = visit[x][y]
                        q.add(intArrayOf(nx, ny))
                        for ((dx2, dy2) in direction) {
                            val (nx2, ny2) = (nx + dx2 to ny + dy2)
                            if (0 <= nx2 && nx2 < R && 0 <= ny2 && ny2 < C && visit[nx2][ny2] != -1 && visit[nx][ny] != visit[nx2][ny2]) {
                                union(p, visit[nx][ny], visit[nx2][ny2])
                                if (find(p, swanArea[0]) == find(p, swanArea[1])) {
                                    println(level)
                                    return
                                }
                            }
                        }
                    } else {
                        union(p, visit[x][y], visit[nx][ny])
                        if (find(p, swanArea[0]) == find(p, swanArea[1])) {
                            println(level)
                            return
                        }
                    }
                }
            }
        }
    }
}
