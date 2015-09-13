/*【问题描述】
这对某个集体（比如你所在的班级）中的‘人名’设计一个哈希表，使得平均查找长度不超过R，完成相应的建表和查表程序。
【基本要求】
	假设人名为中国人姓名的汉语拼音形式。待填入哈希表的人名共有30个，取平均查找长度的上限为2.哈希函数用除留取余法构造，用伪随机探测再散列法处理冲突。
【测试数据】
	取读者周围较熟悉的30个人的姓名。
【实现提示】
	如果随机函数自行构造，则应首先调整好随机函数，使其分布均匀。人名的长度均不超过19个字符（最长的人名如：庄双双（zhuangshuangshuang））。字符的取码方法可直接用c语言的toascii函数，并可对过长的人名先作折叠处理。
*/

#include<stdio.h>
#include<stdlib.h>
#define M 69//随机数，值不同，所构建哈希函数不同
#define hashlen 50//哈希表长度
#define namenum 30//人名个数
typedef struct
{
    char *name;//名字拼音的首地址
    int k;//名字的关键字
}name;
name namelist[hashlen];
typedef struct
{
    char *name;//名字拼音首地址
    int k;//拼音对应关键字
    int sl;//查找长度
}hash;//哈希表
hash hashlist[hashlen];
void initnamelist()//简历一个名字列表，存放30个名字
{
    char *f;
    int r,s,i;
    namelist[0].name="zhangzhen";
    namelist[1].name="guanzhenjiang";
    namelist[2].name="cuihanwen";
    namelist[3].name="songhuipeng";
    namelist[4].name="zhanglu";
    namelist[5].name="zhangdi";
    namelist[6].name="fengshuo";
    namelist[7].name="weiziang";
    namelist[8].name="liuyang";
    namelist[9].name="lihuan";
    namelist[10].name="wangyuyang";
    namelist[11].name="lizheng";
    namelist[12].name="zhaoqianlin";
    namelist[13].name="zhangqianyun";
    namelist[14].name="chenshiyu";
    namelist[15].name="liyin";
    namelist[16].name="wangxuanzhi";
    namelist[17].name="liziwei";
    namelist[18].name="yangbinbin";
    namelist[19].name="guoshangpeng";
    namelist[20].name="dongxue";
    namelist[21].name="hujinghui";
    namelist[22].name="xupeng";
    namelist[23].name="zhumingyue";
    namelist[24].name="wanghejie";
    namelist[25].name="wangle";
    namelist[26].name="liushuang";
    namelist[27].name="wanghongjie";
    namelist[28].name="lisheng";
    namelist[29].name="fenglei";
    for(i=0;i<namenum;i++)
    {
        s=0;
        f=namelist[i].name;
        for(r=0;*(f+r)!='\0';r++)//将字符串所有字符对应的ASCII码相加所得整数作为关键词
            s=*(f+r)+s;
        namelist[i].k=s;
    }
}
void CreateHashList()//创建一个哈希表
{
    int i;
    for(i=0;i<hashlen;i++)//对哈希表初始化
    {
        hashlist[i].name=NULL;
        hashlist[i].k=0;
        hashlist[i].sl=0;
    }
    for(i=0;i<hashlen;i++)
    {
        int sum=0;
        int adr=(namelist[i].k)%M;//哈希函数
        int d=adr;
        if(hashlist[adr].sl==0)//不存在冲突
        {
            hashlist[adr].k=namelist[i].k;
            hashlist[adr].name=namelist[i].name;
            hashlist[adr].sl=1;
        }
        else//存在冲突
        {
            do
            {
                d=(d+namelist[i].k%10+3)%M;//伪随机探测再散列处理冲突，可以选取不同值改变
                sum=sum+1;//查找次数+1
            }while(hashlist[d].k!=0);
            hashlist[d].k=namelist[i].k;
            hashlist[d].name=namelist[i].name;
            hashlist[d].sl=sum+1;
        }
    }
}
void showhash()//显示哈希表
{
    int i;
    float average=0;
    printf("\n地址\t关键字\t搜索长度\tH(key)\t\t姓名\n");
    for(i=0;i<50;i++)
    {
        printf("%d",i);
        printf("\t%d",hashlist[i].k);
        printf("\t%d",hashlist[i].sl);
        printf("\t\t%d",hashlist[i].k%M);
        printf("\t\t%s",hashlist[i].name);
        printf("\n");
    }
    for(i=0;i<hashlen;i++)
        average+=hashlist[i].sl;
    average/=namenum;
    printf("\n平均查找长度：ASL(%d)=%f\n",namenum,average);
}
int main()
{
    initnamelist();
    CreateHashList();
    showhash();
}
