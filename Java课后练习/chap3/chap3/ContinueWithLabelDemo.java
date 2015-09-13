public class ContinueWithLabelDemo {
	public static void main(String[] args) {
		String searchMe = "Look for a substring in me";
		String substring = "sub";
		boolean foundIt = false;

		int max = searchMe.length() - substring.length();
		test: for (int i = 0; i <= max; i++) {
			int n = substring.length();
			int j = i; //i:子串查找开始位置; j:当前在主串中的查找位置
			int k = 0; //k:当前在子串中的查找位置
			while (n-- != 0) {
				// System.out.println(searchMe.charAt(j)+";"+substring.charAt(k));
				if (searchMe.charAt(j++) != substring.charAt(k++)) {
					continue test;
				}
			}
			foundIt = true;
			break test;
		}
		System.out.println(foundIt ? "Found it" : "Didn't find it");
	}
}
