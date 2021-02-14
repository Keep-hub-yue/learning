#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
/*
-----------------------------------
     队列 （链式结构）
-----------------------------------
*/
typedef struct LNode{
	int data;
	struct LNode *next;
}LinkNode;
typedef struct {
	LinkNode *front, *rear;
}LinkQueue;
void InitQueue(LinkQueue &Q)//带头结点初始化
{
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}
bool QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	return false;
}




int main()//测试
{
	LinkQueue Q;
	return 0;
}



/*
----------------------------------------
     队列（顺序结构）
----------------------------------------
*/
/*
// 队列只允许在一端插入 另一端删除的线性表
//First In First Out (FIFO) 先进先出  只能在队尾插入，对头删除
//队列元素个数  （Q.rear + MaxSize - Q.front ）% MaxSize 
//若不浪费一个存储空间 可以设置一个变量size 每次删除 都执行 size-- 
//每次插入元素 都执行 size++ 利用size 判断队是否为空和满
//也可以设置 一个变量 tag 每次插入 执行tag = 1；每次删除 执行 tag = 0；Q.front = Q.rear && tag = 1;为满；
//... && tag = 0;为空 

//若初始化时 Q.rear 指向当前元素 则 Q.rear 指向 MaxSize - 1
#define MaxSize 10
typedef struct {
	int data[MaxSize];//静态数组存放数据
	int front, rear;
}SqQueue;
void InitQueue(SqQueue&Q)
{//初始化 使对头指针和队尾指针都指向0
	Q.front = Q.rear = 0;
}
bool QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	return false;
 }
bool EnQueue(SqQueue&Q, int x)
{
	if (Q.front == (Q.rear + 1) % MaxSize)//队列已满， 取模运算实现逻辑上的循环结构
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}
bool DeQueue(SqQueue&Q, int&x)//出队操作
{
	if (Q.front == Q.rear)
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}
bool GetHead(SqQueue Q, int &x)
{
	if (Q.front == Q.rear)
		return false;
	x = Q.data[Q.front];
	return true;
}
*/



/*
----------------------------------------
      链栈（链式存储结构）
----------------------------------------
*/
/*
typedef struct LinkNode {
	int data;
	struct LinkNode *next;
}*LiStack;

void InitStack(LiStack &S)//带头结点 初始化
{
	S = (LinkNode*)malloc(sizeof(LinkNode));
	S->next = NULL;
}

bool StackEmpty(LiStack &S)//判断是否为空
{
	if (S->next == NULL)
		return true;
	else
		return false;
}

bool Push(LiStack&S, int x)//进栈
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL)
		return false;
	s->data = x;
	s->next = S->next;
	S->next = s;
	return true;
}

bool Pop(LiStack&S, int &x)// 出栈
{
	if (S->next == NULL)
		return false;
	LinkNode*q = S->next;
	x = S->data;
	S->next = q->next;
	free(q);
	return true;
}

bool GetTop(LiStack&S, int &x)//读取栈顶元素
{
	if (S->next == NULL)
		return false;
	x = S->data;
	return true;
}
*/



/*
------------------------------------------
           栈 Stack （顺序栈）
------------------------------------------
*/
/*
//只允许在一端进行插入和删除
//Last In first Out (LIFO)后进先出

// 顺序栈

#define MaxSize 10
typedef struct {              //顺序栈 静态创建
	int data[MaxSize];
	int top;                //栈顶指针
}SqStack;
typedef struct {        //共享栈 
	int data[MaxSize]; // 栈满条件 top0 + 1 = top1 ；
	int top0;
	int top1;
}ShStack;



void InitStack(SqStack &S)//初始化，也可以S.top = 0；后续进栈 出栈 读取栈顶 代码都需相应变化
{
	S.top = -1;
}
bool StackEmpty(SqStack S)//判断栈是否为空
{
	if (S.top == -1)
		return true;
	else
		return false;
}

bool Push(SqStack &S, int x)//进栈
{
	if (S.top == MaxSize - 1)
		return false;
	S.data[++S.top] = x;
	return true;
}

bool Pop(SqStack &S, int &x)//出栈
{
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}

bool GetTop(SqStack S, int &x)//读取栈顶
{
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}
*/



