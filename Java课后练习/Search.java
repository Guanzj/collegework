/*ʵ��һ�����򣬸ó����������һ��Ŀ¼�ַ�����һ���ļ���չ���ַ���������ݹ��������Ŀ¼���������Ŀ¼������ЩĿ¼�в���������չ����ָ����չ����ͬ���ļ�������Щ�ļ������·������¼�����������̨�����
����ʵ�֣�
1.	����һ��Ŀ¼�ַ��������·������һ���ļ���չ���ַ�����
2.	���������ͬ��չ�����ļ������·����Ŀ¼�ַ�������
����Ҫ�㣺
1.	��ȡ�����Ϣ���������ļ��Ƚ�
2.	�ȽϹ�����ʹ�õݹ�ɨ����һ��Ŀ¼���ļ�
3.	���ص�ǰĿ¼�ַ���
�ݹ�ʵ�֣�
1.	�жϵ�ǰfile�Ƿ����ļ��������������չ���Ƚ�
2.	�����ǣ�����ɨ���Ŀ¼�µ��ļ��������κ͸��ļ����жԱȣ�ִ�У�1����
*/

package search;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;

public class Search 
{	//�жϲ�������չ��
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
	//�Ƚ���չ���������ļ�Ŀ¼
	public static void search (File n,String m)
	{
		if(n.isFile())//�ж��ļ�
		{
			if(m.equals(getExtensionName(n.getName())))
				System.out.println(n.getPath());//�������·��
		}
		else//*****************�ݹ鲿��***************************
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
		}catch(IOException e){e.printStackTrace();}//��ȡ·��
		System.out.println("please input extensionname ");
		try
		{
			extensionname=in.readLine();
			in.close();
		}catch(IOException e){e.printStackTrace();}//��ȡ�ļ���չ��
		
		File n=new File(path);
		search(n,extensionname);
		}
	}
