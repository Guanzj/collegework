using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
namespace KNN
{
	public partial class KNNMainWindow : Window
	{
		public float[, ] class1 = new float[27, 9];
		public float[, ] class2 = new float[27, 9];
		public float[, ] class3 = new float[27, 9];
		public float[, ] sample = new float[10, 8];
		public int classes = 0;
		public KNNMainWindow()
		{
			InitializeComponent();
			InitializeData();
		}
		private void buttonSort_Click(object sender, RoutedEventArgs e)
		{
			string outputline = '\t' + txtPHvalue.Text + '\t' + txtJDvalue.Text + '\t' + txtNH4value.Text + '\t' + txtCODvalue.Text + '\t' +
				txtBODvalue.Text + '\t' + txtSSvalue.Text + '\t' + txtXTDvalue.Text + '\t';
			txtOutput.LineDown();
			txtOutput.AppendText('\t' + "PH值" + '\t' + "碱度" + '\t' + "氨氮" + '\t' + "COD" + '\t' + "BOD" + '\t' + "SS" + "    " + "硝态氮" + '\t' + "类别" + '\n');
			txtOutput.AppendText(outputline);
			knnsf(float.Parse(txtPHvalue.Text), float.Parse(txtJDvalue.Text), float.Parse(txtNH4value.Text), float.Parse(txtCODvalue.Text),
				float.Parse(txtBODvalue.Text), float.Parse(txtSSvalue.Text), float.Parse(txtXTDvalue.Text));
			int classesb = classes;
			txtOutput.AppendText(" " + classesb.ToString() + "\n");
		}
		public void knnsf(float PH, float JD, float NH4, float COD, float BOD, float SS, float XTD)
		{
			double[, ] kn = new double[81, 2];
			int a = 0, b = 0, c = 0;
			//计算欧氏距离
			for (int i = 0; i < 27; i++)
			{
				kn[i, 0] = Math.Sqrt(Math.Pow(class1[i, 1] - PH, 2) + Math.Pow(class1[i, 2] - JD, 2) + Math.Pow(class1[i, 3] - NH4, 2) +
					Math.Pow(class1[i, 4] - COD, 2) + Math.Pow(class1[i, 5] - BOD, 2) + Math.Pow(class1[i, 6] - SS, 2) +
					Math.Pow(class1[i, 7] - XTD, 2));
				kn[i, 1] = 1;

				kn[i + 27, 0] = Math.Sqrt(Math.Pow(class2[i, 1] - PH, 2) + Math.Pow(class2[i, 2] - JD, 2) + Math.Pow(class2[i, 3] - NH4, 2) +
					Math.Pow(class2[i, 4] - COD, 2) + Math.Pow(class2[i, 5] - BOD, 2) + Math.Pow(class2[i, 6] - SS, 2) +
					Math.Pow(class2[i, 7] - XTD, 2));
				kn[i + 27, 1] = 2;

				kn[i + 54, 0] = Math.Sqrt(Math.Pow(class3[i, 1] - PH, 2) + Math.Pow(class3[i, 2] - JD, 2) + Math.Pow(class3[i, 3] - NH4, 2) +
					Math.Pow(class3[i, 4] - COD, 2) + Math.Pow(class3[i, 5] - BOD, 2) + Math.Pow(class3[i, 6] - SS, 2) +
					Math.Pow(class3[i, 7] - XTD, 2));
				kn[i + 54, 1] = 3;
			}
			//选择排序法
			for (int i = 0; i < 81; i++)
			{
				int k = 0;
				double mintmp = kn[i, 0], clas = kn[i, 1];
				for (int j = i + 1; j < 81; j++)
				{
					if (mintmp > kn[j, 0])
					{
						mintmp = kn[j, 0];
						clas = kn[j, 1];
						k = j;
					}
				}
				kn[k, 0] = kn[i, 0];
				kn[k, 1] = kn[i, 1];
				kn[i, 0] = mintmp;
				kn[i, 1] = clas;
			}
			//选择K=30个近邻
			for (int k = 0; k < 3; k++)
			{
				if (kn[k, 1] == 1) a++;
				if (kn[k, 1] == 2) b++;
				if (kn[k, 1] == 3) c++;
			}
			//统计近邻类别
			if (a > b && a > c)
			{
				classes = 1;
			}
			if (b > a && b > c)
			{
				classes = 2;
			}
			if (c > b && c > a)
			{
				classes = 3;
			}
		}
		private void InitializeData()
		{
			try
			{
				using (StreamReader train1 = new StreamReader("train1.txt"))
				{
					String line;
					int m = 0, n = 0;
					txtOutput.AppendText("\n------------------------------第一类样本------------------------------\n");
					txtOutput.AppendText('\t' + "PH值" + '\t' + "碱度" + '\t' + "氨氮" + '\t' + "COD" + '\t' + "BOD" + '\t' + "SS" + "    " + "硝态氮" + '\t' + "类别" + '\n');
					while ((line = train1.ReadLine()) != null)
					{
						for (int i = 0, j = 0; i < line.Length; i++, j++)
						{
							if ((line[i] == '\t') && (j != 0))
							{
								class1[m, n] = float.Parse(line.Substring(i - j, j));
								txtOutput.AppendText(line.Substring(i - j, j));
								n++;
								j = 0;
							}
						}
						class1[m, 8] = 1;
						knnsf(class1[m, 1], class1[m, 2], class1[m, 3], class1[m, 4], class1[m, 5], class1[m, 6], class1[m, 7]);
						int classesa = classes;
						txtOutput.AppendText('\t' + " " + classesa.ToString());
						m++;
						n = 0;
						txtOutput.AppendText("\n");
						txtOutput.PageDown();
					}
				}
				using (StreamReader train2 = new StreamReader("train2.txt"))
				{
					String line;
					int m = 0, n = 0;
					txtOutput.AppendText("\n------------------------------第二类样本------------------------------\n");
					txtOutput.AppendText('\t' + "PH值" + '\t' + "碱度" + '\t' + "氨氮" + '\t' + "COD" + '\t' + "BOD" + '\t' + "SS" + "    " + "硝态氮" + '\t' + "类别" + '\n');
					while ((line = train2.ReadLine()) != null)
					{
						for (int i = 0, j = 0; i < line.Length; i++, j++)
						{
							if ((line[i] == '\t') && (j != 0))
							{
								class2[m, n] = float.Parse(line.Substring(i - j, j));
								txtOutput.AppendText(line.Substring(i - j, j));
								n++;
								j = 0;
							}
						}
						class2[m, 8] = 2;
						knnsf(class2[m, 1], class2[m, 2], class2[m, 3], class2[m, 4], class2[m, 5], class2[m, 6], class2[m, 7]);
						int classesa = classes;
						txtOutput.AppendText('\t' + " " + classesa.ToString());
						m++;
						n = 0;
						txtOutput.AppendText("\n");
						txtOutput.PageDown();
					}
				}
				using (StreamReader train3 = new StreamReader("train3.txt"))
				{
					String line;
					int m = 0, n = 0;
					txtOutput.AppendText("\n------------------------------第三类样本------------------------------\n");
					txtOutput.AppendText('\t' + "PH值" + '\t' + "碱度" + '\t' + "氨氮" + '\t' + "COD" + '\t' + "BOD" + '\t' + "SS" + "    " + "硝态氮" + '\t' + "类别" + '\n');
					while ((line = train3.ReadLine()) != null)
					{
						for (int i = 0, j = 0; i < line.Length; i++, j++)
						{
							if ((line[i] == '\t') && (j != 0))
							{
								class3[m, n] = float.Parse(line.Substring(i - j, j));
								txtOutput.AppendText(line.Substring(i - j, j));
								n++;
								j = 0;
							}
						}
						class3[m, 8] = 3;
						knnsf(class3[m, 1], class3[m, 2], class3[m, 3], class3[m, 4], class3[m, 5], class3[m, 6], class3[m, 7]);
						int classesa = classes;
						txtOutput.AppendText('\t' + " " + classesa.ToString());
						m++;
						n = 0;
						txtOutput.AppendText("\n");
						txtOutput.PageDown();
					}
				}
				using (StreamReader yanzheng = new StreamReader("yanzheng.txt"))
				{
					String line;
					int m = 0, n = 0;
					txtOutput.AppendText("\n------------------------------验证样本------------------------------\n");
					txtOutput.AppendText('\t' + "PH值" + '\t' + "碱度" + '\t' + "氨氮" + '\t' + "COD" + '\t' + "BOD" + '\t' + "SS" + "    " + "硝态氮" + '\t' + "类别" + '\n');
					while ((line = yanzheng.ReadLine()) != null)
					{
						for (int i = 0, j = 0; i < line.Length; i++, j++)
						{
							if ((line[i] == '\t') && (j != 0))
							{
								sample[m, n] = float.Parse(line.Substring(i - j, j));
								txtOutput.AppendText(line.Substring(i - j, j));
								n++;
								j = 0;
							}
						}
						knnsf(sample[m, 1], sample[m, 2], sample[m, 3], sample[m, 4], sample[m, 5], sample[m, 6], sample[m, 7]);
						int classesa = classes;
						txtOutput.AppendText('\t' + " " + classesa.ToString());
						m++;
						n = 0;
						txtOutput.AppendText("\n");
						txtOutput.PageDown();
					}
				}
			}
			catch (Exception e)
			{
				// Let the user know what went wrong.
				MessageBox.Show("The file could not be read:\n" + e.Message);
			}
		}
	}
}