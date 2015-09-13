#include<iostream>
#include<string>
using namespace std;
const int N = 200;
class LZW{
private: string Dic[200];//存放词典
		 int code[N];//存放编码过的码字
public: LZW(){//设置词典根
	Dic[0] = 'a';
	Dic[1] = 'b';
	Dic[2] = 'c';
	string *p = Dic;//定义指针指向词典中的字符}
	void Bianma(string cs[N]);//进行编码
	int IsDic(string e);//判断是否在词典中
	int codeDic(string f);
	void display(int g);//显示结果
};
		void LZW::Bianma(string cs[N])
		{
			string P, C, K;
			P = cs[0];
			int l = 0;
			for (int i = 1; i<N; i++)
			{
				C = cs[i];// 当前字符(C) ：=字符流中的下一个字符
				K = P + C;
				if (IsDic(K)) P = K;//P+C在词典中，用C扩展P
				else
				{//P+C不在词典中
					code[l] = codeDic(P);
					Dic[3 + l] = K;//将P+C加入词典
					P = C;
					l++;
				}
				if (N - 1 == i)//如果字符流中没有字符需要编码
					code[l] = codeDic(P);
			}
			display(l);
		}
		int LZW::IsDic(string e)
		{//如果字符流中还有字符需要编码
			for (int b = 0; b<200; b++)
			{
				if (e == Dic[b]) return 1;
			}
			return 0;
		}
		int LZW::codeDic(string f)
		{
			int w = 0;
			for (int y = 0; y<200; y++)
				if (f == Dic[y])
				{
				w = y + 1;
				break;
				}
			return w;
		}
		void LZW::display(int g)
		{
			cout << "经过LZW编码后的码字如下：" << endl;
			for (int i = 0; i <= g; i++)
				cout << code[i];
			cout << endl;
			cout << "经LZW编码后的词典如下：" << endl;
			for (int r = 0; r<g + 3; r++)
				cout << r + 1 << Dic[r] << endl;
		}
		int main()
		{
			LZW t;
			string CSstream[N];// 存放要进行LZW编码的字符序列
			int length;// 要进行LZW编码的字符序列长度
			cout << "请输入所求码子序列的长度：";
			cin >> length;
			while (length >= N)
			{
				cout << "该长度太长，请重新输入：";
				cin >> length;
			}
			cout << "请输入要进行LZW编码的字符序列：" << endl;
			for (int a = 0; a<length; a++)
				cin >> CSstream[a];
			t.Bianma(CSstream);
			return 0;
		}
