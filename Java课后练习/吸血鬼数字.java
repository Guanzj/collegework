/*使用列举法分别模拟两个乘数，进行乘法操作后，使用Arrays.sort()进行排序，再使用Arrays.equals()比较两字符串的内容，如果相等，即为吸血鬼数字。
四位吸血鬼数字有 
1395
1260
1827
2187
1530
1435
6880
*/

import java.util.Arrays;

public class xixuegui 
{	
	
	public static void solve() 
	{
		for (int a = 10; a < 100; a++) 
		{
			for (int b = a; b < 100; b++) 
			{
				int m = a * b;
				if ( m > 999 && m < 10000) 
				{
					String s1 = String.valueOf(m);
					String s2 = String.valueOf(a) + String.valueOf(b);
					char[] str1 = s1.toCharArray();
					char[] str2 = s2.toCharArray();
					Arrays.sort(str1);
					Arrays.sort(str2);
					if ( Arrays.equals(str1, str2) ) 
					{
						System.out.println(s1);
					}
				}
			}
		}
	}
	
	public static void main(String[] args) 
	{
		solve();
	}	
}
