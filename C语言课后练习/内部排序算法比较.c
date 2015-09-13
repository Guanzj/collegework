/*【问题描述】
	在教科书中，各种内部排序算法的时间复杂度分析结果只给出了算法执行时间的阶，或大概执行时间。试通过随机数据比较各算法的关键字比较次数和关键字移动次数，以取得直观感受。
【基本要求】
（1）	对以下6种常用的内部排序算法进行比较：起泡排序、直接插入排序、简单选择排序、快速排序、希尔排序、堆排序。
（2）	待排序表的表长不小于100；其中的数据要用伪随机数产生程序产生；至少要用5组不同的输入数据进行比较；比较的指标为有关键字参加的比较次数和关键字的移动次数（关键字交换记为3次移动）。
（3）	最后要对结果做出简单分析，包括对各组数据得出结果波动大小的解释。
【测试数据】
	由随机数产生器产生。
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
void CreateSq(SqList *l)//创建一组随机数
{
    int i,k,j;
    srand(time(NULL));//设置系统时间作为随机数种子
    printf("请输入元素个数:",k);
    scanf("%d",&k);
    l->len=k;
    printf("请输入取值范围:",j);
    scanf("%d",&j);
    for(i=1;i<=k;i++)
        l->r[i].key=rand()%j;
    for(i=1;i<=k;i++)
        printf("%d  ",l->r[i].key);
    printf("\n");
}
void insertsort(SqList *l)//直接插入排序算法
{
    int i,j;
    int compare=0,change=0;
    for(i=2;i<=l->len;i++)
    {
        if(l->r[i].key<l->r[i-1].key)
        {
            compare++;
            change++;
            l->r[0]=l->r[i];//复制为哨兵
            l->r[i]=l->r[i-1];
            for(j=i-2;l->r[0].key<l->r[j].key;--j)
            {
                compare++;
                l->r[j+1]=l->r[j];//记录后移
            }
            l->r[j+1]=l->r[0];//插入到正确位置
        }
    }
    printf("\n-----直接插入排序后顺序-----\n");
    for(i=1;i<=l->len;i++)
        printf("%d  ",l->r[i].key);
    printf("\n");
    printf("直接插入排序比较次数为:%d\n",compare);
    printf("直接插入排序移动次数为:%d\n",change*3);
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
void ShellSort(SqList *L,int dlta[])//希尔排序
{
    int k,j=L->len/2,t=0;
    int compare,change;
    while(j>=0)
    {
        ++t;
        j-=2;
    }
    j=L->len/2;
    for(k=0;k<t;++k)//计算每次的增量值
    {
        if(j==0)
            j=1;//定义最后一趟排序的增量
        dlta[k]=j;
        j-=2;
    }
    for(k=0;k<t;++k)
        ShellInsert(L,dlta[k]);
    printf("\n-----希尔排序后顺序-----\n");
    for(k=1;k<=L->len;k++)
        printf("%d  ",L->r[k].key);
    printf("\n");
    printf("希尔排序比较次数为:%d\n",compare);
    printf("希尔排序移动次数为:%d\n",change*3);
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
    printf("\n-----小顶堆排序后顺序-----\n");
    for(i=1;i<=l->len;i++)
        printf("%d  ",l->r[i].key);
    printf("\n");
    printf("小顶堆排序比较次数为:%d\n",compare);
    printf("小顶堆排序移动次数为:%d\n",change*3);
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
void Qsort(SqList *L,int low,int high)//递归形式的快速排序算法
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
    printf("\n-----快速排序后序列-----\n");
    for(i=1;i<=L->len;i++)
    printf("%d  ",L->r[i].key);
    printf("\n");
    printf("快速排序后比较次数为:%d\n",compare);
    printf("快速排序后移动次数为:%d\n",change*3);
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
    printf("\n-----冒泡排序后序列-----\n");
    for(i=1;i<=l->len;i++)
        printf("%d  ",l->r[i].key);
    printf("\n");
    printf("冒泡排序比较次数:%d\n",compare);
    printf("冒泡排序移动次数:%d\n",change*3);
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
    printf("\n-----简单选择排序后序列-----\n");
    for(i=1;i<=l->len;i++)
        printf("%d  ",l->r[i].key);
    printf("\n");
    printf("简答选择排序比较次数:%d\n",compare);
    printf("简单选择排序移动次数:%d\n",change*3);
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