/*
---------------------------------------
               静态链表
---------------------------------------
*/
/*
#define MAxSize 10 
typedef struct {
	int data;
	int next;
}SLinkList[MAxSize];



int main(void)
{
	SLinkList L;

	printf("%d\n", sizeof(L));
	return 0;
}
*/



/*
--------------------------------------
              循环链表
--------------------------------------
*/
/*
typedef struct LNode {
	int data;
	struct LNode*next;
} LNode, *LinkList;

bool InitList(LinkList&L)
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = L;//双链表则prior指向尾结点 next指向头结点
	return true;
}
*/


/*
-----------------------------------------------
  双链表的定义、初始化、插入、删除、销毁和遍历
-----------------------------------------------
*/

/*
typedef struct DNode {
	int data;
	struct DNode *prior, *next;
} DNode,*DLinkList;

bool InitDLinkList(DLinkList &L)//双链表的初始化  DLinkList &L 引用类型
{
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)//内存分配失败
		return false;
	L->prior = NULL;
	L->next = NULL;
	return true;
}

bool InsertNextDNote(DNode*p, DNode*s) //在p 结点后插入s结点
{
	if (p == NULL || s == NULL)//非法输入
		return false;
	s->next = p->next;
	if (p->next != NULL)//针对p结点后为NULL的情况
		p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

bool InseertPriorDNote(DNode*p, DNode*s)//前插操作
{
	if (p == NULL || s == NULL)
		return false;
	if (p->prior == NULL)
		return false;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return true;
		
}

bool DLinkListInsert(DLinkList&L, int i, int e) //按位序插入
{
	if (i < 1)
		return false;
	int j = 0;
	DNode *p = L;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	DNode*s = (DNode*)malloc(sizeof(DNode));
	s->next = p->next;
	if (p->next != NULL)
		p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}
bool DNotedelete(DNode*p)//指定结点的删除
{
	if (p == NULL || p->prior == NULL)
		return false;
	p->prior->next = p->next;
	if (p->next != NULL)
		p->next->prior = p->prior;
	free(p);
	return true;
}
bool DeleteNextDNote(DNode*p)
{
	if (p == NULL)
		return false;
	DNode*q = p->next;
	if (q == NULL)
		return false;
	p->next = q->next;
	if (q->next != NULL)
		q->next->prior = p;
	free(q);
	return true;
 }
void DestoryList(DLinkList&L)//销毁双链表
{
	while (L->next != NULL)
		DeleteNextDNote(L);
	free(L);
}

void ListTraversal(DLinkList L)//双链表的安值查找， 按位查找 都只能通过遍历实现 时间复杂度为O(n).
{
	DNode*p = L;
	int i = 0;
	while (p != NULL)//向后遍历
	{
		//......对数据操作
		p = p->next;
		i++;
	}
}
*/



/*
---------------------------
    链表的逆置（带头结点）
---------------------------
*/
/*
typedef struct LNode {
	int data;
	struct LNode*next;
} LNode, *LinkList;

LinkList ReverseList(LinkList*L)
{
	LNode *p ,*q = (*L)->next;

	(*L)->next = NULL;
	while (q != NULL)
	{
		p = q;
		q = q->next;
		p->next = (*L)->next;
		(*L)->next = p;
	}

	return (*L);
}
bool InitList(LinkList*L)//链表的初始化
{
	(*L) = (LNode*)malloc(sizeof(LNode));
	if (*L == NULL)//内存分配失败
		return false;
	(*L)->next = NULL;
	return true;
}

LinkList List_tailInsert(LinkList*L)//指定结点后插 实现尾插法 时间复杂度为O(n)
{
	InitList(L);//初始化
	LNode*s, *r = (*L);
	int x;
	scanf("%d", &x);
	while (x != 999)
	{
		s = (LNode*)malloc(sizeof(LNode));//若写成 s->next = (LNode*)malloc(sizeof(LNode));可以省略r指针？
		s->data = x;
		r->next = s;
		r = s; //使r指向尾结点
		scanf("%d", &x);
	}
	r->next = NULL;
	return *L;
}
void Output(LinkList*L)//带头结点
{
	LNode*p = (*L)->next;
	int j = 1;
	while (p != NULL)
	{
		printf("第%d位：%d\n", j, p->data);
		p = p->next;
		j++;
	}
	return;
}

int main(void)
{
	LinkList L;
	List_tailInsert(&L);
	Output(&L);
	ReverseList(&L);
	printf("逆置的结构后：\n");
	Output(&L);//输出可以不用指针类型
	return 0;
}
*/


