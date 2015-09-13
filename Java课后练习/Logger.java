/*2. 实现一个日志管理类Logger，这个日志管理类的实例对象能够保护一个唯一输出字符流，该输出字符流能够向唯一的日志文件写数据。第1问中实现的各个线程同步使用日志管理对象，将各自扫描得到的文件路径名写入到该日志文件中。*/

package in.memori.multifilefinder;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;

public class Logger {
	ArrayList<String> log;
	public Logger() {
		log = new ArrayList<String>();
	}
	public void add(String str){
		log.add(str);
	}
	public void output() throws IOException {
        OutputStream fOut = new FileOutputStream(new File("output.txt"));
        for(String Str:log)
        	fOut.write((Str+"\r\n").getBytes());
        fOut.close();
	}
}
