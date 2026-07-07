/*
python溢出时会升位数，其他语言会丢弃  (n << shift_amount) & 0xFFFFFFFF
0xFFFFFFFF表示32个1，F表示1111（十六进制的15）

 先来一个好玩的问题：
袋子里一共a个白球，b个黑球，每次从袋子里拿2个球，每个球每次被拿出机会均等
如果拿出的是2个白球、或者2个黑球，那么就往袋子里重新放入1个白球
如果拿出的是1个白球和1个黑球，那么就往袋子里重新放入1个黑球
那么最终袋子里一定会只剩1个球，请问最终的球是黑的概率是多少？用a和b来表达这个概率。

被镇住了吧？其实这题是一个陷阱。

答案：
黑球的数量如果是偶数，最终的球是黑的概率是0%
黑球的数量如果是奇数，最终的球是黑的概率是100%
完全和白球的数量无关。为啥？异或运算的性质了解之后，就了解了。

异或运算的性质
1. 异或运算就是无进位相加
2. 满足交换律和结合律   同一批数字异或的结果相同
3. 0^n = n n^n = 0  若a^b=c，则a^c=b，b^c=a
4. (最常考)若整体异或为x，某局部异或结果y，则余下部分异或结果为x^y

以上问题理解为：白0黑1  则a个0与b个1异或
*/

// 题目一：用异或运算交换两数的值
public class Code01_SwapExclusiveOr {

	public static void main(String[] args) {
		int a = -2323;
		int b = 10;
		a = a ^ b;
		b = a ^ b;  //(a ^ b) ^ b = a
		a = a ^ b;  //(a ^ b) ^ a = b
		System.out.println(a);
		System.out.println(b);

		int[] arr = { 3, 5 };
		swap(arr, 0, 1);
		System.out.println(arr[0]);
		System.out.println(arr[1]);
		swap(arr, 0, 0);
		System.out.println(arr[0]);
	}
    //当i != j时，交换arr[i]和arr[j]的值
    //当i == j时，交换arr[i]和arr[j]的值会导致arr[i]变为0
    // 所以知道这种写法即可，并不推荐
	public static void swap(int[] arr, int i, int j) {
		arr[i] = arr[i] ^ arr[j];
		arr[j] = arr[i] ^ arr[j];
		arr[i] = arr[i] ^ arr[j];
	}
}

// 题目二：不用任何判断语句和比较操作，返回两个数的最大值
// 测试链接 : https://www.nowcoder.com/practice/d2707eaf98124f1e8f1d9c18ad487f76
//二进制最高位1表示负数 0表示正数
public class Code02_GetMaxWithoutJudge {

	// 必须保证n一定是0或者1
	// 0变1，1变0
	public static int flip(int n) {
		return n ^ 1;
	}

	// 非负数返回1(0^1=1)
	// 负数返回0(1^1=0)
	public static int sign(int n) {
		return flip(n >>> 31);  //无符号右移
	}

	// 有溢出风险的实现
	public static int getMax1(int a, int b) {
		int c = a - b;
		// c非负，returnA -> 1
		// c非负，returnB -> 0
		// c负数，returnA -> 0
		// c负数，returnB -> 1
		int returnA = sign(c);
		int returnB = flip(returnA);
		return a * returnA + b * returnB;
	}

	// 没有任何问题的实现
	public static int getMax2(int a, int b) {
		// c可能是溢出的
		int c = a - b;
		// a的符号
		int sa = sign(a);
		// b的符号
		int sb = sign(b);
		// c的符号
		int sc = sign(c);
		// 判断A和B，符号是不是不一样，如果不一样diffAB=1，如果一样diffAB=0
		int diffAB = sa ^ sb;
		// 判断A和B，符号是不是一样，如果一样sameAB=1，如果不一样sameAB=0
		int sameAB = flip(diffAB);
        //returnA的情况：a b异号且a非负(diffAB=1 sa=1) 或者 a b同号且a-b非负(sameAB=1 sc=1)
		int returnA = diffAB * sa + sameAB * sc;
        //returnB的情况：a b异号且b非负(diffAB=1 sb=1) 或者 a b同号且a-b为负(sameAB=1 sc=0)
        //也可以直接用returnB = flip(returnA)来表示
		int returnB = flip(returnA);
		return a * returnA + b * returnB;
	}

	public static void main(String[] args) {
		int a = Integer.MIN_VALUE;
		int b = Integer.MAX_VALUE;
		// getMax1方法会错误，因为溢出
		System.out.println(getMax1(a, b));
		// getMax2方法永远正确
		System.out.println(getMax2(a, b));
	}

}