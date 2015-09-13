/*1. 扩展“上机作业4”的功能，使用多个线程分别读取多个目录中指定扩展名的文件，并将其路径名打印出来。这些目录各自独立，不重合也不相互包含，在程序中用一个ArrayList保存这些目录。*/


package in.memori.multifilefinder;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/**
 * 基于广度优先算法的文件查找器
 */
public class MultiFileFinder {

	/**
	 * 查找文件。
	 * @param baseDirName		待查找的目录
	 * @param targetFileName	目标文件名，支持通配符形式
	 * @return		                              满足查询条件的文件名列表
	 */
	public static ArrayList<String> findFiles(String baseDirName, String targetFileName) {
		/**
		 * 算法简述：
		 * 从某个给定的需查找的文件夹出发，搜索该文件夹的所有子文件夹及文件，
		 * 若为文件，则进行匹配，匹配成功则加入结果集，若为子文件夹，则进队列。
		 * 队列不空，重复上述操作，队列为空，程序结束，返回结果。
		 */
		ArrayList<String> fileList = new ArrayList<String>();
		File baseDir = new File(baseDirName);
		//判断目录是否存在
		if (!baseDir.exists() || !baseDir.isDirectory()){
			System.out.println("File searching failed:" + baseDirName + "is not a directory!");
			return fileList;
		}
		String tempName = null;
		//创建一个队列
		Queue<File> queue = new LinkedList<File>();//实例化队列 
		queue.offer(baseDir);//入队 
		File tempFile = null;
		while (!queue.isEmpty()) {
			//从队列中取目录
			tempFile = (File)queue.poll();
			if (tempFile.exists() && tempFile.isDirectory()) {
				File[] files = tempFile.listFiles();
				for (int i = 0; i < files.length; i++) {
					//如果是目录则放进队列
					if (files[i].isDirectory()) { 
						queue.offer(files[i]);
					} else {
						//如果是文件则根据文件名与目标文件名进行匹配 
						tempName =  files[i].getName(); 
						if (tempName.matches(".*." + targetFileName +"$")) {
							//匹配成功，将文件名添加到结果集
							fileList.add(files[i].getAbsolutePath()); 
						}
					}
				}
			} 
		}
		return fileList;
	}


	public static void main(String[] args) throws IOException {
		ArrayList<String> dir = new ArrayList<String>();
		Logger log = new Logger();
		OwnThread t1 = new OwnThread("C:\\temp", "txt", dir, log);
		OwnThread t2 = new OwnThread("C:\\temp2", "java", dir, log);
		t1.start();
		t2.start();
		
		while(t1.isAlive() || t2.isAlive());     //等待两线程执行结束
		for(int i = 0; i < dir.size(); i++)
			System.out.println(dir.get(i));
		log.output();
	}
}

class OwnThread extends Thread {
	String path, type;
	ArrayList<String> dir;
	Logger log;
	OwnThread(String path, String type, ArrayList<String> dir, Logger log) {
		this.path = path;
		this.type = type;
		this.dir = dir;
		this.log = log;
	}
	public void run() {
		ArrayList<String> resultList = MultiFileFinder.findFiles(path, type); 
		if (resultList.size() == 0) {
			System.out.println("No File Found.");
		} else {
			for (int i = 0; i < resultList.size(); i++) { 
				synchronized(log) {
				dir.add(resultList.get(i));
				log.add(resultList.get(i));
				}
			}
		}
	}
}



