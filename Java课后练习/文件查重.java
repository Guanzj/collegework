/*?	指定本地机器上的某个目录，实现：将这个目录下所有重复的文件列出
?	文件是否“重复”，不是由文件名决定的，而是由文件的二进制内容决定的。工具的实现可以直接对比文件的内容，也可以更高效地对比文件的md5、SHA1签名。
?	需要有界面（界面可参考软件“Fast Duplicate File Finder”）
?	需要支持多个查找任务（每一个任务对应于一个特定的文件系统目录。支持新任务的创建、任务的删除，任务列表在后台用配置文件保存）
*/
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Desktop;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Vector;
import java.util.regex.Pattern;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;
@SuppressWarnings("serial")
public class MainFrame extends Frame {

	private JPanel mainPanel;
	private JPanel headPanel;
	private JPanel bottomPanel;
	private JLabel tipLabel;
	private JTextField pathText;
	private JButton searchButton;
	private JButton searchoutButton;
	private JLabel searchoutTipLabel;
	private JScrollPane searchoutScroll;
	// 不能编辑的DefaultTableModel
	private DefaultTableModel tableModel = new DefaultTableModel() {
		public boolean isCellEditable(int row, int column) {
			return false;
		};
	};
	private JTable searchoutTable;
	private JButton delButton;
	// 遍历所有文件线程
	private SearchThread search;
	// 分析文件和输出到表格线程
	private SearchoutThread searchout;
	// 搜索目录集合
	private ArrayList<File> directory = new ArrayList<File>();
	// 遍历的所有文件,分析处理后前部分是符合条件File
	private Vector<File> allFiles = new Vector<File>();

	public static void main(String[] args) {
		@SuppressWarnings("unused")
		MainFrame mainFrame = new MainFrame("清理重复文件和空文件及空文件夹");
	}

	public MainFrame(String title) {
		super(title);
		init();
		pathText.requestFocus();
	}

	private void init() {

		mainPanel = new JPanel(new BorderLayout());
		headPanel = new JPanel(new BorderLayout());
		bottomPanel = new JPanel(new BorderLayout());
		add(mainPanel);
		mainPanel.add(headPanel, BorderLayout.NORTH);
		mainPanel.add(bottomPanel, BorderLayout.CENTER);

		tipLabel = new JLabel();
		tipLabel.setText("请输入查询的文件目录，多个文件目录用“;”隔开：");
		headPanel.add(tipLabel, BorderLayout.NORTH);

		pathText = new JTextField();
		// 输入回车开始搜索
		pathText.addKeyListener(new KeyAdapter() {
			@Override
			public void keyReleased(KeyEvent e) {
				if (e.getKeyCode() == KeyEvent.VK_ENTER) {
					searchButton.doClick();
				}
			}
		});
		headPanel.add(pathText, BorderLayout.CENTER);

		searchButton = new JButton();
		searchButton.setText("开始搜索");
		searchButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				if ("开始搜索".equals(searchButton.getText())) {
					// 获取用户输入的路径列表
					directory.clear();
					allFiles.clear();
					Util.cleanTableModel(tableModel);
					searchButton.setText("停止搜索");
					searchButton.setEnabled(true);
					delButton.setEnabled(false);
					// 将路径字符串中的路径符\改为通用路经符/
					String paths = MainFrame.this.pathText.getText().replace(
							'\\', '/');
					String path;
					char[] pathArray = paths.toCharArray();
					int start = 0;
					// 提取输入路径字符串中的有效路径构造File对象
					for (int i = 1; i < pathArray.length; i++) {
						if (pathArray[i] == ';' || pathArray[i] == '；'
								|| i == pathArray.length - 1) {
							File fileTemp;
							if (i == pathArray.length - 1
									&& pathArray[i] != ';'
									&& pathArray[i] != '；') {
								path = paths.substring(start);
								fileTemp = (pathArray[i] == ':' || pathArray[i] == '：') ? new File(
										path + "/")
										: new File(path);
							} else {
								path = paths.substring(start, i);
								fileTemp = (pathArray[i - 1] == ':' || pathArray[i - 1] == '：') ? new File(
										path + "/")
										: new File(path);
							}
							if (fileTemp.canExecute()) {
								directory.add(fileTemp);
								start = i + 1;
							} else {
								JOptionPane.showMessageDialog(null,
										"请输入正确的目录路径！", "错误",
										JOptionPane.ERROR_MESSAGE);
								pathText.setText("");
								pathText.requestFocus();
								searchButton.setText("开始搜索");
								return;
							}
						}
					}
					// 构造和初始化两个线程并启动
					System.out.println(File.listRoots()[0].getName());
					System.out.println(directory);
					search = new SearchThread(MainFrame.this, directory,
							allFiles);
					searchout = new SearchoutThread(MainFrame.this, allFiles);
					search.start();
					searchout.start();
				} else {
					searchButton.setText("开始搜索");
					search.stopSearchThread();
				}
			}

		});
		headPanel.add(searchButton, BorderLayout.EAST);

		searchoutButton = new JButton();
		searchoutButton.setText("停止分析");
		searchoutButton.setEnabled(false);
		searchoutButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				searchout.stopSearchoutThread();
			}
		});
		headPanel.add(searchoutButton, BorderLayout.SOUTH);

		searchoutTipLabel = new JLabel();
		searchoutTipLabel.setText("搜索结果：");
		bottomPanel.add(searchoutTipLabel, BorderLayout.NORTH);

		tableModel.addColumn("文件名");
		tableModel.addColumn("文件类型");
		tableModel.addColumn("文件大小");
		tableModel.addColumn("文件路径");

		searchoutTable = new JTable(tableModel);
		searchoutTable.setSelectionBackground(Color.YELLOW);
		searchoutTable.setVisible(true);
		searchoutTable.getColumn("文件类型").setMaxWidth(55);
		searchoutTable.getColumn("文件大小").setMaxWidth(70);
		searchoutTable.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				if (e.getKeyCode() == KeyEvent.VK_DELETE) {
					delButton.doClick();
				}
				if (e.getKeyCode() == KeyEvent.VK_ENTER) {
					for (int i : searchoutTable.getSelectedRows()) {
						Util.openFile((File) tableModel.getValueAt(i, 3));
					}
				}
			}
		});
		searchoutTable.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				if (e.getClickCount() == 2) {
					Util.openFile((File) tableModel.getValueAt(searchoutTable
							.getSelectedRow(), 3));
				}
			}
		});
		searchoutScroll = new JScrollPane(searchoutTable);
		bottomPanel.add(searchoutScroll, BorderLayout.CENTER);

		delButton = new JButton();
		delButton.setText("删除");
		delButton.setEnabled(false);
		delButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				Util.delFiles(MainFrame.this);
			}
		});
		bottomPanel.add(delButton, BorderLayout.SOUTH);

		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosed(WindowEvent e) {
				System.exit(0);
			}

			@Override
			public void windowClosing(WindowEvent e) {
				MainFrame.this.dispose();
			}
		});

		this.setVisible(true);
		this.pack();
	}

	public JButton getSearchButton() {
		return searchButton;
	}

	public JButton getSearchoutButton() {
		return searchoutButton;
	}

	public JLabel getSearchoutTipLabel() {
		return searchoutTipLabel;
	}

	public DefaultTableModel getTableModel() {
		return tableModel;
	}

	public JTable getSearchoutTable() {
		return searchoutTable;
	}

	public JButton getDelButton() {
		return delButton;
	}

}

