#include<iostream>
#include<string>
using namespace std;
const int N = 200;
class LZW{
private: string Dic[200];//��Ŵʵ�
		 int code[N];//��ű����������
public: LZW(){//���ôʵ��
	Dic[0] = 'a';
	Dic[1] = 'b';
	Dic[2] = 'c';
	string *p = Dic;//����ָ��ָ��ʵ��е��ַ�}
	void Bianma(string cs[N]);//���б���
	int IsDic(string e);//�ж��Ƿ��ڴʵ���
	int codeDic(string f);
	void display(int g);//��ʾ���
};
		void LZW::Bianma(string cs[N])
		{
			string P, C, K;
			P = cs[0];
			int l = 0;
			for (int i = 1; i<N; i++)
			{
				C = cs[i];// ��ǰ�ַ�(C) ��=�ַ����е���һ���ַ�
				K = P + C;
				if (IsDic(K)) P = K;//P+C�ڴʵ��У���C��չP
				else
				{//P+C���ڴʵ���
					code[l] = codeDic(P);
					Dic[3 + l] = K;//��P+C����ʵ�
					P = C;
					l++;
				}
				if (N - 1 == i)//����ַ�����û���ַ���Ҫ����
					code[l] = codeDic(P);
			}
			display(l);
		}
		int LZW::IsDic(string e)
		{//����ַ����л����ַ���Ҫ����
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
			cout << "����LZW�������������£�" << endl;
			for (int i = 0; i <= g; i++)
				cout << code[i];
			cout << endl;
			cout << "��LZW�����Ĵʵ����£�" << endl;
			for (int r = 0; r<g + 3; r++)
				cout << r + 1 << Dic[r] << endl;
		}
		int main()
		{
			LZW t;
			string CSstream[N];// ���Ҫ����LZW������ַ�����
			int length;// Ҫ����LZW������ַ����г���
			cout << "�����������������еĳ��ȣ�";
			cin >> length;
			while (length >= N)
			{
				cout << "�ó���̫�������������룺";
				cin >> length;
			}
			cout << "������Ҫ����LZW������ַ����У�" << endl;
			for (int a = 0; a<length; a++)
				cin >> CSstream[a];
			t.Bianma(CSstream);
			return 0;
		}
