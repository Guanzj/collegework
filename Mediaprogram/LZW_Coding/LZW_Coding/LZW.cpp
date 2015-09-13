#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
char Dictionary[1000][1000];
char ch[1000];
int a[1000];
int s, n;
int len;
char h[2], t[100];
char p[100];
void Editcode()       //±àÂë£»
{
	cout << "ÇëÊäÈëÒª±àÂëµÄ×Ö·û´®:" << endl << endl;
	cin >> ch;
	t[0] = 0;
	s = 0;
	n = 128;
	cout << endl;
	cout << "´ÊµäÖÐµÄ±àÂëÎª:" << endl << endl;
	for (int i = 0; ch[i]; i++)
	{
		h[0] = ch[i];
		strcat_s(t, h);
		int j;
		for (j = 1; j<n; j++)
			if (strcmp(t, Dictionary[j]) == 0)
				break;
		if (j == n)
		{
			cout << s << " ";
			strcpy_s(Dictionary[n], t);
			strcpy_s(t, h);
			s = h[0];
			n++;
		}
		else s = j;
	}
	cout << s << endl;
}

void main()
{
	h[1] = 0;
	for (int i = 1; i <= 127; i++)
	{
		h[0] = char(i);
		strcpy_s(Dictionary[i], h);
	}


	while (true)
	{
		cout << "±àÂë"<<endl;

		cout << endl;

		Editcode();
		cout << endl << "±àÂë´Êµä:" << endl << endl;
		for (int i = 33; i < n; i++)//Ã¿6Î»×ÖµäÊä³öÒ»ÐÐ
		{
			if ((i - 32) % 6 != 0)
				cout << setw(4) << i << setw(6) << Dictionary[i] << "  ";
			else
				cout << setw(4) << i << setw(6) << Dictionary[i] << endl;
		}
		cout <<endl<<"********************************************************************************"<< endl<<endl;


	}

}