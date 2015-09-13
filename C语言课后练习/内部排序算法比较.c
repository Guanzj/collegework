/*������������
	�ڽ̿����У������ڲ������㷨��ʱ�临�Ӷȷ������ֻ�������㷨ִ��ʱ��Ľף�����ִ��ʱ�䡣��ͨ��������ݱȽϸ��㷨�Ĺؼ��ֱȽϴ����͹ؼ����ƶ���������ȡ��ֱ�۸��ܡ�
������Ҫ��
��1��	������6�ֳ��õ��ڲ������㷨���бȽϣ���������ֱ�Ӳ������򡢼�ѡ�����򡢿�������ϣ�����򡢶�����
��2��	�������ı���С��100�����е�����Ҫ��α����������������������Ҫ��5�鲻ͬ���������ݽ��бȽϣ��Ƚϵ�ָ��Ϊ�йؼ��ֲμӵıȽϴ����͹ؼ��ֵ��ƶ��������ؼ��ֽ�����Ϊ3���ƶ�����
��3��	���Ҫ�Խ�������򵥷����������Ը������ݵó����������С�Ľ��͡�
���������ݡ�
	�������������������
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 1024
typedef struct
{
    int key;
}RedType;
typedef struct
{
    RedType r[max+1];
    int len;
}SqList;
void CreateSq(SqList *l)//����һ�������
{
    int i,k,j;
    srand(time(NULL));//����ϵͳʱ����Ϊ���������
    printf("������Ԫ�ظ���:",k);
    scanf("%d",&k);
    l->len=k;
    printf("������ȡֵ��Χ:",j);
    scanf("%d",&j);
    for(i=1;i<=k;i++)
        l->r[i].key=rand()%j;
    for(i=1;i<=k;i++)
        printf("%d  ",l->r[i].key);
    printf("\n");
}
void insertsort(SqList *l)//ֱ�Ӳ��������㷨
{
    int i,j;
    int compare=0,change=0;
    for(i=2;i<=l->len;i++)
    {
        if(l->r[i].key<l->r[i-1].key)
        {
            compare++;
            change++;
            l->r[0]=l->r[i];//����Ϊ�ڱ�
            l->r[i]=l->r[i-1];
            for(j=i-2;l->r[0].key<l->r[j].key;--j)
            {
                compare++;
                l->r[j+1]=l->r[j];//��¼����
            }
            l->r[j+1]=l->r[0];//���뵽��ȷλ��
        }
    }
    printf("\n-----ֱ�Ӳ��������˳��-----\n");
    for(i=1;i<=l->len;i++)
        printf("%d  ",l->r[i].key);
    printf("\n");
    printf("ֱ�Ӳ�������Ƚϴ���Ϊ:%d\n",compare);
    printf("ֱ�Ӳ��������ƶ�����Ϊ:%d\n",change*3);
}
void ShellInsert(SqList *L,int dk)
{
    int i,j,compare=0,change=0;
    for(i=dk+1;i<=L->len;++i)
        if(L->r[i].key<L->r[i-dk].key)
        {
            ++compare;
            L->r[0]=L->r[i];
            for(j=i-dk;j>0&&L->r[0].key<L->r[j].key;j-=dk)
            {
                ++compare;
                ++change;
                L->r[j+dk]=L->r[j];
            }
            L->r[j+dk]=L->r[0];
        }
}
void ShellSort(SqList *L,int dlta[])//ϣ������
{
    int k,j=L->len/2,t=0;
    int compare,change;
    while(j>=0)
    {
        ++t;
        j-=2;
    }
    j=L->len/2;
    for(k=0;k<t;++k)//����ÿ�ε�����ֵ
    {
        if(j==0)
            j=1;//�������һ�����������
        dlta[k]=j;
        j-=2;
    }
    for(k=0;k<t;++k)
        ShellInsert(L,dlta[k]);
    printf("\n-----ϣ�������˳��-----\n");
    for(k=1;k<=L->len;k++)
        printf("%d  ",L->r[k].key);
    printf("\n");
    printf("ϣ������Ƚϴ���Ϊ:%d\n",compare);
    printf("ϣ�������ƶ�����Ϊ:%d\n",change*3);
}
void HeapAdjust(SqList *l,int s,int m)
{
    int i,compare=0,change=0;
    l->r[0]=l->r[s];
    for(i=2*s;i<=m;i*=2)
    {
        if(i<m&&l->r[i].key>l->r[i+1].key)
            i++;
        compare+=2;
        if(l->r[0].key<l->r[i].key)
            break;
        l->r[s]=l->r[i];
        change++;
        s=i;
    }
    l->r[s]=l->r[0];
}
void Heapsort(SqList *l)
{
    int i,compare,change;
    for(i=l->len/2;i>0;i--)
        HeapAdjust(l,i,l->len);
    for(i=l->len;i>1;i--)
    {
        l->r[0]=l->r[1];
        l->r[1]=l->r[i];
        l->r[i]=l->r[0];
        change++;
        HeapAdjust(l,1,i-1);
    }
    printf("\n-----С���������˳��-----\n");
    for(i=1;i<=l->len;i++)
        printf("%d  ",l->r[i].key);
    printf("\n");
    printf("С��������Ƚϴ���Ϊ:%d\n",compare);
    printf("С���������ƶ�����Ϊ:%d\n",change*3);
}

int Partition(SqList *L,int low,int high)
{
    int pivotkey,compare=0,change=0;
    L->r[0]=L->r[low];
    pivotkey=L->r[low].key;
    while(low<high)
    {
        while(low<high&&L->r[high].key>=pivotkey)
        {
            ++compare;
            --high;
        }
        ++change;
        L->r[low]=L->r[high];
        while(low<high&&L->r[low].key<=pivotkey)
        {
            ++compare;
            ++low;
        }
        L->r[high]=L->r[low];
    }
    ++change;
    L->r[low]=L->r[0];
    return low;
}
void Qsort(SqList *L,int low,int high)//�ݹ���ʽ�Ŀ��������㷨
{
	int pivotloc;
    if(low<high)
	{
        pivotloc=Partition(L,low,high);
        Qsort(L,low,pivotloc-1);
        Qsort(L,pivotloc+1,high);
	}
}
void QuickSort(SqList *L)
{
    int i,compare,change;
    Qsort(L,1,L->len);
    printf("\n-----�������������-----\n");
    for(i=1;i<=L->len;i++)
    printf("%d  ",L->r[i].key);
    printf("\n");
    printf("���������Ƚϴ���Ϊ:%d\n",compare);
    printf("����������ƶ�����Ϊ:%d\n",change*3);
}
void BubbleSort(SqList *l)
{
    int i,j,k,t,compare=0,change=0;
    k=l->len;
    for(i=1;i<=l->len-1;i++)
    {
        for(j=1;j<=k-1;j++)
        {
            compare++;
            if(l->r[j].key>l->r[j+1].key)
            {
                t=l->r[j].key;
                l->r[j].key=l->r[j+1].key;
                l->r[j+1].key=t;
                change++;
            }
        }
        k--;
    }
    printf("\n-----ð�����������-----\n");
    for(i=1;i<=l->len;i++)
        printf("%d  ",l->r[i].key);
    printf("\n");
    printf("ð������Ƚϴ���:%d\n",compare);
    printf("ð�������ƶ�����:%d\n",change*3);
}
void SelectSort(SqList *l)
{
    int i,j,t,compare=0,change=0;
    for(i=1;i<=l->len;i++)
    {
        l->r[0]=l->r[i];
        j=i+1;
        t=i;
        for(j;j<=l->len;j++)
        {
            compare++;
            if(l->r[0].key>l->r[j].key)
            {
                t=j;
                l->r[0]=l->r[j];
            }
        }
        if(t!=i)
        {
            change++;
            l->r[t]=l->r[i];
            l->r[i]=l->r[0];
        }
    }
    printf("\n-----��ѡ�����������-----\n");
    for(i=1;i<=l->len;i++)
        printf("%d  ",l->r[i].key);
    printf("\n");
    printf("���ѡ������Ƚϴ���:%d\n",compare);
    printf("��ѡ�������ƶ�����:%d\n",change*3);
}
void main()
{
    int i;
    int dlta[max];
    SqList l,a,b,c,d,e,f;
    CreateSq(&l);
    a=b=c=d=e=f=l;
    BubbleSort(&a);
    SelectSort(&b);
    QuickSort(&c);
    ShellSort(&d,dlta);
    Heapsort(&e);
    insertsort(&f);
}
