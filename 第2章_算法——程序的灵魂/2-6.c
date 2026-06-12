/*
 * 习题6
 * 用伪代码表示第 4 题中各题的算法。
 * （原第4题共8小题，请分别写出对应的伪代码）
*/

/*
 * 参考答案：
 *
 * （1）交换 A、B：
 * BEGIN
 *     C = A
 *     A = B
 *     B = C
 * END
 *
 * （2）10个数找最大：
 * BEGIN
 *     INPUT x
 *     max = x
 *     FOR i = 2 TO 10
 *         INPUT x
 *         IF x > max THEN max = x
 *     END FOR
 *     PRINT max
 * END
 *
 * （3）3个数排序：
 * BEGIN
 *     INPUT a, b, c
 *     IF a > b THEN SWAP(a, b)
 *     IF a > c THEN SWAP(a, c)
 *     IF b > c THEN SWAP(b, c)
 *     PRINT a, b, c
 * END
 *
 * （4）1+2+...+100：
 * BEGIN
 *     sum = 0
 *     FOR i = 1 TO 100
 *         sum = sum + i
 *     END FOR
 *     PRINT sum
 * END
 *
 * （5）判断同时被3和5整除：
 * BEGIN
 *     INPUT n
 *     IF n % 3 == 0 AND n % 5 == 0 THEN
 *         PRINT "能"
 *     ELSE
 *         PRINT "不能"
 *     END IF
 * END
 *
 * （6）100~200间素数：
 * BEGIN
 *     FOR n = 100 TO 200
 *         flag = 1
 *         FOR i = 2 TO sqrt(n)
 *             IF n % i == 0 THEN
 *                 flag = 0
 *                 BREAK
 *             END IF
 *         END FOR
 *         IF flag == 1 THEN PRINT n
 *     END FOR
 * END
 *
 * （7）最大公约数（辗转相除）：
 * BEGIN
 *     INPUT m, n
 *     WHILE n != 0 DO
 *         r = m % n
 *         m = n
 *         n = r
 *     END WHILE
 *     PRINT m
 * END
 *
 * （8）求二次方程根：
 * BEGIN
 *     INPUT a, b, c
 *     delta = b*b - 4*a*c
 *     IF delta > 0 THEN
 *         x1 = (-b + sqrt(delta)) / (2*a)
 *         x2 = (-b - sqrt(delta)) / (2*a)
 *         PRINT x1, x2
 *     ELSE IF delta == 0 THEN
 *         x = -b / (2*a)
 *         PRINT x, "(重根)"
 *     ELSE
 *         PRINT "无实根"
 *     END IF
 * END
 */
