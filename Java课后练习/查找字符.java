public class chuxaincishu {	
	public static void main(String[] args) {
		String str = "Java is my favorite programming language";
		int cishu = 0;
		for (int i = 0; i < str.length(); i++) {
			if ( str.charAt(i) == 'a' ) {
				cishu++;
			}
		}
		System.out.println(cishu);
	}	
}

//设变量cishu记录该字符串中a出现的次数，初始化为0，然后是字符串中的字符一一与a比较，若相同则cishu+1.最后返回cishu的值即为所求
