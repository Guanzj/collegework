public class ShortCircuit {
	static boolean test1(int n) {
		System.out.println("test1 result:" + (n < 1));
		return (n < 1);
	}

	static boolean test2(int n) {
		System.out.println("test2 result:" + n < 2));
		return (n < 2);
	}

	static boolean test3(int n) {
		System.out.println("test3 result:" + (n < 3));
		return (n < 3);
	}

	public static void main(String[] args) {
		boolean b = test1(0) && test2(2) && test3(2);
		System.out.println("expression is " + b);
	}
}