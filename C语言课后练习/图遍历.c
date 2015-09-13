/*������������
�ܶ��漰ͼ�ϲ������㷨������ͼ�ı�������Ϊ�����ġ���дһ��������ʾ����ͨ������ͼ�Ϸ���ȫ�����Ĳ١�

������Ҫ��
���ڽӶ��ر�Ϊ�洢�ṹ��ʵ����ͨ����ͼ��������Ⱥ͹�����ȱ��������û�ָ���Ľ��Ϊ��㣬�ֱ����ÿ�ֱ����µĽ��������к���Ӧ�������ı߼���

���������ݡ�
�̿���ͼ7.33����ʱ������̣����Ϊ������

��ʵ����ʾ��
��ͼ�Ľ�㲻����30����ÿ���ڵ���һ����ű�ʾ�����һ��ͼ��n����㣬�����ǵı�ŷֱ�Ϊ1,2��������n����ͨ������ͼ��ȫ��������һ��ͼ��ÿ����Ϊһ�����ԣ����ԶԱߵ�����˳������ĳ�����ơ�ע�⣬�������ı�������ߣ��˵�˳���ܵߵ���

��ѡ�����ݡ�
��1��������ջ���ͣ��Լ������ʵ�֣����÷ǵݹ��㷨ʵ��������ȱ�����
��2�����ڽӱ�Ϊ�洢�ṹ��������������������͹���������������ٰ����������δ�ӡ��������
��3������ϰ��7.8��ʾ����������������ͼ��·������Ҫ�Ƚ��������и�Ϊ�㷺��Ӧ�á���дһ��·�������㷨������ӱ�����������;����֣�ݵ����м�·��������̡�

*/

#define MAX 30
#define MAX_LEN 20
#include<stdio.h>
#include<stdlib.h>
int visited[MAX];//ȫ�ֱ��������ʱ�־����
int visit[MAX];
//����ͼ���ڽӱ�洢��ʾ
typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode;
typedef struct
{
    QNode *front;
    QNode *rear;
}Queue;
typedef struct ArcNode
{
    int adjvex;//�ù���ָ��Ķ����λ��
    struct ArcNode *nextarc;//ָ����һ������ָ��
}ArcNode;
typedef struct VNode
{
    char data;//������Ϣ
    ArcNode *firstarc;//ָ���һ�������ö��㻡��ָ��
}VNode;
typedef struct
{
    VNode adjlist[MAX];
    int vexnum,arcnum;//ͼ��ǰ�������ͱ���
}ALGraph;
int InitQueue(Queue *p)
{
    p->front=p->rear=(QNode *)malloc(sizeof(QNode));
    if(!p->front)
        return 0;
    p->front->next=NULL;
    return 1;
}
int  EnQueue(Queue *q,int e)
{
    QNode *p;
    p=(QNode *)malloc(sizeof(QNode));
    if(!p)
        return 0;
    p->data=e;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
    return 1;
}
int  DeQueue(Queue *q,int *e)
{
    QNode *p;
    if(q->front==q->rear)
        return 0;
    p=q->front->next;
    *e=p->data;
    q->front->next=p->next;
    if(q->rear==p)
        q->rear=q->front;
    free(p);
    return 1;
}
int empty(Queue *q)
{
    if(q->front==q->rear)
        return ;
    else return 0;
}
int CreateGraph(ALGraph *g)
{
    int i,j,k;
    ArcNode *p;
    printf("������ͼ�Ķ������ͱ���:");
    scanf("%d%d",&g->vexnum,&g->arcnum);
    getchar();
    for(i=0;i<g->vexnum;i++)
    {
        printf("�������%d���������Ϣ:",i+1);
        scanf("%s",&g->adjlist[i].data);
        g->adjlist[i].firstarc=NULL;
    }
    for(i=0;i<g->arcnum;i++)
    {
        printf("�������%d���ߵ�������յ�:",i+1);
        scanf("%d%d",&j,&k);
        p=(ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex=k;
        p->nextarc=g->adjlist[j].firstarc;
        g->adjlist[j].firstarc=p;
        p=(ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex=j;
        p->nextarc=g->adjlist[k].firstarc;
        g->adjlist[k].firstarc=p;
    }
}
void DFS(ALGraph g,int v)
{
    ArcNode *p;
    visited[v]=1;
    printf("%c ",g.adjlist[v].data);
    p=g.adjlist[v].firstarc;
    while(p)
    {
        if(!visited[p->adjvex])
            DFS(g,p->adjvex);
        p=p->nextarc;
    }
}
void DFSTraverse(ALGraph g)
{
    int i;
    for(i=0;i<g.vexnum;i++)
        visited[i]=0;
    for(i=0;i<g.vexnum;i++)
    {
        if(!visited[i])
            DFS(g,i);
    }
}
void BFS(ALGraph g)//������ȱ�������
{
	int i,k;
	Queue q;
	ArcNode *p;
	for(i=0;i<g.vexnum;i++);
		visit[i]=0;
	InitQueue(&q);
	for(i=0;i<g.vexnum;i++)
		if (!visit[i])
		{
			printf("%c ",g.adjlist[i].data);
			visited[i]=1;
			EnQueue(&q,i);
			while (!empty(&q))
			{
				DeQueue(&q,&k);
				p=g.adjlist[k].firstarc;
				while (p)
				{
					if (!visited[p->adjvex])
					{
						printf("%c ",g.adjlist[p->adjvex].data);
						visited[p->adjvex]=1;
						EnQueue(&q,p->adjvex);
					}
					p=p->nextarc;
				}
			}
		}
}
int  main()
{
    ALGraph g;
    CreateGraph(&g);
    printf("������ȱ���:\n");
    DFSTraverse(g);
    printf("\n");
    printf("������ȱ���:\n");
    BFS(g);
}