/*
----------------------
  头插法（不带头结点）
----------------------
*/
/*
typedef struct LNode {
	int data;
	struct LNode*next;
} LNode, *LinkList;

LinkList List_headInsert(LinkList*L)
{
	(*L) = NULL;
	int x;
	LNode*s;
	scanf("%d", &x);
	while (x != 999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->next = *L;
		s->data = x;
		(*L) = s;
		scanf("%d", &x);
	}
	return (*L);
}
void output(LinkList*L)//不带头结点
{
	printf("单链表内容如下：\n");
	printf("%d\n", (*L)->data);
	LNode*p = (*L)->next;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	return;
}
int main(void)//demo
{
	LinkList L;
	List_headInsert(&L);
	output(&L);

	return 0;
 }
 */



 /*
 ---------------------------
   头插法（带头结点）
 ---------------------------
 */
/*
typedef struct LNode {
	int data;
	struct LNode*next;
} LNode, *LinkList;

LinkList List_HeadInsert(LinkList*L)
{
	int x;
	(*L) = (LNode*)malloc(sizeof(LNode));//初始化
	(*L)->next = NULL;

	LNode*s;
	scanf("%d", &x);
	while (x != 999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = (*L)->next;
		(*L)->next = s;
		scanf("%d", &x);
	}
	return (*L);
}

void Output(LinkList*L)//带头结点
{
	LNode*p = (*L)->next;
	int j = 1;
	while (p != NULL)
	{
		printf("第%d位：%d\n", j, p->data);
		p = p->next;
		j++;
	}
	return;
}

int main(void)
{
	LinkList L;
	List_HeadInsert(&L);
	Output(&L);
	return 0;
}
*/






/*
----------------------------
    尾插法（不带头结点） 
----------------------------
*/
/*
typedef struct LNode {
	int data;
	struct LNode *next;
} LNode, *LinkList;

LinkList TailInsert_List(LinkList*L)
{
	(*L) = NULL;//初始化
	(*L) = (LNode*)malloc(sizeof(LNode));
	int x;
	scanf("%d", &x);
	(*L)->data = x;
	LNode*r, *s  = (*L);	
	scanf("%d", &x);
	while (x != 999)
	{
		s->next = (LNode*)malloc(sizeof(LNode));
		s = s->next;
		s->data = x;
		scanf("%d", &x);
	}
	s->next = NULL;
	return (*L);
}

void output(LinkList*L)//不带头结点
{
	printf("单链表内容如下：\n");
	printf("%d\n", (*L)->data);
	LNode*p = (*L)->next;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	return;
}

int main(void)
{
	LinkList L;
	TailInsert_List(&L);
	output(&L);
	return 0;
}
*/




/*
-------------------------------
单链表的建立(尾插法)带头结点
-------------------------------
*/
/*
typedef struct LNode {
	int data;
	struct LNode*next;
} LNode, *LinkList;

bool InitList(LinkList*L)//链表的初始化
{
	(*L) = (LNode*)malloc(sizeof(LNode));
	if (*L == NULL)//内存分配失败
		return false;
	(*L)->next = NULL;
	return true;
}

bool ListInsert(LinkList*L, int i, int e)//链表的插入
{
	if (i < 1)
		return false;//插入位置不合法
	LNode*p = (*L);
	int j = 0;
	while (p != NULL && j < i - 1)//找到第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	LNode*s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

void Output(LinkList*L)//带头结点
{
	LNode*p = (*L)->next;
	int j = 1;
	while (p != NULL)
	{
		printf("第%d位：%d\n", j, p->data);
		p = p->next;
		j++;
	}
	return;
}

LinkList List_tailInsert(LinkList*L)//指定结点后插 实现尾插法 时间复杂度为O(n)
{
	InitList(L);//初始化
	LNode*s, *r = (*L);
	int x;
	scanf("%d", &x);
	while (x != 999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s; //使r指向尾结点
		scanf("%d", &x);
	}
	r->next = NULL;
	return *L;
}

int main(void)
{
	LinkList L;
	//List_tailInsert(&L);   该方法更优
	InitList(&L);
	int e;
	int length = 0;
	int k;
	printf("请输入最后一个数据：");//作为循环的结束标志
	scanf("%d", &k);
	do
	{
		printf("请输入数据：");
		scanf("%d", &e);
		ListInsert(&L, length + 1, e);

		length++;
	} while (e != k);////利用链表的插入，实现尾插 但是时间复杂度高O(n2)
	printf("链表内容如下：\n");
	Output(&L);
	//64-73行可以封装成一个工具函数 
	return 0;
}
*/



