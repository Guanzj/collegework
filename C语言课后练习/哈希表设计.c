/*������������
���ĳ�����壨���������ڵİ༶���еġ����������һ����ϣ��ʹ��ƽ�����ҳ��Ȳ�����R�������Ӧ�Ľ���Ͳ�����
������Ҫ��
	��������Ϊ�й��������ĺ���ƴ����ʽ���������ϣ�����������30����ȡƽ�����ҳ��ȵ�����Ϊ2.��ϣ�����ó���ȡ�෨���죬��α���̽����ɢ�з������ͻ��
���������ݡ�
	ȡ������Χ����Ϥ��30���˵�������
��ʵ����ʾ��
	�������������й��죬��Ӧ���ȵ��������������ʹ��ֲ����ȡ������ĳ��Ⱦ�������19���ַ�����������磺ׯ˫˫��zhuangshuangshuang�������ַ���ȡ�뷽����ֱ����c���Ե�toascii���������ɶԹ��������������۵�����
*/

#include<stdio.h>
#include<stdlib.h>
#define M 69//�������ֵ��ͬ����������ϣ������ͬ
#define hashlen 50//��ϣ����
#define namenum 30//��������
typedef struct
{
    char *name;//����ƴ�����׵�ַ
    int k;//���ֵĹؼ���
}name;
name namelist[hashlen];
typedef struct
{
    char *name;//����ƴ���׵�ַ
    int k;//ƴ����Ӧ�ؼ���
    int sl;//���ҳ���
}hash;//��ϣ��
hash hashlist[hashlen];
void initnamelist()//����һ�������б����30������
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
        for(r=0;*(f+r)!='\0';r++)//���ַ��������ַ���Ӧ��ASCII���������������Ϊ�ؼ���
            s=*(f+r)+s;
        namelist[i].k=s;
    }
}
void CreateHashList()//����һ����ϣ��
{
    int i;
    for(i=0;i<hashlen;i++)//�Թ�ϣ���ʼ��
    {
        hashlist[i].name=NULL;
        hashlist[i].k=0;
        hashlist[i].sl=0;
    }
    for(i=0;i<hashlen;i++)
    {
        int sum=0;
        int adr=(namelist[i].k)%M;//��ϣ����
        int d=adr;
        if(hashlist[adr].sl==0)//�����ڳ�ͻ
        {
            hashlist[adr].k=namelist[i].k;
            hashlist[adr].name=namelist[i].name;
            hashlist[adr].sl=1;
        }
        else//���ڳ�ͻ
        {
            do
            {
                d=(d+namelist[i].k%10+3)%M;//α���̽����ɢ�д����ͻ������ѡȡ��ֵͬ�ı�
                sum=sum+1;//���Ҵ���+1
            }while(hashlist[d].k!=0);
            hashlist[d].k=namelist[i].k;
            hashlist[d].name=namelist[i].name;
            hashlist[d].sl=sum+1;
        }
    }
}
void showhash()//��ʾ��ϣ��
{
    int i;
    float average=0;
    printf("\n��ַ\t�ؼ���\t��������\tH(key)\t\t����\n");
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
    printf("\nƽ�����ҳ��ȣ�ASL(%d)=%f\n",namenum,average);
}
int main()
{
    initnamelist();
    CreateHashList();
    showhash();
}