// 遍历文件和文件夹线程
class SearchThread extends Thread {

	private MainFrame frame;
	private ArrayList<File> directory;
	private Vector<File> allFiles;
	private boolean next = true; // next决定是否继续遍历条件之一

	public SearchThread(MainFrame frame, ArrayList<File> dir, Vector<File> files) {
		this.frame = frame;
		this.directory = dir;
		this.allFiles = files;
	}

	public void stopSearchThread() {
		next = false;
	}

	// 递归算法遍历
	private void SearchFile(File file) {
		Util.addFile(allFiles, file);
		try{
			if (file.isDirectory() && next) {
				for (File filetemp : file.listFiles()) {
					SearchFile(filetemp);
				}
			}
		}catch(Exception e){
			JOptionPane.showMessageDialog(null, file.getPath()+"目录无法打开！", "错误",
					JOptionPane.ERROR_MESSAGE);
		}
	}

	@Override
	public void run() {
		next = true;
		frame.getSearchoutTipLabel().setText("正在搜索，请耐心等待...");
		while (next) {
			for (File file : directory) {
				SearchFile(file);
			}
			break;
		}
		// 同步信号量
		synchronized (Util.toNextThread) {
			Util.toNextThread.notify();
		}
	}
}

// 分析搜索结果和输出到表格线程
class SearchoutThread extends Thread {

	private Vector<File> allFiles;
	private MainFrame frame;
	private boolean next = true; // 决定是否继续分析搜索结果

	public SearchoutThread(MainFrame frame, Vector<File> files) {
		this.allFiles = files;
		this.frame = frame;
	}

	public void stopSearchoutThread() {
		next = false;
	}

