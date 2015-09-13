/*【问题描述】
很多涉及图上操作的算法都是以图的遍历操作为基础的。试写一个程序，演示在连通的无向图上访问全部结点的操。

【基本要求】
以邻接多重表为存储结构，实现连通无向图的深度优先和广度优先遍历。以用户指定的结点为起点，分别输出每种遍历下的结点访问序列和相应生成树的边集。

【测试数据】
教科书图7.33。暂时忽略里程，起点为北京。

【实现提示】
设图的结点不超过30个，每个节点用一个编号表示（如果一个图有n个结点，则它们的编号分别为1,2，……，n）。通过输入图的全部边输入一个图，每个边为一个数对，可以对边的输入顺序做出某种限制。注意，生成树的边是有向边，端点顺序不能颠倒。

【选作内容】
（1）借助于栈类型（自己定义和实现），用非递归算法实现深度优先遍历。
（2）以邻接表为存储结构，建立深度优先生成树和广度优先生成树，再按凹入表或树形打印生成树。
（3）正如习题7.8提示中所分析的那样，图的路径遍历要比结点遍历具有更为广泛的应用。再写一个路径遍历算法，求出从北京到广州中途不过郑州的所有简单路径及其里程。

*/

#define MAX 30
#define MAX_LEN 20
#include<stdio.h>
#include<stdlib.h>
int visited[MAX];//全局变量，访问标志数组
int visit[MAX];
//无向图的邻接表存储显示
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
    int adjvex;//该孤所指向的顶点的位置
    struct ArcNode *nextarc;//指向下一条弧的指针
}ArcNode;
typedef struct VNode
{
    char data;//顶点信息
    ArcNode *firstarc;//指向第一条依附该顶点弧的指针
}VNode;
typedef struct
{
    VNode adjlist[MAX];
    int vexnum,arcnum;//图当前顶点数和边数
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
    printf("请输入图的顶点数和边数:");
    scanf("%d%d",&g->vexnum,&g->arcnum);
    getchar();
    for(i=0;i<g->vexnum;i++)
    {
        printf("请输入第%d个顶点的信息:",i+1);
        scanf("%s",&g->adjlist[i].data);
        g->adjlist[i].firstarc=NULL;
    }
    for(i=0;i<g->arcnum;i++)
    {
        printf("请输入第%d条边的起点与终点:",i+1);
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
void BFS(ALGraph g)//广度优先遍历函数
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
    printf("深度优先遍历:\n");
    DFSTraverse(g);
    printf("\n");
    printf("广度优先遍历:\n");
    BFS(g);
}
