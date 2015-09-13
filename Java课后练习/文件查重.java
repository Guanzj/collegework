/*?	ָ�����ػ����ϵ�ĳ��Ŀ¼��ʵ�֣������Ŀ¼�������ظ����ļ��г�
?	�ļ��Ƿ��ظ������������ļ��������ģ��������ļ��Ķ��������ݾ����ġ����ߵ�ʵ�ֿ���ֱ�ӶԱ��ļ������ݣ�Ҳ���Ը���Ч�ضԱ��ļ���md5��SHA1ǩ����
?	��Ҫ�н��棨����ɲο������Fast Duplicate File Finder����
?	��Ҫ֧�ֶ����������ÿһ�������Ӧ��һ���ض����ļ�ϵͳĿ¼��֧��������Ĵ����������ɾ���������б��ں�̨�������ļ����棩
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
	// ���ܱ༭��DefaultTableModel
	private DefaultTableModel tableModel = new DefaultTableModel() {
		public boolean isCellEditable(int row, int column) {
			return false;
		};
	};
	private JTable searchoutTable;
	private JButton delButton;
	// ���������ļ��߳�
	private SearchThread search;
	// �����ļ������������߳�
	private SearchoutThread searchout;
	// ����Ŀ¼����
	private ArrayList<File> directory = new ArrayList<File>();
	// �����������ļ�,���������ǰ�����Ƿ�������File
	private Vector<File> allFiles = new Vector<File>();

	public static void main(String[] args) {
		@SuppressWarnings("unused")
		MainFrame mainFrame = new MainFrame("�����ظ��ļ��Ϳ��ļ������ļ���");
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
		tipLabel.setText("�������ѯ���ļ�Ŀ¼������ļ�Ŀ¼�á�;��������");
		headPanel.add(tipLabel, BorderLayout.NORTH);

		pathText = new JTextField();
		// ����س���ʼ����
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
		searchButton.setText("��ʼ����");
		searchButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				if ("��ʼ����".equals(searchButton.getText())) {
					// ��ȡ�û������·���б�
					directory.clear();
					allFiles.clear();
					Util.cleanTableModel(tableModel);
					searchButton.setText("ֹͣ����");
					searchButton.setEnabled(true);
					delButton.setEnabled(false);
					// ��·���ַ����е�·����\��Ϊͨ��·����/
					String paths = MainFrame.this.pathText.getText().replace(
							'\\', '/');
					String path;
					char[] pathArray = paths.toCharArray();
					int start = 0;
					// ��ȡ����·���ַ����е���Ч·������File����
					for (int i = 1; i < pathArray.length; i++) {
						if (pathArray[i] == ';' || pathArray[i] == '��'
								|| i == pathArray.length - 1) {
							File fileTemp;
							if (i == pathArray.length - 1
									&& pathArray[i] != ';'
									&& pathArray[i] != '��') {
								path = paths.substring(start);
								fileTemp = (pathArray[i] == ':' || pathArray[i] == '��') ? new File(
										path + "/")
										: new File(path);
							} else {
								path = paths.substring(start, i);
								fileTemp = (pathArray[i - 1] == ':' || pathArray[i - 1] == '��') ? new File(
										path + "/")
										: new File(path);
							}
							if (fileTemp.canExecute()) {
								directory.add(fileTemp);
								start = i + 1;
							} else {
								JOptionPane.showMessageDialog(null,
										"��������ȷ��Ŀ¼·����", "����",
										JOptionPane.ERROR_MESSAGE);
								pathText.setText("");
								pathText.requestFocus();
								searchButton.setText("��ʼ����");
								return;
							}
						}
					}
					// ����ͳ�ʼ�������̲߳�����
					System.out.println(File.listRoots()[0].getName());
					System.out.println(directory);
					search = new SearchThread(MainFrame.this, directory,
							allFiles);
					searchout = new SearchoutThread(MainFrame.this, allFiles);
					search.start();
					searchout.start();
				} else {
					searchButton.setText("��ʼ����");
					search.stopSearchThread();
				}
			}

		});
		headPanel.add(searchButton, BorderLayout.EAST);

		searchoutButton = new JButton();
		searchoutButton.setText("ֹͣ����");
		searchoutButton.setEnabled(false);
		searchoutButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				searchout.stopSearchoutThread();
			}
		});
		headPanel.add(searchoutButton, BorderLayout.SOUTH);

		searchoutTipLabel = new JLabel();
		searchoutTipLabel.setText("���������");
		bottomPanel.add(searchoutTipLabel, BorderLayout.NORTH);

		tableModel.addColumn("�ļ���");
		tableModel.addColumn("�ļ�����");
		tableModel.addColumn("�ļ���С");
		tableModel.addColumn("�ļ�·��");

		searchoutTable = new JTable(tableModel);
		searchoutTable.setSelectionBackground(Color.YELLOW);
		searchoutTable.setVisible(true);
		searchoutTable.getColumn("�ļ�����").setMaxWidth(55);
		searchoutTable.getColumn("�ļ���С").setMaxWidth(70);
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
		delButton.setText("ɾ��");
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

// �����ļ����ļ����߳�
class SearchThread extends Thread {

	private MainFrame frame;
	private ArrayList<File> directory;
	private Vector<File> allFiles;
	private boolean next = true; // next�����Ƿ������������֮һ

	public SearchThread(MainFrame frame, ArrayList<File> dir, Vector<File> files) {
		this.frame = frame;
		this.directory = dir;
		this.allFiles = files;
	}

	public void stopSearchThread() {
		next = false;
	}

	// �ݹ��㷨����
	private void SearchFile(File file) {
		Util.addFile(allFiles, file);
		try{
			if (file.isDirectory() && next) {
				for (File filetemp : file.listFiles()) {
					SearchFile(filetemp);
				}
			}
		}catch(Exception e){
			JOptionPane.showMessageDialog(null, file.getPath()+"Ŀ¼�޷��򿪣�", "����",
					JOptionPane.ERROR_MESSAGE);
		}
	}

	@Override
	public void run() {
		next = true;
		frame.getSearchoutTipLabel().setText("���������������ĵȴ�...");
		while (next) {
			for (File file : directory) {
				SearchFile(file);
			}
			break;
		}
		// ͬ���ź���
		synchronized (Util.toNextThread) {
			Util.toNextThread.notify();
		}
	}
}

// ����������������������߳�
class SearchoutThread extends Thread {

	private Vector<File> allFiles;
	private MainFrame frame;
	private boolean next = true; // �����Ƿ���������������

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
				Util.toNextThread.wait(); // ͬ���ź���
				next = true;
				frame.getSearchButton().setText("��ʼ����");
				frame.getSearchButton().setEnabled(false);
				frame.getSearchoutButton().setEnabled(true);
				frame.getSearchoutButton().requestFocus();
				frame.getSearchoutTipLabel().setText("���ڷ������ݣ������ĵȴ�...");

				boolean before, behide;
				int rows = 0;
				// ��������Ǿ�������ģ����ݴ˹���ɾ������Ҫ��File
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
				frame.getSearchoutTipLabel().setText("����������...");
				frame.getSearchoutTable().requestFocus();
				// ������
				Util.addTableRows(frame, allFiles, rows);

				frame.getSearchoutTipLabel().setText("���������");
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
	// �����������ʽ��Pattern��̬����
	public static Pattern pattern = Pattern
			.compile("\\D*����\\D*|\\D*����\\D*|\\D*\\(\\d\\)\\D*");

	// ���������ļ����ļ���
	public static void addFile(Vector<File> allFiles, File file) {
		if (allFiles.isEmpty()) {
			allFiles.add(file);
		} else {

			/*
			 * //˳����ҷ� for (int i = 0, size = allFiles.size(), compare; i <
			 * size; i++) { compare = file.getName().compareToIgnoreCase(
			 * allFiles.get(i).getName()); if (compare < 0) { allFiles.add(i,
			 * file); break; } if (i == size - 1) { if (compare >= 0) {
			 * allFiles.add(file); } } }
			 */

			// ���ֲ��ҷ�
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

	// �ж��Ƿ���ļ�����ļ��л򸴼��ļ�
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
			JOptionPane.showMessageDialog(null, file.getPath()+"Ŀ¼�޷��򿪣�", "����",
					JOptionPane.ERROR_MESSAGE);
		}
		return false;
	}

	// ��������
	public static void addTableRows(MainFrame frame, Vector<File> selectFiles,
			int rowsLength) {
		DefaultTableModel tableModel = frame.getTableModel();
		File file;
		for (int i = 0; i < rowsLength; i++) {
			file = selectFiles.get(i);
			tableModel.addRow(new Object[] {
					file.getName(),
					file.isDirectory() ? "���ļ���" : (Util.pattern.matcher(
							file.getName()).matches() ? "�����ļ�" : "�ļ�"),
					file.length(), file });
		}
	}

	// ɾ������кͶ�Ӧ�ļ�
	public static void delFiles(MainFrame frame) {
		JTable table = frame.getSearchoutTable();
		DefaultTableModel tableModel = frame.getTableModel();
		int[] select = table.getSelectedRows();
		if (select.length == 0) {
			JOptionPane.showMessageDialog(null, "��ѡ����Ҫɾ�����ļ������ļ��У�", "����",
					JOptionPane.ERROR_MESSAGE);
			return;
		}
		if (JOptionPane.showConfirmDialog(null, "ȷ��ɾ����ѡ" + select.length
				+ "���ļ����ļ��У�", "�����޼ۣ�����������", JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION) {
			for (int i = 0; i < select.length; i++) {
				((File) tableModel.getValueAt(select[i] - i, 3)).delete();
				tableModel.removeRow(select[i] - i);
			}
		}
	}

	// ��ձ��
	public static void cleanTableModel(DefaultTableModel tableModel) {
		int length = tableModel.getRowCount();
		for (int i = 0; i < length; i++) {
			tableModel.removeRow(0);
		}
	}

	// ʹ�ñ���ϵͳ����������ļ����ļ���,�ļ���ʧ������ļ������ļ���
	public static void openFile(File file) {
		Desktop desktop = Desktop.getDesktop();
		try {
			desktop.open(file);
		} catch (IOException e) {
			JOptionPane.showMessageDialog(null, "�ļ���ʧ�ܣ�",
					"����", JOptionPane.ERROR_MESSAGE);
			try {
				desktop.open(file.getParentFile());
			} catch (IOException e1) {
				e1.printStackTrace();
			}
			e.printStackTrace();
		}
	}
}