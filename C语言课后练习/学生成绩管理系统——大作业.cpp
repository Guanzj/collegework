/*��1������ѧ���ɼ����浽����
��2������ÿλѧ���ܳɼ�
��3�������ܳɼ���С�Լ�¼��������
��4���������ѧ���ɼ���һ���ļ���
��5����ʾ�������ѧ����Ϣ
��6�����ļ��ж�ȡ��Ϣ
��7�����ļ���Ϣ������������
��8��������������ѧ����¼
*/

#include<iostream>

#include<string>

#include<fstream>

#include<cstdlib>

using namespace std;

enum {SUBJECT=5};//һ������

typedef struct

{

char subject[10];//��Ŀ����

int score;//��Ŀ�ɼ�

}markinfo;

typedef struct studentnode

{

markinfo mark[SUBJECT];

int totalmark;

char name[10];//ѧ������

studentnode * next;

}studentnode;

class student

{

studentnode * head;

public:

student();

int addstudent();

~student();

int countmark();

int sortbymark();

int save();

int show();

int display();

int readfiletolist();

int searchbyname();

};

student::student() //�ù��캯������ʼ����

{

head=new studentnode;

head->next=NULL;

}

//1������ѧ���������ɼ������ݣ��������������С�

int student::addstudent()

{

studentnode * p;

int i;

char check;

system("cls");

cout<<"**********************"<<endl;

cout<<"������ѧ����Ϣ��"<<endl;

do

{

p=new studentnode;

cin.ignore();

cout<<"������";

gets_s(p->name,1024);

i=0;

p->totalmark=0;

do

{

cout<<"��Ŀ��";

gets_s(p->mark[i].subject,1023);

cout<<"�ɼ�(0--100)��";

do

{

cin>>p->mark[i].score;

}

while(p->mark[i].score>100||p->mark[i].score<0);

p->totalmark=p->totalmark+p->mark[i].score;

getchar();

}

while(++i!=SUBJECT);

if(head->next==NULL)

{

head->next=p;p->next=NULL;

}

else

{

p->next=head->next;

head->next=p;

}

cout<<"�������?y or n :";

check=getchar();

}

while(check!='n' &&check!='N');

return 0;

}

//2������ÿλѧ���ܳɼ���

int student::countmark()

{

studentnode * p=head->next;

if(p==NULL)

{

cout<<"û��ѧ��������������"<<endl;system("pause");return 0;

}

else

{

cout<<"***************"<<endl;

cout<<"ѧ���ɼ����ܣ�"<<endl;

while(p)

{

cout<<"������"<<p->name<<" �ܳɼ���"<<p->totalmark<<endl;

p=p->next;

}

}

system("pause");

return 0;

}

//4���������ѧ���ɼ���һ���ļ��С�

int student::save()

{

char address[35];

int i;

studentnode * p=head->next;

cout<<"�����뱣��ĵ�ַ"<<endl;

cin.ignore();

gets_s(address,1023);

ofstream fout;

fout.open(address,ios::app|ios::out);

while(p)

{

fout<<"*";

fout<<p->name<<"*";

i=0;

while(i!=SUBJECT)

{

fout<<p->mark[i].subject<<"*";

fout<<p->mark[i].score;

i++;

}

//fout<<"*";

p=p->next;

}

fout.flush();

fout.close();

cout<<"�Ѿ����棬�����";

system("pause");

return 0;

}

student::~student() //��������

{

studentnode * p,* s;

p=head->next;

while(p)

{

s=p->next;

delete p;

p=s;

}

delete head;

}

//3�������ܳɼ���С�Լ�¼��������

int student::sortbymark()

{

studentnode *move1=head->next;

studentnode *move2,*max,*pre1,*pre2,*maxpre,*s=move1;

if(head->next==NULL)

{

cout<<"û�м�¼�������"<<endl;system("pause");return 0;

}

for(pre1=head,max=move1,maxpre=pre1;move1->next!=NULL;pre1=move1,maxpre=pre1,move1=move1->next,max=move1)

{

for(pre2=move1,move2=move1->next;move2!=NULL;pre2=move2,move2=move2->next)

if(move2->totalmark>max->totalmark)

{

maxpre=pre2;

max=move2;

}

if(move1->next==max) //����max��move1��

{

pre1->next=max;

move1->next=max->next;

max->next=move1;

move1=max;

}

else

{

s=move1->next;

move1->next=max->next;

max->next=s;

maxpre->next=move1;

pre1->next=max;

move1=max;

}

}

cout<<"�Ѿ����մӴ�С����"<<endl;

system("pause");

return 0;

}