	@Override
	public void run() {

		synchronized (Util.toNextThread) {
			try {
				Util.toNextThread.wait(); // 同步信号量
				next = true;
				frame.getSearchButton().setText("开始搜索");
				frame.getSearchButton().setEnabled(false);
				frame.getSearchoutButton().setEnabled(true);
				frame.getSearchoutButton().requestFocus();
				frame.getSearchoutTipLabel().setText("正在分析数据，请耐心等待...");

				boolean before, behide;
				int rows = 0;
				// 搜索结果是经过排序的，根据此规律删除不合要求File
				for (int i = 0; i < allFiles.size() && next; rows = ++i) {
					if (Util.isEmptyOrCopyFile(allFiles.get(i))) {
						continue;
					}
					if (i == 0) {
						before = true;
					} else {
						before = (allFiles.get(i).getName()
								.compareToIgnoreCase(
										allFiles.get(i - 1).getName()) != 0);
					}
					if (i == allFiles.size() - 1) {
						behide = true;
					} else {
						behide = (allFiles.get(i).getName()
								.compareToIgnoreCase(
										allFiles.get(i + 1).getName()) != 0);
					}
					if (allFiles.get(i).isDirectory() || (before && behide)) {
						allFiles.remove(i--);
					}

				}

				frame.getSearchoutButton().setEnabled(false);
				frame.getSearchoutTipLabel().setText("正在输出结果...");
				frame.getSearchoutTable().requestFocus();
				// 输出结果
				Util.addTableRows(frame, allFiles, rows);

				frame.getSearchoutTipLabel().setText("搜索结果：");
				frame.getSearchButton().setEnabled(true);
				frame.getDelButton().setEnabled(true);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}

class Util {

	public static String toNextThread = "NextThread";
	// 编译好正则表达式胡Pattern静态对象
	public static Pattern pattern = Pattern
			.compile("\\D*副本\\D*|\\D*复件\\D*|\\D*\\(\\d\\)\\D*");

	// 搜索输入文件和文件夹
	public static void addFile(Vector<File> allFiles, File file) {
		if (allFiles.isEmpty()) {
			allFiles.add(file);
		} else {

			/*
			 * //顺序查找法 for (int i = 0, size = allFiles.size(), compare; i <
			 * size; i++) { compare = file.getName().compareToIgnoreCase(
			 * allFiles.get(i).getName()); if (compare < 0) { allFiles.add(i,
			 * file); break; } if (i == size - 1) { if (compare >= 0) {
			 * allFiles.add(file); } } }
			 */

			// 二分查找法
			int left = 0, right = allFiles.size() - 1, middle, compare;
			if (file.getName().compareToIgnoreCase(
					allFiles.get(right).getName()) >= 0) {
				allFiles.add(file);
				return;
			}
			if (file.getName().compareToIgnoreCase(allFiles.get(0).getName()) <= 0) {
				allFiles.add(0, file);
				return;
			}
			while (true) {
				middle = (left + right) / 2;
				compare = file.getName().compareToIgnoreCase(
						allFiles.get(middle).getName());
				if (compare == 0 || middle == left) {
					allFiles.add(middle + 1, file);
					return;
				} else {
					if (compare < 0) {
						right = middle;
					} else {
						left = middle;
					}
				}
			}
		}
	}

	// 判断是否空文件或空文件夹或复件文件
	public static boolean isEmptyOrCopyFile(File file) {
		if (file.isFile()
				&& (file.length() == 0 || Util.pattern.matcher(file.getName())
						.matches())) {
			return true;
		}
		try{
			if (file.isDirectory() && file.listFiles().length == 0) {
				return true;
			}
		}catch(Exception e){
			JOptionPane.showMessageDialog(null, file.getPath()+"目录无法打开！", "错误",
					JOptionPane.ERROR_MESSAGE);
		}
		return false;
	}

	// 表格添加行
	public static void addTableRows(MainFrame frame, Vector<File> selectFiles,
			int rowsLength) {
		DefaultTableModel tableModel = frame.getTableModel();
		File file;
		for (int i = 0; i < rowsLength; i++) {
			file = selectFiles.get(i);
			tableModel.addRow(new Object[] {
					file.getName(),
					file.isDirectory() ? "空文件夹" : (Util.pattern.matcher(
							file.getName()).matches() ? "复制文件" : "文件"),
					file.length(), file });
		}
	}

	// 删除表格行和对应文件
	public static void delFiles(MainFrame frame) {
		JTable table = frame.getSearchoutTable();
		DefaultTableModel tableModel = frame.getTableModel();
		int[] select = table.getSelectedRows();
		if (select.length == 0) {
			JOptionPane.showMessageDialog(null, "请选择需要删除的文件或者文件夹！", "错误",
					JOptionPane.ERROR_MESSAGE);
			return;
		}
		if (JOptionPane.showConfirmDialog(null, "确定删除所选" + select.length
				+ "个文件或文件夹？", "数据无价，谨慎操作！", JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION) {
			for (int i = 0; i < select.length; i++) {
				((File) tableModel.getValueAt(select[i] - i, 3)).delete();
				tableModel.removeRow(select[i] - i);
			}
		}
	}

	// 清空表格
	public static void cleanTableModel(DefaultTableModel tableModel) {
		int length = tableModel.getRowCount();
		for (int i = 0; i < length; i++) {
			tableModel.removeRow(0);
		}
	}

	// 使用本地系统关联程序打开文件或文件夹,文件打开失败则打开文件所在文件夹
	public static void openFile(File file) {
		Desktop desktop = Desktop.getDesktop();
		try {
			desktop.open(file);
		} catch (IOException e) {
			JOptionPane.showMessageDialog(null, "文件打开失败！",
					"错误", JOptionPane.ERROR_MESSAGE);
			try {
				desktop.open(file.getParentFile());
			} catch (IOException e1) {
				e1.printStackTrace();
			}
			e.printStackTrace();
		}
	}
}