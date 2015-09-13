/*实现一个程序，该程序的输入是一个目录字符串和一个文件扩展名字符串，程序递归地搜索该目录及其各级子目录，在这些目录中查找所有扩展名与指定扩展名相同的文件，将这些文件的相对路径名记录下来并向控制台输出。
具体实现：
1.	输入一个目录字符串（相对路径）和一个文件扩展名字符串；
2.	输出具有相同扩展名的文件的相对路径（目录字符串）。
程序要点：
1.	读取相关信息并和其他文件比较
2.	比较过程中使用递归扫描下一级目录及文件
3.	返回当前目录字符串
递归实现：
1.	判断当前file是否是文件，若是与给定扩展名比较
2.	若不是，继续扫描该目录下的文件，并依次和各文件进行对比，执行（1）。
*/

package search;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;

public class Search 
{	//判断并返回扩展名
	public static String getExtensionName(String filename) 
	{   
        	if ((filename != null) && (filename.length() > 0)) 
		{   
            		int dot = filename.lastIndexOf('.');   
            			if ((dot >-1) && (dot < (filename.length() - 1))) 
				{   
                			return filename.substring(dot + 1);   
            			}   
        	}   
        	return filename;
    	}   
	//比较扩展名并返回文件目录
	public static void search (File n,String m)
	{
		if(n.isFile())//判断文件
		{
			if(m.equals(getExtensionName(n.getName())))
				System.out.println(n.getPath());//返回相对路径
		}
		else//*****************递归部分***************************
		{
			String a[]=n.list();
			if(a!=null)
			{
				File b[]=new File[a.length];
				for(int i=0;i<a.length;i++)
				{
					b[i]=new File(n,a[i]);
					search(b[i],m);
				}
			}
		}
	}
	

	public static void main(String [] agrs)
	{
		String path=" ";
		String extensionname=" ";
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("please input path ");
		try{
			path=in.readLine();
		}catch(IOException e){e.printStackTrace();}//读取路径
		System.out.println("please input extensionname ");
		try
		{
			extensionname=in.readLine();
			in.close();
		}catch(IOException e){e.printStackTrace();}//读取文件扩展名
		
		File n=new File(path);
		search(n,extensionname);
		}
	}
