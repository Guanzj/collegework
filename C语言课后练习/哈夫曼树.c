
/*һ��������ϵͳӦ�������¹��ܣ�
��1��I����ʼ����Initialization�������ն˶����ַ�����Сn���Լ�n���ַ���n��Ȩֵ���������������������������ļ�hfmTree�С�
��2��E�����루Encoding���������ѽ��õĹ����������粻���ڴ棬����ļ�hfmTree�ж��룩�����ļ�ToBeTran�е����Ľ��б��룬Ȼ�󽫽�������ļ�Codefile�С�
��3��D�����루Decoding���������ѽ��õĹ����������ļ�Codefile�еĴ���������룬��������ļ�Textfile�С�
��4��P��ӡ�����ļ���Print�������ļ�Codefile�Խ��ո�ʽ��ʾ���ն��ϣ�ÿ��50�����롣ͬʱ�����ַ���ʽ�ı����ļ�д���ļ�Codeprin�С�
��5��T��ӡ����������Tree printing�����������ڴ��еĹ���������ֱ�۵ķ�ʽ�����������ʽ����ʾ���ն��ϣ�ͬʱ�����ַ���ʽ�Ĺ�������д���ļ�Treeprint�С�
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 200
#define M 2*N-1
#define MAXINT 32767
typedef struct//����ṹ��
{
    int weight;//Ȩֵ
    int parent;//˫�׽��
    int lchild;//����
    int rchild;//�Һ���
    char key;//�ַ�
}htnode;
typedef htnode hfmTree[M];
int n;
void inithfmt(hfmTree ht)//�Թ�������T��ʼ��
{
    int i;
    printf("������n=");//�������蹹������������n���ַ�
    scanf("%d",&n);
    getchar();
    for(i=0;i<2*n-1;i++)//���������Ĺ���������2*n-1������ʼ��
    {
        ht[i].weight=0;
        ht[i].lchild=-1;
        ht[i].parent=-1;
        ht[i].rchild=-1;
    }
    printf("\n");
}
void input(hfmTree ht)//����ṹ������ַ���������Ӧ��Ȩֵ
{
    int w,i;
    char k;
    for(i=0;i<n;i++)
    {
        printf("�������%d���ַ�:",i+1);//�����ַ�
        scanf("%c",&k);
        getchar();
        ht[i].key=k;
        printf("�������%d���ַ���Ȩֵ:",i+1);//�����ַ�����Ӧ��Ȩֵ
        scanf("%d",&w);
        getchar();
        ht[i].weight=w;
        printf("\n");
    }
}
void select(hfmTree ht,int pos,int *s1,int *s2)//ѡ������ѡ��Ȩֵ��С�������ַ�����������λ��
{
    int j,m1,m2;
    m1=m2=MAXINT;
    for(j=0;j<=pos;j++)//ѡ��Ȩֵ��С���ַ�������s1������Ϊֹ
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
    for(j=0;j<=pos;j++)//ѡ��Ȩֵ��С���ַ�������s2������λ��
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
void creathfmt(hfmTree ht)//������������
{
    int i,j,k,s1,s2,m;
    inithfmt(ht);//�Խṹ���ʼ��
    input(ht);//����ṹ����ַ���Ȩֵ
    for(i=n;i<2*n-1;i++)
    {
        select(ht,i-1,&s1,&s2);//ѡ����
        ht[s1].parent=i;
        ht[s2].parent=i;
        ht[i].lchild=s1;
        ht[i].rchild=s2;
        ht[i].weight=ht[s1].weight+ht[s2].weight;//��Ȩֵ��С�������ַ�����Ϊһ�Ź����������ظ��˹���ֱ�������ַ�������������������
    }
}
void printhfmt(hfmTree ht)//��ӡ��������
{
    int i;
    printf("\tȨֵ\t��ĸ\t����\t�Һ���\t�ַ�");
    for(i=0;i<2*n-1;i++)
    {
        printf("\n");
        printf("\t%d\t%d\t%d\t%d\t%c",ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild,ht[i].key);
    }
    printf("\n");
}
void hfmtpath(hfmTree ht,int i,int j)//�Թ����������б��룬��࡮0�����ұ࡮1��
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
void hfmnode(hfmTree ht)//����ַ������Ӧ�Ĺ���������
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
void Encoding(hfmTree ht)//����һ���ַ����������Ӧ�����ӡ
{
    char r[1000];
    int i;
    int j;
    printf("\n��������Ҫ������ַ�:");
    gets(r);
    printf("����Ľ����:");
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
void Decoding(hfmTree ht)//����һ���ַ���������ӡ���Ӧ��������
{
    char r[1000];
    int i ,j ,len;
    j=2*n-2;
    printf("\n��������Ҫ������ַ���:");
    gets(r);
    len=strlen(r);
    printf("����Ľ����:");
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
int main()//������
{
    int i,j;
    hfmTree ht;//����ṹ��
    char flag;//�������ı��������ں��湦�ܵ�ѡ��
    creathfmt(ht);//����һ����������
    printhfmt(ht);//�����õĹ���������ӡ
    hfmnode(ht);//����ַ������Ӧ�ı���
    printf("\n��E������\t��D������\t��Q���˳�");//����ѡ��
    printf("\nѡ��:");
    flag=getchar();
    getchar();
    while(flag!='Q')
    {
        if(flag=='E')//����
            Encoding(ht);
        else if(flag=='D')//����
            Decoding(ht);
        else
            printf("�������,����������.\n");
        printf("\n��E������\t��D������\t��Q���˳�");
        printf("\nѡ��:");
        flag=getchar();
        getchar();
    }
    system("pause");
}

