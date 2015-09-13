public class A{
	public static void main(String []args){
		int a=12345;
		int result=0;
		while (a>0){
			result+=a%10;
			a/=10;
		}
		System.out.println(result);
	}
}