/*
--------------
  求表长度
--------------
*/
/*
typedef struct LNode {
	int data;
	struct LNode*next;
} LNode, *LinkList;

int Length(LinkList*L)
{
	LNode*p = *L;
	int len = 0;
	while (p != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}
*/



/*
---------------------------
       按值查找
---------------------------
*/
/*
typedef struct LNode {
	int data;
	struct LNode*next;
} LNode, *LinkList;

LNode* LocateElem(LinkList*L, int e)
{
	LNode*p = (*L)->next;
	while (p != NULL && p->data != e)
		p = p->next;
	return p;
}
*/






/*
----------------------------
    按位查找
----------------------------
*/
/*
typedef struct LNode {
	int data;
	struct LNode *next;
} LNode, *LinkList;

LNode* GetElem(LinkList*L, int i)
{
	if (1 > i)
		return false;
	LNode*p = *L;
	int j = 0;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}
*/











/*
-----------------------------------
        指定结点的删除
-----------------------------------
*/
/*
typedef struct Lnode {
	int data;
	struct Lnode *next;
}Lnode, *Linklist;

bool Listdelete(Lnode *p)//该方法在删除最后一位的时候不行，删除最后一位只能传入头指针 遍历链表 找到其前驱结点
{
	if (p == NULL)
		return false;
	Lnode *q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
	return true;
	
}
*/



/*
------------------------------
删除第i个结点（不带头结点）
------------------------------
*/
/*
typedef struct Lnode {
	int data;
	struct Lnode *next;
}Lnode, *Linklist;

bool Listdelete(Linklist *L, int i,int e)
{
	if (i < 1)//i值不合法
		return false;
	Lnode *p = *L;
	Lnode *q;
	if (1 == i)//删除第一个结点的操作
	{
		(*L) = p->next;
		e = (*L)->data;
		return true;
	}
	int j = 1;//p指向当前结点的位序
	while (p != NULL && j < i - 1)//找到第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL)// 当p 为NULL 时 i值不合法 i超过了 链表的长度
		return false;
	if (p->next == NULL)//第i-1后面为NULL
		return false;
	q = p->next;
	e = q->data;	
	p->next = q->next;
	free(q);
}
*/





/*
-------------------------------------
删除第i个结点（带头结点）
-------------------------------------
*/
/*
typedef struct Lnode {
	int data;
	struct Lnode *next;
}Lnode, *Linklist;

bool Listdelete(Linklist *L, int i, int e)
{
	if (i < 1)
		return false;
	Lnode *p = (*L);
	int j = 0;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	Lnode *q = p->next;
	e = p->data;
	p->next = q->next;
	free(q);//释放第i个内存
	return true;
}
*/




/*
------------------------------------
指定结点的前插操作（单链表）
------------------------------------
*/
/*
//也可以传入头指针，遍历链表 找到p的前驱结点，在执行p前驱结点的后插操作
typedef struct Lnode {
	int data;
	struct Lnode *next;
}Lnode, *Linklist;


bool InsertPriorNode(Lnode*p, int e)//不用传入头指针，先把二者数据调换，在执行后插操作
{
	if (p == NULL)
		return false;
	Lnode *s = (Lnode*)malloc(sizeof(Lnode));
	if (s == NULL)//内存分配失败
		return false;
	s->data = p->data;
	p->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
*/


/*
--------------------------------
指定结点的后插操作（单链表）
--------------------------------
*/
/*
typedef struct Lnode {
	int data;
	struct Lnode *next;
}Lnode, *Linklist;

bool InsertNextNode( Lnode*p,int e)
{
	if (p == NULL)
		return false;
	Lnode *s = (Lnode*)malloc(sizeof(Lnode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;

}
*/



