/*（1）输入学生成绩保存到链表
（2）计算每位学生总成绩
（3）按照总成绩大小对记录进行排序
（4）输出所有学生成绩到一个文件中
（5）显示新输入的学生信息
（6）从文件中读取信息
（7）将文件信息保存在链表中
（8）根据姓名查找学生记录
*/

#include<iostream>

#include<string>

#include<fstream>

#include<cstdlib>

using namespace std;

enum {SUBJECT=5};//一共五门

typedef struct

{

char subject[10];//科目名称

int score;//科目成绩

}markinfo;

typedef struct studentnode

{

markinfo mark[SUBJECT];

int totalmark;

char name[10];//学生姓名

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

student::student() //用构造函数来初始化。

{

head=new studentnode;

head->next=NULL;

}

//1．输入学生姓名、成绩等数据，并保存在链表中。

int student::addstudent()

{

studentnode * p;

int i;

char check;

system("cls");

cout<<"**********************"<<endl;

cout<<"请输入学生信息："<<endl;

do

{

p=new studentnode;

cin.ignore();

cout<<"姓名：";

gets_s(p->name,1024);

i=0;

p->totalmark=0;

do

{

cout<<"科目：";

gets_s(p->mark[i].subject,1023);

cout<<"成绩(0--100)：";

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

cout<<"继续添加?y or n :";

check=getchar();

}

while(check!='n' &&check!='N');

return 0;

}

//2．计算每位学生总成绩。

int student::countmark()

{

studentnode * p=head->next;

if(p==NULL)

{

cout<<"没有学生，请重新输入"<<endl;system("pause");return 0;

}

else

{

cout<<"***************"<<endl;

cout<<"学生成绩汇总："<<endl;

while(p)

{

cout<<"姓名："<<p->name<<" 总成绩："<<p->totalmark<<endl;

p=p->next;

}

}

system("pause");

return 0;

}

//4．输出所有学生成绩到一个文件中。

int student::save()

{

char address[35];

int i;

studentnode * p=head->next;

cout<<"请输入保存的地址"<<endl;

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

cout<<"已经保存，请查阅";

system("pause");

return 0;

}

student::~student() //析构函数

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

//3．按照总成绩大小对记录进行排序

int student::sortbymark()

{

studentnode *move1=head->next;

studentnode *move2,*max,*pre1,*pre2,*maxpre,*s=move1;

if(head->next==NULL)

{

cout<<"没有记录，请添加"<<endl;system("pause");return 0;

}

for(pre1=head,max=move1,maxpre=pre1;move1->next!=NULL;pre1=move1,maxpre=pre1,move1=move1->next,max=move1)

{

for(pre2=move1,move2=move1->next;move2!=NULL;pre2=move2,move2=move2->next)

if(move2->totalmark>max->totalmark)

{

maxpre=pre2;

max=move2;

}

if(move1->next==max) //交换max和move1。

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

cout<<"已经按照从大到小排序"<<endl;

system("pause");

return 0;

}

//5输出输入的信息

int student::show()

{

studentnode * p=head->next;

int i;

if(head->next==NULL){cout<<"没有学生记录，请添加"<<endl;system("pause"); return 0;}

else

{

while(p)

{

cout<<"姓名："<<p->name;

i=1;

while(i!=SUBJECT+1)

{

cout<<"科目："<<p->mark[i-1].subject;

cout<<" 成绩："<<p->mark[i-1].score;

i++;

}

cout<<endl;

p=p->next;

}

}

system("pause");

return 0;

}

//6:从文件按读取记录

int student::display()

{

ifstream fin;

char buf[100];

char str[25];

cout<<"请输入路径及文件名:"<<endl;

cin.ignore();

gets_s(str,1023);

fin.open(str);

if(!fin)

{

cout<<"没有此文件"<<endl;

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

//8从文件中读取数据，并将数据保存在链表中

int student::readfiletolist()

{

ifstream fin;

int i;

char str[25];

cout<<"请输入路径及文件名:"<<endl;

cin.ignore();

gets_s(str,1234);

fin.open(str);

if(!fin)

{

cout<<"没有此文件"<<endl;

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

cout<<"信息已经保存在链表中"<<endl;

system("pause");

return 0;

}

//9根据姓名进行查找

int student::searchbyname()

{

if(head->next==NULL)

{

cout<<"没有学生，请添加或者从文件中读取"<<endl;

system("pause");

return 0;

}

studentnode * p=head->next;

char findname[10];

int i;

cout<<"请输入姓名:";

cin.ignore();

gets_s(findname,1234);

while(p)

{

if(!strcmp(p->name,findname))

{

cout<<"经查找，找到该生信息如下："<<endl<<endl;

cout<<"姓名："<<p->name;

i=1;

while(i!=SUBJECT+1)

{

cout<<"科目："<<p->mark[i-1].subject;

cout<<" 成绩："<<p->mark[i-1].score;

i++;

}

cout<<endl;

system("pause");

return 1;

}

p=p->next;

}

cout<<"没有此学生，请添加或者从文件中读取"<<endl;

system("pause");

return 0;

}

int showmenu()

{

int choice;

char * menu[9]={

"1:输入学生成绩保存到链表\n",

"2:计算每位学生总成绩\n",

"3:按照总成绩大小对记录进行排序\n",

"4:输出所有学生成绩到一个文件中\n",

"5:显示新输入的学生信息\n",

"6:从文件中读取信息\n",

"7:将文件信息保存在链表中\n",

"8:根据姓名查找学生记录\n",

"9:结束程序\n"

};

cout<<"	"<<"*****************************************************"<<endl;

cout<<"	 *"<<"	 "<<"学生成绩管理系统"<<" *"<<endl;

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