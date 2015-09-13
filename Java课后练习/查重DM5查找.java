==========先定义一个接口==============
package com.xiatian.file;
import java.io.File;

public interface IDirHandle {

public void handle(File file);
}
==========md5工具类======================
package com.yinhai.xui.tools;

import java.security.MessageDigest;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class MD5Util {
// cache所有求过md5的内容
private static Map map = Collections.synchronizedMap(new HashMap());
public static void destroy() {
if(null != map)map.clear();
map = null;
}
public static String MD5(String s) {
if(null != map.get(s))return map.get(s).toString();
String s1 = MD5(s.getBytes());// "" + (map.size() + 1);
map.put(s, s1);
return s1;
}
public final static String MD5(byte []btInput) {
char hexDigits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
'A', 'B', 'C', 'D', 'E', 'F' };
try {
// MessageDigest mdInst = MessageDigest.getInstance("MD5");
// mdInst.update(btInput);
// byte[] md = mdInst.digest();
// int j = md.length;
// char str[] = new char[j * 2];
// int k = 0;
// for (int i = 0; i < j; i++) {
// byte byte0 = md[i];
// str[k++] = hexDigits[byte0 >>> 4 & 0xf];
// str[k++] = hexDigits[byte0 & 0xf];
// }
// return new String(str);
MessageDigest md5 = MessageDigest.getInstance("MD5");
   md5.update(btInput);
   return bytes2Hex(md5.digest());
} catch (Exception e) {
//if(org.apache.commons.logging.LogFactory.getLog(this.getClass()).isDebugEnabled())e.printStackTrace();
return null;
}
}
//将字节数组转换成16进制的字符串
private static String bytes2Hex(byte[] bts) {
String des = "";
String tmp = null;

for (int i = 0; i < bts.length; i++) {
tmp = (Integer.toHexString(bts[i] & 0xFF));
if (tmp.length() == 1) {
des += "0";
}
des += tmp;
}
return des;
}
public static void main(String[] args) {
System.out.print(MD5Util.MD5("AusITcim#1485"));
}
}

==========实现代码如下==========
package com.xiatian.file;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

import com.yinhai.xui.tools.MD5Util;

public class DirHandle implements IDirHandle{

private IDirHandle hd = null;
public DirHandle()
{
hd = this;
}
public DirHandle(IDirHandle h){hd = h;};
public void doFile(File f)
{
if(null != hd)
{
hd.handle(f);
}
}
public DirHandle doDir(String s)
{
File f = new File(s);
if(f.isFile())doFile(f);
else
{
File []fs = f.listFiles();
for(int i = 0, j = fs.length; i < j; i++)
{
if(fs[i].isFile())doFile(fs[i]);
else doDir(fs[i].getAbsolutePath());
}
}
return this;
}
public String getMd5(File f)
{
long lnSize = f.length();
long M100 = 1024 * 1024 * 100;
byte []b = new byte[3 * 1024 + (int)((lnSize / M100 + 1) * 10)];
int i = 0, j, p;
FileInputStream in = null;
try {
in  = new FileInputStream(f);
j = in.read(b, 0, p = i = 2 * 1024);
if(lnSize > M100 + 10)
while(j >= i)
{
in.skip(M100);
try
{
j = in.read(b, p, p += (i = 10));
} catch (Exception e) {
break;
}
}
// in.skip(-(lnSize - 1024));
// in.read(b, p, 1024);
return MD5Util.MD5(b);
} catch (Exception e) {
e.printStackTrace();
} 
finally
{
if(null != in)
try {
in.close();
} catch (IOException e) {
e.printStackTrace();
}
}
return null;
}
private Map size = new HashMap();
private Map md5 = new HashMap();
public void doCheck()
{
int i = size.size();
Iterator it = size.entrySet().iterator();
while(it.hasNext())
{
Map.Entry en = (Map.Entry)it.next();
List list = (List)en.getValue();
if(1 < list.size())
{
String s1 = (String)list.get(0);
String sMd1 = (String)md5.get(s1);
for(int x = 1, y = list.size(); x < y; x++)
{
String szFileName = (String)list.get(x);
if(sMd1.equals(md5.get(szFileName)))
{
System.out.println("@rem 同：" + s1 + "\r\ndel \"" + szFileName + "\"");
}
}
}
}
}
public void handle(File file)
{
long ln = file.length();
String sz = ln + "";
List mT = null;
if(null == (mT = (List)size.get(sz)))
{
size.put(sz, mT = new ArrayList());
}
mT.add(file.getAbsolutePath());
sz = getMd5(file);
md5.put(file.getAbsolutePath(), sz);
// System.out.println("@rem " + sz + " " + file.getAbsolutePath());
}
public static void main(String []a)
{
new DirHandle().doDir("D:/PPSDownload/电影/").doCheck();
}
}