/*
--------------------------------
弹链表的按位序插入（不带头结点）
--------------------------------
*/
/*
typedef struct Lnode {
	int data;
	struct Lnode *next;
} Lnode, *Linklist;

bool listinsert(Linklist *L, int i, int e)
{
	if (1 == i)
	{
		Lnode *s = (Lnode*)malloc(sizeof(Lnode));
		s->next = *L;
		*L = s;
	}
	if (i < 1)
		return false;
	Lnode *p;
	int j = 1;//当前p指向的结点位序
	while (p != NULL && j < i - 1)//寻找到第i-1个结点 即i 结点前一个
	{
		p = (*L)->next;
		j++;
	}
	if (p == NULL)
		return false;
	Lnode *s = (Lnode*)malloc(sizeof(Lnode));
	s->data = e;
	s->next = p->next;
	p->next = s;
}

int main(void)
{
	Linklist L;
	//省略链表的初始化和赋值等操作
	listinsert(&L, 3, 6);

	return 0;
}
*/


/*
--------------------------------
单链表的按位序插入（带头结点）
--------------------------------
*/
/*
typedef struct Lnode {
	int data;
	struct Lnode *next;
} Lnode, *Linklist;



bool listinsert(Linklist*p, int i, int e)
{
	if (i < 1)
		return false;
	Lnode *q;
	int j = 0;//当前q指向的结点位序 0结点即 头结点
	q = (*p);
	while (q != NULL && j < i - 1)//寻找到第i-1个结点 即i 结点前一个
	{
		q = q->next;
			j++;
	}
	if (q == NULL)
		return false;
	Lnode *s = (Lnode*)malloc(sizeof(Lnode));
	s->data = e;
	s->next = q->next;
	q->next = s;
	return true;
}
*/




/*
--------------------------
带头结点链表的定义及初始化
--------------------------
*/
/*
typedef struct Lnode {
	int data;
	struct Lnode *next;
} Lnode, *Linklist;

bool Initlist(Linklist *p)
{
	*p = (Lnode*)malloc(sizeof(Lnode));
	if (*p == NULL)
		return false;
	(*p)->next = NULL;
	return true;
}

int main(void)
{
	Linklist L;
	Initlist(&L);

	return 0;
}
*/





/*
----------------------------
不带头节点链表的定义及初始化
-----------------------------
*/
/*
typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode,*Linklist;

bool Initlist(Linklist *p)
{
	*p = NULL;
	return true;
}

int main(void)
{
	Linklist L;

	Initlist(&L);
	
	return 0;
}
*/




/*
--------------------------
顺序表的查找(按值)
--------------------------
*/
/*
#define MaxSize 10

typedef struct {
	int *data;
	int length;
}selist;

void Initlist(selist*q )
{
	q->data = (int*)malloc(sizeof(int)*MaxSize);
	q->length = 0;
	for (int i = 0; i < MaxSize; ++i)
	{
		if ((i+1) % 2)
		{
			q->data[i] = i + 1;
			continue;
		}
		q->data[i] = 0;
	}
	q->length = MaxSize;
}

int locateelem(selist*q, int i)//寻找第一个元素值为i的位序。
{
	for (int j = 0; j < q->length; ++j)
		if (i == q->data[j])
			return j + 1;
	return 0;
}

int main(void)
{
	selist L;
	Initlist(&L);
	for (int i = 0; i < L.length; ++i)
		printf("%d\n", L.data[i]);
	printf("%d", locateelem(&L, 7));

	return 0;
}
*/










/*
------------------------
    顺序表的查找(按位)
------------------------
*/
/*
#define MaxSize 10

typedef struct {
	int * data;
	int length;
}selist;

void Initlist(selist*q)
{
	q->data = (int*)malloc(sizeof(int)*MaxSize);
	q->length = 0;

}

int getelem(selist*q, int i)
{
	return q->data[i - 1];
}

int main(void)
{
	selist L;
	Initlist(&L);
	for (int i = 0; i < MaxSize; ++i)
		L.data[i] = i;
	printf("%d\n", getelem(&L, 3));

	return 0;
}
*/






