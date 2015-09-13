
/*一个完整的系统应具有以下功能：
（1）I：初始化（Initialization）。从终端读入字符集大小n，以及n个字符和n个权值，建立哈夫曼树，并将它存于文件hfmTree中。
（2）E：编码（Encoding）。利用已建好的哈夫曼树（如不在内存，则从文件hfmTree中读入），对文件ToBeTran中的正文进行编码，然后将结果存入文件Codefile中。
（3）D：译码（Decoding）。利用已建好的哈夫曼树将文件Codefile中的代码进行译码，结果存入文件Textfile中。
（4）P：印代码文件（Print）。将文件Codefile以紧凑格式显示在终端上，每行50个代码。同时将此字符形式的编码文件写入文件Codeprin中。
（5）T：印哈夫曼树（Tree printing）。将已在内存中的哈夫曼树以直观的方式（树或凹入表形式）显示在终端上，同时将此字符形式的哈夫曼树写入文件Treeprint中。
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 200
#define M 2*N-1
#define MAXINT 32767
typedef struct//定义结构体
{
    int weight;//权值
    int parent;//双亲结点
    int lchild;//左孩子
    int rchild;//右孩子
    char key;//字符
}htnode;
typedef htnode hfmTree[M];
int n;
void inithfmt(hfmTree ht)//对哈夫曼树T初始化
{
    int i;
    printf("请输入n=");//输入所需构建哈夫曼树的n个字符
    scanf("%d",&n);
    getchar();
    for(i=0;i<2*n-1;i++)//对所构建的哈夫曼树的2*n-1个结点初始化
    {
        ht[i].weight=0;
        ht[i].lchild=-1;
        ht[i].parent=-1;
        ht[i].rchild=-1;
    }
    printf("\n");
}
void input(hfmTree ht)//输入结构体各个字符与其所对应的权值
{
    int w,i;
    char k;
    for(i=0;i<n;i++)
    {
        printf("请输入第%d个字符:",i+1);//输入字符
        scanf("%c",&k);
        getchar();
        ht[i].key=k;
        printf("请输入第%d个字符的权值:",i+1);//输入字符所对应的权值
        scanf("%d",&w);
        getchar();
        ht[i].weight=w;
        printf("\n");
    }
}
void select(hfmTree ht,int pos,int *s1,int *s2)//选择函数，选择权值最小的两个字符，并返回其位置
{
    int j,m1,m2;
    m1=m2=MAXINT;
    for(j=0;j<=pos;j++)//选择权值最小的字符，并用s1返回其为止
    {
        if(ht[j].parent==-1)
        {
            if(ht[j].weight<m1)
            {
                m1=ht[j].weight;
                *s1=j;
            }
        }

    }
    for(j=0;j<=pos;j++)//选择权值次小的字符，并用s2返回其位置
    {
        if(ht[j].parent==-1)
        {
            if(m2>ht[j].weight&&j!=(*s1))
            {
                m2=ht[j].weight;
                *s2=j;
            }
        }
    }
}
void creathfmt(hfmTree ht)//构建哈夫曼树
{
    int i,j,k,s1,s2,m;
    inithfmt(ht);//对结构体初始化
    input(ht);//输入结构体的字符及权值
    for(i=n;i<2*n-1;i++)
    {
        select(ht,i-1,&s1,&s2);//选择函数
        ht[s1].parent=i;
        ht[s2].parent=i;
        ht[i].lchild=s1;
        ht[i].rchild=s2;
        ht[i].weight=ht[s1].weight+ht[s2].weight;//将权值最小的两个字符构建为一颗哈夫曼树，重复此过程直到所有字符都包含到哈夫曼树内
    }
}
void printhfmt(hfmTree ht)//打印哈夫曼树
{
    int i;
    printf("\t权值\t父母\t左孩子\t右孩子\t字符");
    for(i=0;i<2*n-1;i++)
    {
        printf("\n");
        printf("\t%d\t%d\t%d\t%d\t%c",ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild,ht[i].key);
    }
    printf("\n");
}
void hfmtpath(hfmTree ht,int i,int j)//对哈夫曼树进行编码，左编‘0’，右编‘1’
{
    int a,b;
    a=i;
    b=j=ht[i].parent;
    if(ht[j].parent!=-1)
    {
        i=j;
        hfmtpath(ht,i,j);
    }
    if(ht[b].lchild==a)
        printf("0");
    else
        printf("1");
}
void hfmnode(hfmTree ht)//输出字符与其对应的哈夫曼编码
{
    int i,j;
    for(i=0;i<n;i++)
    {
        j=0;
        printf("\n");
        printf("\t%c\t",ht[i].key);
        hfmtpath(ht,i,j);
    }
    printf("\n");
}
void Encoding(hfmTree ht)//输入一串字符，并将其对应编码打印
{
    char r[1000];
    int i;
    int j;
    printf("\n请输入需要编码的字符:");
    gets(r);
    printf("编码的结果是:");
    for(j=0;r[j]!='\0';j++)
    {
        for(i=0;i<n;i++)
        {
            if(r[j]==ht[i].key)
                hfmtpath(ht,i,j);
        }
    }
    printf("\n");
}
void Decoding(hfmTree ht)//输入一串字符串，并打印其对应的译码结果
{
    char r[1000];
    int i ,j ,len;
    j=2*n-2;
    printf("\n请输入需要译码的字符串:");
    gets(r);
    len=strlen(r);
    printf("译码的结果是:");
    for(i=0;i<len;i++)
    {
        if(r[i]=='0')
        {
            j=ht[j].lchild;
            if(ht[j].lchild==-1)
            {
                printf("%c",ht[j].key);
                j=2*n-2;
            }
        }
        else if(r[i]=='1')
        {
            j=ht[j].rchild;
            if(ht[j].rchild==-1)
            {
                printf("%c",ht[j].key);
                j=2*n-2;
            }
        }
    }
    printf("\n");
}
int main()//主函数
{
    int i,j;
    hfmTree ht;//定义结构体
    char flag;//定义旗帜变量，用于后面功能的选择
    creathfmt(ht);//建立一个哈夫曼树
    printhfmt(ht);//将建好的哈夫曼树打印
    hfmnode(ht);//输出字符与其对应的编码
    printf("\n【E】编码\t【D】译码\t【Q】退出");//功能选择
    printf("\n选择:");
    flag=getchar();
    getchar();
    while(flag!='Q')
    {
        if(flag=='E')//编码
            Encoding(ht);
        else if(flag=='D')//译码
            Decoding(ht);
        else
            printf("输入错误,请重新输入.\n");
        printf("\n【E】编码\t【D】译码\t【Q】退出");
        printf("\n选择:");
        flag=getchar();
        getchar();
    }
    system("pause");
}

