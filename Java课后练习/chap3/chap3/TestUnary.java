public class TestUnary {

	public static void main(String args[]) {
		short a = 9;
		int b = -a;
		System.out.println("a = " + a);
		System.out.println("b = " + b);
		
		byte bb = 9;
		int ib = +bb;
		System.out.println("bb = " + bb);
		System.out.println("ib = " + ib);
		
		int i = 0;
		int j = i++;
		int k = ++j;
		System.out.println("i = " + i);
		System.out.println("j = " + j);
		System.out.println("k = " + k);
		
		int x = 4, y = 8;
		int z = (x++) * (--y);
		System.out.println("x = " + x);
		System.out.println("y = " + y);
		System.out.println("z = " + z);
	}
}
