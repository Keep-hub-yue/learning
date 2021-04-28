#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/*
-----------------------------
		����������
-----------------------------
*/

typedef struct Threadnode {
	int data;
	Threadnode *lchild, *rchild;
	int ltag, rtag;
}Threadnode,*ThreadTree;

void visit(Threadnode *q, Threadnode* &pre)//����P ��pre ���п�ָ��Ľ��������
{
	if (!q->lchild)
	{
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre && !pre->rchild)
	{
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
}
void PreThread(ThreadTree T,Threadnode* &pre )//���������ͬʱ������������
{
	if (T)
	{
		visit(T,pre	);
		if (T->ltag == 0)//���������ѭ��
			PreThread(T->lchild,pre);
		PreThread(T->rchild,pre);
	}
}
void CreateThreadTree(ThreadTree T)
{
	Threadnode *pre = NULL;
	if (T)
		PreThread(T,pre);
	if (!pre->rchild)//�������һ�����
		pre->rtag = 1;
		
}
/*��������������������ǰ���ͺ��*/
/*
------------------------------------------------------
	�����������������п����ҵ�ָ�����ǰ���ͺ��
	����ʹ�����취�����������±�����������
	������������������ֻ���ҵ���̣��ں���������������
	ֻ���ҵ�ǰ����
-----------------------------------------------------
*/
//�Һ��
Threadnode* firstnode(Threadnode* q)//�ҵ����������һ�����ʵĽ�㡣
{
	while (q->ltag == 0)
		q = q->lchild;
	return q;
}

Threadnode* nextnode(Threadnode* q)
{
	if (q->rtag == 1)
		return q->rchild;
	else
		return firstnode(q->rchild);
}

//�Զ����������ı������ǵݹ�
void inorder(ThreadTree T)
{
	for (Threadnode*p = firstnode(T); !p; nextnode(p))
		...;//ʵ�ֶ�p�ķ��ʲ���
}
//��ǰ��
Threadnode* nextnode1(Threadnode *q)
{
	if (q->ltag == 1)
		return q->lchild;
	else
	{
		while (q->lchild->rtag == 0)
			q = q->rchild;
		return q;
	}
}

/*
------------------------------------
		����������
------------------------------------
*/
/*����Ŀ���������ǰ��*/
/*
typedef struct BiTnode {
	int data;
	BiTnode *lchild, *rchild;
}BiTnode,*Bitree;

//BiTnode *p;//ָ��Ŀ����
//BiTnode *pre = NULL;//ָ��ǰ���ʽ���ǰ��
//BiTnode	 *final = NULL;//��¼���յĽ��

void visit(BiTnode *q)//�ҵ�ָ������ǰ���������ݹ��㷨�е�visit������
{
	if (q == p)
		final = pre;
	else
		pre = q;
}
//�������
void inorder(Bitree T)
{
	if (T)
	{
		inorder(T->lchild);
		visit(T);//��visit�������޸ģ�����ʵ�ֲ�ͬ��Ŀ��
		inorder(T->rchild);
	}
}
*/
/*����������*/
/*
typedef struct ThreadNode {
	int data;
	ThreadNode *lchild, *rchild;
	int ltag, rtag;
}ThreadNode,*ThreadTree;

ThreadNode *pre = NULL;

void Visit(ThreadNode *q)
{
	if (!q->lchild)
	{
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre && !pre->rchild)
	{
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
}

void inThread(ThreadTree T)
{
	if (T)
	{
		inThread(T->lchild);
		Visit(T);
		inThread(T->rchild);
	}
}

void CreatThread(ThreadTree T)
{
	inThread(T);
	pre->rchild = NULL;//�������һ�����ʱ���䲢����������������������һ�ε���Visit����������Ҫ�����һ�������е�������
	pre->rtag = 1;
}
*/
/*
---------------------------------------
              ��(������)
--------------------------------------
*/
//�������Ľ�㣨˳��洢��
//struct TreeNode {
//	int value;
//	bool isempty;
//};

//int main(void)
//{
//	TreeNode T[100];//��һ��λ�ÿ��Կ���
//	for (int i = 0;i<100;++i)//��ʼ��
//	{
//		T[i].isempty = true;
//	}
	/* 
	------------------------------------
	����Ԫ�صı������ȫ�������Ķ�Ӧ��
	���±��ʾ����֮����߼���ϵ��
	iԪ�ص�  ���� Ϊ2i
			�Һ��� Ϊ2i+1
		˫�׽��Ϊ i/2����ȡ��
		���Ҳ���Լ������


		˳��洢�ṹֻ�ʺϴ洢��ȫ������
	*/
// ��ʽ�洢
/*
typedef struct BiTNode {
	int data;//������
	BiTNode *lchild, *rchild;//���Һ���ָ��
}BiTNode,*BiTree;
//�ҵ�һ�����ĺ��ӽ��ܼ򵥣�Ѱ�Ҹ��ڵ���Ҫ�Զ��������б���
//�������õ�����㣬�����ڶ�����ʱ���븸���ָ�롣����������
int main()
{
	BiTree root = NULL;//����һ����

	root = (BiTNode *)malloc(sizeof(BiTNode));//�������㡣
	root->data = 1;
	root->lchild = NULL;
	root->rchild = NULL;

	BiTNode*p = (BiTNode*)malloc(sizeof(BiTNode));//�����½��
	p->data = 2;
	p->lchild = NULL;
	p->rchild = NULL;
	root->lchild = p;//����������λ�á�

}
*/
/* �������ı���*/
/*
void visit(BiTree T);
//�������
void Preorder(BiTree T)
{
	if (T) {
		visit(T);
		Preorder(T->lchild);
		Preorder(T->rchild);
	}
}
//�������
void Inorder(BiTree T)
{
	if (T)
	{
		Inorder(T->lchild);
		visit(T);
		Inorder(T->rchild);
	}
}
//�������
void Posorder(BiTree T)
{
	Posorder(T->lchild);
	Posorder(T->rchild);
	visit(T);
}
//���������
int TreeDepth(BiTree T)
{
	if (!T)
		return 0;
	else
	{
		int l = TreeDepth(T->lchild);
		int r = TreeDepth(T->rchild);
		return l > r ? l + 1 : r + 1;
	}
}
*/
//��α���
/*
���ø������У��Ƚ���������
�����зǿգ����ͷ�����ӣ����������Һ��ӽ��������ӣ�������ڣ�
�ظ���һ��������Ϊ�ա�
*/
/*
void Levelordder()
{
	...;//ʡ�Զ�����ش���
	while (!isempty)
	{
		DeQueue(Q, p);//�����ڱ���ָ��
		visit(p);
		if (p->lchild)
			Enqueue(Q, p->lchild);
		if (p->rchild)
			Enqueue(Q, p->rchild);
	}

}
*/

/*
---------------------------------------------
             KMP�㷨
---------------------------------------------
*/
/*
#define MANSIze 10
typedef struct {
	char ch[MANSIze];//��̬����
	int length ;
}SString;
//��next����
void Get_next(SString T,int next[])
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

//KMp �㷨�Ż� �����ֲ�ƥ��ʱ�����ݵ��ַ���T.ch[next[j]]���뵱ǰ�ַ���T.ch[j]��һ�� nextval[j] = nextval[next[j]];

void Get_nextval(int nextval[])
{
	int next[T.length + 1];
	Get_next(T, next);
	int nextval[T.length + 1];
	nextval[1] = 0;
	for (int j = 2; j <= T.length + 1; ++j)
	{
		if (T.ch[j] == T.ch[next[j]])
			nextval[j] = nextval[next[j]];
		else
			nextval[j] = next[j];
	}
}


int Index_KMP(SString S, SString T)
{
	int i = 1, j = 1;
	int next[T.length+1];
	Get_next(T, next);
	while ( i <= S.length && j <= T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
		
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}
*/

/*
--------------------------------------------
	          ��
--------------------------------------------
*/
/*
#define MANSIze 10
typedef struct {
	char ch[MANSIze];//��̬����
	int length;
}SString;

void StrAsign(SString &S,char ch[])//��ֵ ��ʼ��
{	
	int i = 1;
	for (; ch[i - 1] != '\0'; ++i)
	{
		S.ch[i] = ch[i - 1];
	}
	S.length = i-1;
}

bool SubString(SString &Sub, SString T, int pos, int len)//���Ӵ�
{
	if (T.length - pos + 1 < len)
		return false;
	for (int i = pos; i - pos < len; ++i)
	{
		Sub.ch[i - pos + 1] = T.ch[i];
	}
	Sub.length = len;
	return true;
}

int StrCompare(SString S, SString T)//�ַ����Ƚ�
{
	for (int i = 1; i <= S.length && i <= T.length; ++i)
	{
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}

int Index(SString S, SString T)//��λ�Ӵ�λ�ã����ص�һ�γ��ֵ�λ�á�
{	
	SString Sub;
	for (int i = 1; S.length - i >= T.length; ++i)
	{
		SubString(Sub, S, i, T.length);
		if (StrCompare(Sub, T) == 0)
			return i;//�����Ӵ�λ��
	}
	return 0;//û���Ӵ�
}

int main()
{
	SString S;
	SString T;
	StrAsign(S, "wangdao");
	StrAsign(T, "gda");
	printf("�Ӵ�λ��%d\n", Index(S, T));

	return 0;
}
*/
/*
-------------------------------------------
   ջ��Ӧ�� ���� ���ʽ��ֵ
-------------------------------------------
*/
/*
#define MaxSize 50

typedef struct {//�����ջ
	char data[MaxSize];
	int top;
}op;
typedef	 struct {
	float data[MaxSize];
	int top;
}st;
float eva(float a, float b, char ch)
{
	switch (ch)
	{
	case'+':
		return a + b;
	case'-':
		return a - b;
	case'/':
		return a / b;
	case'*':
		return a * b;
	}
}

float EvaluateExpression(char exp[])
{
	op ch;
	st num;
	float a, b;
	ch.top = -1; //��ʼ�� ch
	num.top = -1;
	for (int i = 0; exp[i] != '\0'; i++)
	{
		switch (exp[i])
		{
		case '(':
			ch.data[++ch.top] = exp[i]; break;
		case ')':
			while (ch.data[ch.top] != '(')
			{
				b = num.data[num.top--];
				a = num.data[num.top--];
				num.data[++num.top] = eva(a, b, ch.data[ch.top--]);
			}
			ch.top--; break;			
		case'+':
		case'-':

			if (ch.data[ch.top] == '*' || ch.data[ch.top] == '/' || ch.data[ch.top] == '+' || ch.data[ch.top] == '-')
			{
				b = num.data[num.top--];
				a = num.data[num.top--];
				num.data[++num.top] = eva(a, b, ch.data[ch.top--]);
				ch.data[++ch.top] = exp[i];
			}
			else
				ch.data[++ch.top] = exp[i]; break;

		case'*':
		case'/':
			if (ch.data[ch.top] == '*' || ch.data[ch.top] == '/')
			{
				b = num.data[num.top--];
				a = num.data[num.top--];
				num.data[++num.top] = eva(a, b, ch.data[ch.top--]);
				ch.data[++ch.top] = exp[i];
			}
			else
				ch.data[++ch.top] = exp[i]; break;
		default:
			num.data[++num.top] = (float)(exp[i] - '0');
			for (int j = i + 1; exp[j] != ')'&& exp[j] != '+'&& exp[j] != '-'&& exp[j] != '*'&&exp[j] != '/'; ++j)
			{
				num.data[num.top] = 10 * num.data[num.top] + (exp[j] - '0');
				i++;
			}

		}
	}
	while (ch.top != -1)
	{
		b = num.data[num.top--];
		a = num.data[num.top--];
		num.data[++num.top] = eva(a, b, ch.data[ch.top--]);
	}
	return num.data[num.top];
}
int main()//����ͨ��
{
	char exp[100] = "23-45*23/(78-56)";
	printf("%.2f\n", EvaluateExpression(exp));
	return 0;
}
*/


/*
---------------------------------------
   ջ��Ӧ�á�������ƥ��
---------------------------------------
*/
/*
#define MaxSize 10
typedef struct {
	char data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack &S)
{
	S.top = -1;
}

bool StackEmpty(SqStack S)
{
	if (S.top == -1)
		return true;
	return false;
}

bool Push(SqStack &S, char x)
{
	if (S.top == MaxSize - 1)//ջ��
		return false;
	S.data[++S.top] = x;
	return true;
}

bool Pop(SqStack &S, char &x)
{
	if (S.top == -1)//ջ��
		return false;
	x = S.data[S.top--];
	return true;
}
bool BracketCheck(char str[], int length)
{
	SqStack S;
	InitStack(S);
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')//ɨ�赽��������� ֱ����ջ
			Push(S, str[i]);
		else//�����������1��ջΪ�� 2��ջ��Ϊ��
		{
			if (StackEmpty(S))
				return false;
			char topelem;
			Pop(S, topelem);
			if (str[i] == ')' && topelem != '(')
				return false;
			if (str[i] == ']' && topelem != '[')
				return false;
			if (str[i] == '}' && topelem != '{')
				return false;
		}
	}
	return StackEmpty(S);
}

int main(void) // ����
{
	char str1[] = { '(','(','{','}',')',')','[',']'};
	char str2[] = { '(','(','{','}',')',')','[','{' };
	char str3[] = { '(','(','{','}',')',')','[',']',')' };
	if (BracketCheck(str1,8))
		printf("ƥ��\n");
	else
		printf("��ƥ��\n");
	if (BracketCheck(str2,8))
		printf("ƥ��\n");
	else
		printf("��ƥ��\n");
	if (BracketCheck(str3,9))
		printf("ƥ��\n");
	else
		printf("��ƥ��\n");
	return 0;

}//����ͨ��
*/





/*
--------------------------------------
       ˫������
--------------------------------------
*/
// ջ��ֻ����һ�˲����ɾ�������Ա�
// ���У�ֻ����һ�˲��� ��һ��ɾ�������Ա�
//˫�˶��У��������˲��������ɾ�������Ա�
//���⻹ �������޵�˫�˶��� ��������޵�˫�˶���


/*
------------------------------------
   ���У���ʽ�ṹ������ͷ���
------------------------------------
*/
/*
typedef struct LNode {
	int data;
	struct LNode *next;
}LinkNode;
typedef struct {
	LinkNode *front, *rear;
}LinkQueue;
void InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = NULL;
}

void EnQueue(LinkQueue &Q, int x)
{
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL)
	{
		Q.front = s;
		Q.rear = s;
	}
	else
	{
		Q.rear->next = s;
		Q.rear = s;
	}
}
bool DeQueue(LinkQueue &Q, int &x)
{
	if (Q.front == Q.rear && Q.front == NULL)// �ն�
		return false;
	LinkNode *q = Q.front;
	x = q->data;	
	Q.front = q->next;
	if (Q.rear == q)
		Q.front = Q.rear = NULL;
	free(q);
	return true;
}
*/





/*
-----------------------------------
	 ���� ����ʽ�ṹ����ͷ���
-----------------------------------
*/
/*
typedef struct LNode {
	int data;
	struct LNode *next;
}LinkNode;
typedef struct {
	LinkNode *front, *rear;
}LinkQueue;
void InitQueue(LinkQueue &Q)//��ͷ����ʼ��
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
void EnQueue(LinkQueue &Q, int x) //��Ӳ��� *** ���Զ����bool�ͣ����Ǳ߼����� 
{
	LinkNode * s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}
bool DeQueue(LinkQueue &Q, int &x) // ���Ӳ���
{
	if (Q.front == Q.rear)
		return false;
	LinkNode *q = Q.front->next;
	x = q->data;
	Q.front = q->next;
	if (Q.rear == q)//ɾ�����һ�����
		Q.rear = Q.front;
	free(q);
	return true;
}
*/




/*
----------------------------------------
	 ���У�˳��ṹ��
----------------------------------------
*/
/*
// ����ֻ������һ�˲��� ��һ��ɾ�������Ա�
//First In First Out (FIFO) �Ƚ��ȳ�  ֻ���ڶ�β���룬��ͷɾ��
//����Ԫ�ظ���  ��Q.rear + MaxSize - Q.front ��% MaxSize
//�����˷�һ���洢�ռ� ��������һ������size ÿ��ɾ�� ��ִ�� size--
//ÿ�β���Ԫ�� ��ִ�� size++ ����size �ж϶��Ƿ�Ϊ�պ���
//Ҳ�������� һ������ tag ÿ�β��� ִ��tag = 1��ÿ��ɾ�� ִ�� tag = 0��Q.front = Q.rear && tag = 1;Ϊ����
//... && tag = 0;Ϊ��

//����ʼ��ʱ Q.rear ָ��ǰԪ�� �� Q.rear ָ�� MaxSize - 1
#define MaxSize 10
typedef struct {
	int data[MaxSize];//��̬����������
	int front, rear;
}SqQueue;
void InitQueue(SqQueue&Q)
{//��ʼ�� ʹ��ͷָ��Ͷ�βָ�붼ָ��0
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
	if (Q.front == (Q.rear + 1) % MaxSize)//���������� ȡģ����ʵ���߼��ϵ�ѭ���ṹ
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}
bool DeQueue(SqQueue&Q, int&x)//���Ӳ���
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
	  ��ջ����ʽ�洢�ṹ��
----------------------------------------
*/
/*
typedef struct LinkNode {
	int data;
	struct LinkNode *next;
}*LiStack;

void InitStack(LiStack &S)//��ͷ��� ��ʼ��
{
	S = (LinkNode*)malloc(sizeof(LinkNode));
	S->next = NULL;
}

bool StackEmpty(LiStack &S)//�ж��Ƿ�Ϊ��
{
	if (S->next == NULL)
		return true;
	else
		return false;
}

bool Push(LiStack&S, int x)//��ջ
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL)
		return false;
	s->data = x;
	s->next = S->next;
	S->next = s;
	return true;
}

bool Pop(LiStack&S, int &x)// ��ջ
{
	if (S->next == NULL)
		return false;
	LinkNode*q = S->next;
	x = S->data;
	S->next = q->next;
	free(q);
	return true;
}

bool GetTop(LiStack&S, int &x)//��ȡջ��Ԫ��
{
	if (S->next == NULL)
		return false;
	x = S->data;
	return true;
}
*/



/*
------------------------------------------
		   ջ Stack ��˳��ջ��
------------------------------------------
*/
/*
//ֻ������һ�˽��в����ɾ��
//Last In first Out (LIFO)����ȳ�

// ˳��ջ

#define MaxSize 10
typedef struct {              //˳��ջ ��̬����
	int data[MaxSize];
	int top;                //ջ��ָ��
}SqStack;
typedef struct {        //����ջ
	int data[MaxSize]; // ջ������ top0 + 1 = top1 ��
	int top0;
	int top1;
}ShStack;



void InitStack(SqStack &S)//��ʼ����Ҳ����S.top = 0��������ջ ��ջ ��ȡջ�� ���붼����Ӧ�仯
{
	S.top = -1;
}
bool StackEmpty(SqStack S)//�ж�ջ�Ƿ�Ϊ��
{
	if (S.top == -1)
		return true;
	else
		return false;
}

bool Push(SqStack &S, int x)//��ջ
{
	if (S.top == MaxSize - 1)
		return false;
	S.data[++S.top] = x;
	return true;
}

bool Pop(SqStack &S, int &x)//��ջ
{
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}

bool GetTop(SqStack S, int &x)//��ȡջ��
{
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}
*/



/*
---------------------------------------
			   ��̬����
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
			  ѭ������
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
	L->next = L;//˫������priorָ��β��� nextָ��ͷ���
	return true;
}
*/


/*
-----------------------------------------------
  ˫����Ķ��塢��ʼ�������롢ɾ�������ٺͱ���
-----------------------------------------------
*/

/*
typedef struct DNode {
	int data;
	struct DNode *prior, *next;
} DNode,*DLinkList;

bool InitDLinkList(DLinkList &L)//˫����ĳ�ʼ��  DLinkList &L ��������
{
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)//�ڴ����ʧ��
		return false;
	L->prior = NULL;
	L->next = NULL;
	return true;
}

bool InsertNextDNote(DNode*p, DNode*s) //��p �������s���
{
	if (p == NULL || s == NULL)//�Ƿ�����
		return false;
	s->next = p->next;
	if (p->next != NULL)//���p����ΪNULL�����
		p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

bool InseertPriorDNote(DNode*p, DNode*s)//ǰ�����
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

bool DLinkListInsert(DLinkList&L, int i, int e) //��λ�����
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
bool DNotedelete(DNode*p)//ָ������ɾ��
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
void DestoryList(DLinkList&L)//����˫����
{
	while (L->next != NULL)
		DeleteNextDNote(L);
	free(L);
}

void ListTraversal(DLinkList L)//˫����İ�ֵ���ң� ��λ���� ��ֻ��ͨ������ʵ�� ʱ�临�Ӷ�ΪO(n).
{
	DNode*p = L;
	int i = 0;
	while (p != NULL)//������
	{
		//......�����ݲ���
		p = p->next;
		i++;
	}
}
*/



/*
---------------------------
	��������ã���ͷ��㣩
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
bool InitList(LinkList*L)//����ĳ�ʼ��
{
	(*L) = (LNode*)malloc(sizeof(LNode));
	if (*L == NULL)//�ڴ����ʧ��
		return false;
	(*L)->next = NULL;
	return true;
}

LinkList List_tailInsert(LinkList*L)//ָ������� ʵ��β�巨 ʱ�临�Ӷ�ΪO(n)
{
	InitList(L);//��ʼ��
	LNode*s, *r = (*L);
	int x;
	scanf("%d", &x);
	while (x != 999)
	{
		s = (LNode*)malloc(sizeof(LNode));//��д�� s->next = (LNode*)malloc(sizeof(LNode));����ʡ��rָ�룿
		s->data = x;
		r->next = s;
		r = s; //ʹrָ��β���
		scanf("%d", &x);
	}
	r->next = NULL;
	return *L;
}
void Output(LinkList*L)//��ͷ���
{
	LNode*p = (*L)->next;
	int j = 1;
	while (p != NULL)
	{
		printf("��%dλ��%d\n", j, p->data);
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
	printf("���õĽṹ��\n");
	Output(&L);//������Բ���ָ������
	return 0;
}
*/


/*
----------------------
  ͷ�巨������ͷ��㣩
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
void output(LinkList*L)//����ͷ���
{
	printf("�������������£�\n");
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
   ͷ�巨����ͷ��㣩
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
	 (*L) = (LNode*)malloc(sizeof(LNode));//��ʼ��
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

 void Output(LinkList*L)//��ͷ���
 {
	 LNode*p = (*L)->next;
	 int j = 1;
	 while (p != NULL)
	 {
		 printf("��%dλ��%d\n", j, p->data);
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
	 β�巨������ͷ��㣩
 ----------------------------
 */
 /*
 typedef struct LNode {
	 int data;
	 struct LNode *next;
 } LNode, *LinkList;

 LinkList TailInsert_List(LinkList*L)
 {
	 (*L) = NULL;//��ʼ��
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

 void output(LinkList*L)//����ͷ���
 {
	 printf("�������������£�\n");
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
 ������Ľ���(β�巨)��ͷ���
 -------------------------------
 */
 /*
 typedef struct LNode {
	 int data;
	 struct LNode*next;
 } LNode, *LinkList;

 bool InitList(LinkList*L)//����ĳ�ʼ��
 {
	 (*L) = (LNode*)malloc(sizeof(LNode));
	 if (*L == NULL)//�ڴ����ʧ��
		 return false;
	 (*L)->next = NULL;
	 return true;
 }

 bool ListInsert(LinkList*L, int i, int e)//����Ĳ���
 {
	 if (i < 1)
		 return false;//����λ�ò��Ϸ�
	 LNode*p = (*L);
	 int j = 0;
	 while (p != NULL && j < i - 1)//�ҵ���i-1�����
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

 void Output(LinkList*L)//��ͷ���
 {
	 LNode*p = (*L)->next;
	 int j = 1;
	 while (p != NULL)
	 {
		 printf("��%dλ��%d\n", j, p->data);
		 p = p->next;
		 j++;
	 }
	 return;
 }

 LinkList List_tailInsert(LinkList*L)//ָ������� ʵ��β�巨 ʱ�临�Ӷ�ΪO(n)
 {
	 InitList(L);//��ʼ��
	 LNode*s, *r = (*L);
	 int x;
	 scanf("%d", &x);
	 while (x != 999)
	 {
		 s = (LNode*)malloc(sizeof(LNode));
		 s->data = x;
		 r->next = s;
		 r = s; //ʹrָ��β���
		 scanf("%d", &x);
	 }
	 r->next = NULL;
	 return *L;
 }

 int main(void)
 {
	 LinkList L;
	 //List_tailInsert(&L);   �÷�������
	 InitList(&L);
	 int e;
	 int length = 0;
	 int k;
	 printf("���������һ�����ݣ�");//��Ϊѭ���Ľ�����־
	 scanf("%d", &k);
	 do
	 {
		 printf("���������ݣ�");
		 scanf("%d", &e);
		 ListInsert(&L, length + 1, e);

		 length++;
	 } while (e != k);////��������Ĳ��룬ʵ��β�� ����ʱ�临�Ӷȸ�O(n2)
	 printf("�����������£�\n");
	 Output(&L);
	 //64-73�п��Է�װ��һ�����ߺ���
	 return 0;
 }
 */



 /*
 --------------
   �����
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
		��ֵ����
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
	 ��λ����
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
		 ָ������ɾ��
 -----------------------------------
 */
 /*
 typedef struct Lnode {
	 int data;
	 struct Lnode *next;
 }Lnode, *Linklist;

 bool Listdelete(Lnode *p)//�÷�����ɾ�����һλ��ʱ���У�ɾ�����һλֻ�ܴ���ͷָ�� �������� �ҵ���ǰ�����
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
 ɾ����i����㣨����ͷ��㣩
 ------------------------------
 */
 /*
 typedef struct Lnode {
	 int data;
	 struct Lnode *next;
 }Lnode, *Linklist;

 bool Listdelete(Linklist *L, int i,int e)
 {
	 if (i < 1)//iֵ���Ϸ�
		 return false;
	 Lnode *p = *L;
	 Lnode *q;
	 if (1 == i)//ɾ����һ�����Ĳ���
	 {
		 (*L) = p->next;
		 e = (*L)->data;
		 return true;
	 }
	 int j = 1;//pָ��ǰ����λ��
	 while (p != NULL && j < i - 1)//�ҵ���i-1�����
	 {
		 p = p->next;
		 j++;
	 }
	 if (p == NULL)// ��p ΪNULL ʱ iֵ���Ϸ� i������ ����ĳ���
		 return false;
	 if (p->next == NULL)//��i-1����ΪNULL
		 return false;
	 q = p->next;
	 e = q->data;
	 p->next = q->next;
	 free(q);
 }
 */





 /*
 -------------------------------------
 ɾ����i����㣨��ͷ��㣩
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
	 free(q);//�ͷŵ�i���ڴ�
	 return true;
 }
 */




 /*
 ------------------------------------
 ָ������ǰ�������������
 ------------------------------------
 */
 /*
 //Ҳ���Դ���ͷָ�룬�������� �ҵ�p��ǰ����㣬��ִ��pǰ�����ĺ�����
 typedef struct Lnode {
	 int data;
	 struct Lnode *next;
 }Lnode, *Linklist;


 bool InsertPriorNode(Lnode*p, int e)//���ô���ͷָ�룬�ȰѶ������ݵ�������ִ�к�����
 {
	 if (p == NULL)
		 return false;
	 Lnode *s = (Lnode*)malloc(sizeof(Lnode));
	 if (s == NULL)//�ڴ����ʧ��
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
 ָ�����ĺ�������������
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
 ������İ�λ����루����ͷ��㣩
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
	 int j = 1;//��ǰpָ��Ľ��λ��
	 while (p != NULL && j < i - 1)//Ѱ�ҵ���i-1����� ��i ���ǰһ��
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
	 //ʡ������ĳ�ʼ���͸�ֵ�Ȳ���
	 listinsert(&L, 3, 6);

	 return 0;
 }
 */


 /*
 --------------------------------
 ������İ�λ����루��ͷ��㣩
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
	 int j = 0;//��ǰqָ��Ľ��λ�� 0��㼴 ͷ���
	 q = (*p);
	 while (q != NULL && j < i - 1)//Ѱ�ҵ���i-1����� ��i ���ǰһ��
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
 ��ͷ�������Ķ��弰��ʼ��
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
 ����ͷ�ڵ�����Ķ��弰��ʼ��
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
 ˳���Ĳ���(��ֵ)
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

 int locateelem(selist*q, int i)//Ѱ�ҵ�һ��Ԫ��ֵΪi��λ��
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
	 ˳���Ĳ���(��λ)
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
 ˳��������ݵ�ɾ��
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
		 printf("ɾ���ɹ�����ֵΪ%d\n", e);
	 else
		 printf("λ��i���Ϸ�\n");
	 for (int k = 0; k < L.length; ++k)
		 printf("L.data[%d] = %d\n", k, L.data[k]);

	 return 0;
 }
 */





 /*
 ---------------------
 ˳Ѱ��Ĳ����ɾ��
 ---------------------
 */
 /*
 #define MaxSize 10

 struct Seqlist {
	 int data[MaxSize];
	 int length;
 };

 void InitList(struct Seqlist * p)//˳����ʼ��
 {
	 for (int i = 0; i < MaxSize; ++i)
		 p->data[i] = 0;
	 p->length = 0;
 }

 void input(struct Seqlist *p)//˳���ֵ,û�д������壬ֻ��Ϊ�˸�˳����ϲ�ͬ��ֵ�����ں�������
 {
	 for (int i = 0; i < 5; ++i)
	 {
		 p->data[i] = i + 1;
		 p->length++;
	 }
 }

 bool ListInsert(struct Seqlist*p, int j, int k) //ʵ��˳��Ĳ���
 {
	 if (j<1 || j > p->length + 1)//����λ�ò��Ϸ�
		 return false;
	 if (p->length == MaxSize)//������󳤶�
		 return false;
	 for (int i = p->length + 1; i >= j - 1; i--)
		 p->data[i + 1] = p->data[i];
	 p->data[j - 1] = k;
	 p->length++;
	 return true;
 }

 void output(struct Seqlist*p)//���
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
	 i ? printf("����ɹ���\n") : printf("����ʧ�ܣ�\n");//����Ƿ����ɹ�
	 output(&L);

	 return 0;
 }
 */



 /*
 -----------------------
 ˳���Ķ�̬��������չ
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
   ˳���ľ�̬����
   --------------------------
   */
   /*
   #define MAXSIZE 10
   typedef struct {
	   int data[MAXSIZE]; // ��̬����������
	   int length;//˳���ǰ����
   }sqlist;//˳�������Ͷ���

   void InitList(sqlist * L)//˳����ʼ��
   {
	   for (int i = 0; i < MAXSIZE; ++i)
		   (*L).data[i] = 0;//ָ�����->   �ڼ�����ڲ� ��ת��Ϊ ��*ָ�������.   p[i] �ȼ��� *��p+i��
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