//5����������Ϣ

int student::show()

{

studentnode * p=head->next;

int i;

if(head->next==NULL){cout<<"û��ѧ����¼�������"<<endl;system("pause"); return 0;}

else

{

while(p)

{

cout<<"������"<<p->name;

i=1;

while(i!=SUBJECT+1)

{

cout<<"��Ŀ��"<<p->mark[i-1].subject;

cout<<" �ɼ���"<<p->mark[i-1].score;

i++;

}

cout<<endl;

p=p->next;

}

}

system("pause");

return 0;

}

//6:���ļ�����ȡ��¼

int student::display()

{

ifstream fin;

char buf[100];

char str[25];

cout<<"������·�����ļ���:"<<endl;

cin.ignore();

gets_s(str,1023);

fin.open(str);

if(!fin)

{

cout<<"û�д��ļ�"<<endl;

system("pause");

return 0;

}

while(fin)

{

fin.getline(buf,sizeof(buf));

cout<<buf<<endl;

}

system("pause");

return 0;

}

//8���ļ��ж�ȡ���ݣ��������ݱ�����������

int student::readfiletolist()

{

ifstream fin;

int i;

char str[25];

cout<<"������·�����ļ���:"<<endl;

cin.ignore();

gets_s(str,1234);

fin.open(str);

if(!fin)

{

cout<<"û�д��ļ�"<<endl;

system("pause");

return 0;

}

studentnode * p;

fin.ignore(100,'*');

while(fin)

{

p=new studentnode;

p->totalmark=0;

fin.getline(p->name,100,'*');

i=0;

while(i!=SUBJECT)

{

fin.getline(p->mark[i].subject,100,'*');

fin>>p->mark[i].score;

p->totalmark+=p->mark[i].score;

i++;

}

if(head->next==NULL)

{

head->next=p;

p->next=NULL;

}

else

{

p=head->next;

head->next=p;

}

}

cout<<"��Ϣ�Ѿ�������������"<<endl;

system("pause");

return 0;

}

//9�����������в���

int student::searchbyname()

{

if(head->next==NULL)

{

cout<<"û��ѧ��������ӻ��ߴ��ļ��ж�ȡ"<<endl;

system("pause");

return 0;

}

studentnode * p=head->next;

char findname[10];

int i;

cout<<"����������:";

cin.ignore();

gets_s(findname,1234);

while(p)

{

if(!strcmp(p->name,findname))

{

cout<<"�����ң��ҵ�������Ϣ���£�"<<endl<<endl;

cout<<"������"<<p->name;

i=1;

while(i!=SUBJECT+1)

{

cout<<"��Ŀ��"<<p->mark[i-1].subject;

cout<<" �ɼ���"<<p->mark[i-1].score;

i++;

}

cout<<endl;

system("pause");

return 1;

}

p=p->next;

}

cout<<"û�д�ѧ��������ӻ��ߴ��ļ��ж�ȡ"<<endl;

system("pause");

return 0;

}

int showmenu()

{

int choice;

char * menu[9]={

"1:����ѧ���ɼ����浽����\n",

"2:����ÿλѧ���ܳɼ�\n",

"3:�����ܳɼ���С�Լ�¼��������\n",

"4:�������ѧ���ɼ���һ���ļ���\n",

"5:��ʾ�������ѧ����Ϣ\n",

"6:���ļ��ж�ȡ��Ϣ\n",

"7:���ļ���Ϣ������������\n",

"8:������������ѧ����¼\n",

"9:��������\n"

};

cout<<"	"<<"*****************************************************"<<endl;

cout<<"	 *"<<"	 "<<"ѧ���ɼ�����ϵͳ"<<" *"<<endl;

cout<<"	"<<"*****************************************************"<<endl;

for(choice=0;choice<9;choice++)

cout<<"	 "<<menu[choice];

cout<<"	"<<"*****************************************************"<<endl;

cout<<"please choose to continue"<<endl;

do

{

cin>>choice;

}

while(choice>9||choice<1);

return choice;

}

int main()

{

int menuitem,flag=1;

student stu;

while(flag)

{

system("cls");

menuitem=showmenu();

switch(menuitem)

{

case 1:{stu.addstudent();break;}

case 2:{stu.countmark();break;}

case 3:{stu.sortbymark();break;}

case 4:{stu.save();break;}

case 5:{stu.show();break;}

case 6:{stu.display();break;}

case 7:{stu.readfiletolist();break;}

case 8:{stu.searchbyname();break;}

case 9:{flag=0;break;}

}

}

return 0;

}