/*
--------------------
顺序表中数据的删除
--------------------
*/
/*
#define MaxSize 10

typedef struct {
	int data[MaxSize];
	int length;
}list;

void Inilist(list *q)
{
	for (int i = 0; i < MaxSize; i++)
		q->data[i] = 0;
	q->length = 0;
	return ;

}
bool listDelete(list*q, int i, int *p)
{
	if (i<1 || i>q->length)
		return false;
	*p = q->data[i-1];
	for (int j = i; j < q->length; j++)
		q->data[j - 1] = q->data[j];
	q->length--;
	return true;

}
int main(void)
{
	list L;
	Inilist(&L);
	for (int i = 0; i < 5; ++i)
	{
		L.data[i] = i + 1;
		L.length++;
	}
	for (int k = 0; k < L.length; ++k)
		printf("L.data[%d] = %d\n", k, L.data[k]);
	int e = -1;
		
	if (listDelete(&L, 3, &e))
		printf("删除成功，其值为%d\n", e);
	else
		printf("位序i不合法\n");
	for (int k = 0; k < L.length; ++k)
		printf("L.data[%d] = %d\n", k, L.data[k]);

	return 0;
}
*/





/*
---------------------
顺寻表的插入和删除
---------------------
*/
/*
#define MaxSize 10
  
struct Seqlist {
	int data[MaxSize];
	int length;
};

void InitList(struct Seqlist * p)//顺序表初始化
{
	for (int i = 0; i < MaxSize; ++i)
		p->data[i] = 0;
	p->length = 0;
}

void input(struct Seqlist *p)//顺序表赋值,没有代表意义，只是为了给顺序表赋上不同的值，便于后面的理解
{
	for (int i = 0; i < 5; ++i)
	{
		p->data[i] = i + 1;
		p->length++;
	}
}

bool ListInsert(struct Seqlist*p, int j, int k) //实现顺表的插入
{
	if (j<1 || j > p->length + 1)//插入位置不合法
		return false;
	if (p->length == MaxSize)//超过最大长度
		return false;
	for (int i = p->length + 1; i >= j - 1; i--)
		p->data[i + 1] = p->data[i];
	p->data[j - 1] = k;
	p->length++;
	return true;
}

void output(struct Seqlist*p)//输出
{
	for (int i = 0; i < p->length; ++i)
		printf("data[%d] = %d\n", i, p->data[i]);
}

int main()
{
	int i;
	struct Seqlist L;
	InitList(&L);
	input(&L);
	output(&L);
	int a = 7;
	i = ListInsert(&L,3,a);
	i ? printf("插入成功！\n") : printf("插入失败！\n");//检测是否插入成功
	output(&L);

	return 0;
}
*/



/*
-----------------------
顺序表的动态创建及扩展
-----------------------
*/
/*
constexpr auto InitSize = 10;

typedef struct {
	int * data;
	int length;
	int MAXSize;

}seqlist ;

void InitList(seqlist* p)
{
	p->data = (int *)malloc(sizeof(int)*InitSize);
	p->length = 0;
	p->MAXSize = InitSize;
}

void IncreaseSize(seqlist* p, int len)
{
	int * q = p->data;
	p->data= (int *)malloc(sizeof(int*)*(InitSize + len));
	for (int i = 0; i < InitSize; ++i)
		p->data[i] = q[i];
	p->length = 0;
	p->MAXSize = InitSize + len;
	free(q);
	return;
}

void output(seqlist *L)
{
	for (int i = 0; i < L->MAXSize; ++i)
		printf("data[%d]=%d\n", i, L->data[i]);
	return;
}

int main(void)
{
	seqlist L;
	InitList(&L);
	IncreaseSize(&L, 5);
	output(&L);

	return 0;
}
  */




/*
-----------------------------
顺序表的静态分配
--------------------------
*/
/*
#define MAXSIZE 10
typedef struct {
	int data[MAXSIZE]; // 静态数组存放数据
	int length;//顺序表当前长度
}sqlist;//顺序表的类型定义

void InitList(sqlist * L)//顺序表初始化
{
	for (int i = 0; i < MAXSIZE; ++i)
		(*L).data[i] = 0;//指针变量->   在计算机内部 会转化为 （*指针变量）.   p[i] 等价于 *（p+i）
	L->length = 0;

}

int main(void)
{
	sqlist L;
	InitList(&L);
	for (int i = 0; i < MAXSIZE; ++i)
		printf("data[%d] = %d\n", i, L.data[i]);

	return 0;
}
*/