public class ContinueWithLabelDemo {
	public static void main(String[] args) {
		String searchMe = "Look for a substring in me";
		String substring = "sub";
		boolean foundIt = false;

		int max = searchMe.length() - substring.length();
		test: for (int i = 0; i <= max; i++) {
			int n = substring.length();
			int j = i; //i:�Ӵ����ҿ�ʼλ��; j:��ǰ�������еĲ���λ��
			int k = 0; //k:��ǰ���Ӵ��еĲ���λ��
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
