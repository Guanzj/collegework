/*1、使用LInkedList实现一个类，该类有一个方法，该方法接受一个字符串作为参数，依次读取字符串中的字符，每次遇到“+”时就将“+”后面的一个字符压入栈中，每次遇到“-”时就将当前栈顶的字符弹出并在控制台打印，直至字符串遍历完，最后输出栈上剩余内容。实现main()方法调用这个方法，并传入字符串“+U+n+c---+e+r+t---+a-+i-+n+t+y---+-+r+u--+l+e+s---”，观察输出。*/

package linklist_stack;
import java.util.*;
public class linklist{
	 List<Character> ll=new LinkedList<Character>();
     void EampleF(String ExampleStr){
        	 for(int i=0;i<ExampleStr.length();i++)
        	 {
        		 if(ExampleStr.charAt(i)=='+')
        			 ll.add(ExampleStr.charAt(i+1)); 
        		 else if(ExampleStr.charAt(i)=='-')
        		 {     
        			   for(int b=ll.size()-1;b>=0;b--)
        			   {
        				 System.out.print(ll.get(b)); 
        				 ll.remove(b);
        			   }
        		 } 
        		 else continue;
        	 }
			 for(int b=0;b<ll.size();b++)
				 System.out.print(ll.get(b));	  	 
    }
	public static void main(String[] args) {	
		linklist eol=new linklist();
		eol.EampleF("+U+n+c---+e+r+t---+a-+i-+n+t+y---+-+r+u--+l+e+s---");
	}
}
