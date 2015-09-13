/*1. ��չ���ϻ���ҵ4���Ĺ��ܣ�ʹ�ö���̷ֱ߳��ȡ���Ŀ¼��ָ����չ�����ļ���������·������ӡ��������ЩĿ¼���Զ��������غ�Ҳ���໥�������ڳ�������һ��ArrayList������ЩĿ¼��*/


package in.memori.multifilefinder;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/**
 * ���ڹ�������㷨���ļ�������
 */
public class MultiFileFinder {

	/**
	 * �����ļ���
	 * @param baseDirName		�����ҵ�Ŀ¼
	 * @param targetFileName	Ŀ���ļ�����֧��ͨ�����ʽ
	 * @return		                              �����ѯ�������ļ����б�
	 */
	public static ArrayList<String> findFiles(String baseDirName, String targetFileName) {
		/**
		 * �㷨������
		 * ��ĳ������������ҵ��ļ��г������������ļ��е��������ļ��м��ļ���
		 * ��Ϊ�ļ��������ƥ�䣬ƥ��ɹ��������������Ϊ���ļ��У�������С�
		 * ���в��գ��ظ���������������Ϊ�գ�������������ؽ����
		 */
		ArrayList<String> fileList = new ArrayList<String>();
		File baseDir = new File(baseDirName);
		//�ж�Ŀ¼�Ƿ����
		if (!baseDir.exists() || !baseDir.isDirectory()){
			System.out.println("File searching failed:" + baseDirName + "is not a directory!");
			return fileList;
		}
		String tempName = null;
		//����һ������
		Queue<File> queue = new LinkedList<File>();//ʵ�������� 
		queue.offer(baseDir);//��� 
		File tempFile = null;
		while (!queue.isEmpty()) {
			//�Ӷ�����ȡĿ¼
			tempFile = (File)queue.poll();
			if (tempFile.exists() && tempFile.isDirectory()) {
				File[] files = tempFile.listFiles();
				for (int i = 0; i < files.length; i++) {
					//�����Ŀ¼��Ž�����
					if (files[i].isDirectory()) { 
						queue.offer(files[i]);
					} else {
						//������ļ�������ļ�����Ŀ���ļ�������ƥ�� 
						tempName =  files[i].getName(); 
						if (tempName.matches(".*." + targetFileName +"$")) {
							//ƥ��ɹ������ļ�����ӵ������
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
		
		while(t1.isAlive() || t2.isAlive());     //�ȴ����߳�ִ�н���
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



